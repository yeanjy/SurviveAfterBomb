#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <random>
#include <set>
#include <vector>
#include <chrono>
#include <thread>
#include "app.hpp"
#include "events.hpp"
#include "survivor.hpp"
#include "variables.hpp"

app::app(){};

void app::consumeEvents()
{
  std::uniform_int_distribution<int> dis(0, events.size()-1) ;
  std::uniform_int_distribution<int> d(0, family.size()-1) ;

  std::set<int> event;
  std::set<int> member;

  while (event.size() < 3)
  {
    int e = dis(gen);
    event.insert(e);
  }
  while(member.size() < 3)
  {
    int m = d(gen);
    member.insert(m);
  }
  std::vector<int> event_indices(event.begin(), event.end());
  std::vector<int> member_indices(member.begin(), member.end());

  for (int i = 0; i < 3; ++i)
    if (!family[member_indices[i]].getIsExploring() && family[member_indices[i]].getIsAlive())
      events[event_indices[i]](family[member_indices[i]], inventory, 99);

  std::cout << "\n";
}

void app::checkExplore()
{
  if (exploring) 
  {
    for (auto &menber : family)
    { 
      if (menber.getIsExploring())
      {
        menber.addExploringDays();  
        if (menber.getExlporingDay() >= 3)
        {
          exploring = false; 
          menber.setIsExlporing(false);
          menber.setExploringDays(0);
          menber.setThirst(3);
          menber.setHunger(3);
          std::cout << menber.getName() << " voltou da exploração. Ganhos:\n\t";
          getFood(menber, inventory, 99);
          std::cout << "\t";
          getWater(menber, inventory, 99);
          std::cout << "\n";
        }
      }
    }
    return;
  }
  
  std::shared_ptr<item> foodPtr = findFood(inventory);
  std::shared_ptr<item> waterPtr = findWater(inventory);

  if (foodPtr && waterPtr)
  {
    auto it = inventory.find(foodPtr);
    auto itt = inventory.find(waterPtr);

    if (it != inventory.end() && itt != inventory.end())
    {
      if (it->second <= 3 || itt->second <= 3)
      {
        if (checkFamilyHealth())
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
          family[e].goToExplore(); 
        }
        else
          exploring = false; 
      }
    }
  }
}

void app::printFamilyData()
{
  for (survivor &member : family)
    member.printData();
  std::cout << "\n";
}

void app::updateFamilyData()
{
  for (auto &member : family)
    member.updateData();
}

void app::checkMenberIsAlive()
{
  for (auto &member : family)
    member.checkIsAlive();
}

bool app::checkFamilyHealth()
{
  return (!dad.getIsAlive() || !dad.getIsHealthy()) &&
         (!mon.getIsAlive() || !mon.getIsHealthy()) &&
         (!son.getIsAlive() || !son.getIsHealthy()) &&
         (!daughter.getIsAlive() || !daughter.getIsHealthy());
}

void app::checkEndOfGame()
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

void app::printInventory()
{
  std::cout << "Inventário: ";
  for (auto item : inventory)
  {
    item.first->printItem();
    std::cout  << "x" << item.second << " "; 
  }
  std::cout << "\n";
  std::cout << "\n";
}

void app::run()
{
  std::cout << openText;
  initInventory(inventory);
  while (isRun)
  {
    checkMenberIsAlive();
    printDay();  
    consumeEvents();
    checkExplore();
    printInventory();
    printFamilyData(); 
    updateFamilyData();

    // std::this_thread::sleep_for(std::chrono::seconds(1));
    checkEndOfGame();
  }
}
