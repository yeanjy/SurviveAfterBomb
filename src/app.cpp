#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include "app.hpp"
#include "events.hpp"
#include "item.hpp"
#include "food.hpp"
#include "water.hpp"
#include "medkit.hpp"
#include "repiratoryMask.hpp"
#include "survivor.hpp"
#include "variables.hpp"

app::app()
:isRun(true), getSickPorcentage(5), getLostFoodPorcentage(15), getLostWaterPorcentage(15), 
getLostMedkitPorcentage(10), armyHelpPorcentage(0), dayCounter(1), freakOutPorcentage(1)
{};

void app::consumeEvents(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, std::vector<FunctionPointer> &events)
{
  std::uniform_int_distribution<int> dis(0, events.size()-1) ;
  std::uniform_int_distribution<int> d(0, family.size()-1) ;

  std::set<int> event;
  std::set<int> member;

  while (event.size() < 3)
  { 
    int temp = dis(gen);
    event.insert(temp);
  }
  while(member.size() < 3)
  {
    int temp = d(gen);
    member.insert(temp);
  }

  std::vector<int> event_indices(event.begin(), event.end());
  std::vector<int> member_indices(member.begin(), member.end());

  for (int i = 0; i < 3; i++)
    if (!family[member_indices[i]].getIsExploring() && family[member_indices[i]].getIsAlive())
      events[event_indices[i]](family[member_indices[i]], inventory, *this);

  std::cout << "\n";
}

void app::checkExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, bool &exploring, bool &tookTheMask)
{
  std::shared_ptr<item> maskPtr = findMask(inventory);
  auto maskIt = inventory.find(maskPtr);

  if (exploring)
  {
    for (auto &menber : family)
    {
      if (menber.getIsExploring())
      {
        menber.addExploringDays();
        if (menber.getExploringDay() >= 3)
        {
          if (tookTheMask && maskPtr && maskIt != inventory.end())
          {
            tookTheMask = false;
            maskIt->second++;
          }
          exploring = false;
          menber.setIsExploring(false);
          menber.setExploringDays(0);
          menber.setThirst(3);
          menber.setHunger(3);
          std::cout << menber.getName() << " voltou da exploração. Ganhos:\n";
          exploreGain(inventory);
        }
      }
    }
    return;
  }

  std::shared_ptr<item> foodPtr = findFood(inventory);
  std::shared_ptr<item> waterPtr = findWater(inventory);

  if (foodPtr && waterPtr)
  {
    auto foodIt = inventory.find(foodPtr);
    auto waterIt = inventory.find(waterPtr);

    if (foodIt != inventory.end() && waterIt != inventory.end())
    {
      if (foodIt->second <= 3 || waterIt->second <= 3)
      {
        if (checkFamilyHealth(family))
          return;

        exploring = true;

        std::uniform_int_distribution<int> dis(0, family.size() - 1);
        int e = dis(gen);

        bool foundExplorer = false;
        for (size_t attempts = 0; attempts < family.size(); ++attempts)
        {
          e = dis(gen);
          if (family[e].getIsAlive() && family[e].getIsHealthy())
          {
            foundExplorer = true;
            break;
          }
        }

        if (foundExplorer)
        {
          std::cout << family[e].getName() << " foi explorar, devido a falta de comida/água\n";
          std::cout << "\n";
          if (maskPtr && maskIt != inventory.end() && maskIt->second > 0)
          {
            tookTheMask = true;
            maskIt->second--;
          }
          family[e].goToExplore(inventory, exploring, tookTheMask);
        }
        else
        {
          exploring = false;
        }
      }
    }
  }
}

void app::printFamilyData(std::vector<survivor> &family)
{
  for (survivor &member : family)
    member.printData();
  std::cout << "\n";
}

void app::updateFamilyData(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::vector<survivor*> thirstVector;
  std::vector<survivor*> hungerVector; 

  for (auto& member : family)
  {
    thirstVector.push_back(&member);
    hungerVector.push_back(&member);
  }

  std::sort(thirstVector.begin(), thirstVector.end(), [](const survivor* s1, const survivor* s2) {
    return s1->getThirst() < s2->getThirst();
  });

  std::sort(hungerVector.begin(), hungerVector.end(), [](const survivor* s1, const survivor* s2) {
    return s1->getHunger() < s2->getHunger();
  });

  for (auto &member : family)
    member.updateData(inventory);

  for (auto *menber : thirstVector)
    menber->drink(inventory);

  for (auto *menber : hungerVector)
    menber->eat(inventory);
}

void app::checkMemberIsAlive(std::vector<survivor> &family)
{
  for (auto &member : family)
    member.checkIsAlive();
}

bool app::checkFamilyHealth(std::vector<survivor> &family)
{
  return (!family[0].getIsAlive() || !family[0].getIsHealthy()) &&
         (!family[1].getIsAlive() || !family[1].getIsHealthy()) &&
         (!family[2].getIsAlive() || !family[2].getIsHealthy()) &&
         (!family[3].getIsAlive() || !family[3].getIsHealthy());
}

void app::checkEndOfGame(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  size_t survivorCounter = 0;
  for (auto &member : family)
  {
    if (!member.getIsAlive())
      survivorCounter++;
  }

  if (survivorCounter == family.size()) 
  {
    std::cout << endText; 
    inventory.clear();
    isRun = false;
  }
}

void app::printDay()
{
  std::cout << "----------------------------------\n";
  std::cout << "Dia : " << dayCounter << "\n";
  std::cout << "\n";
  dayCounter++;
}

std::string app::toStringInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::string result = "Inventário: " ;
  for (auto &item : inventory)
  {
    result += item.first->toString() + "x" + std::to_string(item.second) + " ";
  }
  return result;
}

void app::printInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::cout << "Inventário: ";
  for (auto &item : inventory)
  {
    item.first->printItem();
    std::cout  << "x" << item.second << " "; 
  }
  std::cout << "\n";
  std::cout << "\n";
}

void app::updatePorcentage()
{
  getSickPorcentage += 0.5;
  getLostMedkitPorcentage += 0.3;
  getLostFoodPorcentage += 0.4;
  getLostWaterPorcentage += 0.4;
  armyHelpPorcentage += 0.3;
  freakOutPorcentage += 0.2;
}

void app::initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::shared_ptr<item> w = std::make_shared<water>(); 
  std::shared_ptr<item> f = std::make_shared<food>(); 
  std::shared_ptr<item> m = std::make_shared<respiratoryMask>(); 
  std::shared_ptr<item> med = std::make_shared<medkit>(); 
  inventory.insert({f, 10});
  inventory.insert({w, 10});
  inventory.insert({m, 1});
  inventory.insert({med, 1});
}

void app::run()
{
  survivor dad("Ted", 35, 'm', 173, 90);
  survivor mon("Dolores", 31, 'f', 181, 72);
  survivor son("Timmy", 14, 'm', 142, 42);
  survivor daughter("Mary Jane", 17, 'f', 163, 62);
  bool exploring = false;
  bool tookTheMask = false;
  std::vector<survivor> family = {dad, mon, son, daughter};
  std::vector<FunctionPointer> events = {getSick, getFood, getWater, lostFood, lostWater, getMedkit, lostMedkit, armyHelp, freakOut};
  std::unordered_map<std::shared_ptr<item>, int> inventory;

  std::cout << openText;
  initInventory(inventory);

  while (isRun)
  {
    checkMemberIsAlive(family);
    printDay();
    consumeEvents(inventory, family, events);
    checkExplore(inventory, family, exploring, tookTheMask);
    printInventory(inventory);
    printFamilyData(family);
    updateFamilyData(family, inventory);
    checkEndOfGame(family, inventory);
    updatePorcentage();
  }
}
