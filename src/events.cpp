#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <unordered_map>
#include "events.hpp"
#include "food.hpp"
#include "item.hpp"
#include "medkit.hpp"
#include "repiratoryMask.hpp"
#include "variables.hpp"
#include "water.hpp"
#include "app.hpp"

bool verifyEvent(double porcentage)
{
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  return dis(gen) < (porcentage/100.0);
}

void getFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostFoodPorcentage))
    return;

  std::shared_ptr<item> foodPtr = findFood(inventory);

  if(foodPtr)
  {
    auto it = inventory.find(foodPtr);
    if (it != inventory.end())
    {
      std::uniform_int_distribution<> dis(1, 2); 
      int tmp = dis(gen);
      it->second += tmp;
      std::cout << s.getName() <<" achou " << tmp << " comida\n";
    }
  }
  a.ocurredEvent.push_back("Evento: getFood, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void lostFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostFoodPorcentage))
    return;

  std::shared_ptr<item> foodPtr = findFood(inventory);

  if(foodPtr)
  {
    auto it = inventory.find(foodPtr);
    if (it != inventory.end())
    {
      if (it->second <= 0)
        return;
      else if(it->second > 2)
      {
        std::uniform_int_distribution<> dis(1, 2); 
        int tmp = dis(gen);
        it->second -= tmp;
        std::cout << "Foi perdido " << tmp << " comida\n";
      }
      else
      {
        it->second--;
        std::cout << "Foi perdido " << 1 << " comida\n";
      }
    }
  }
  a.ocurredEvent.push_back("Evento: lostFood, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void getWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostWaterPorcentage))
    return;

  std::shared_ptr<item> waterPtr = findWater(inventory);

  if(waterPtr)
  {
    auto it = inventory.find(waterPtr);
    if (it != inventory.end())
    {
      std::uniform_int_distribution<> dis(1, 2); 
      int tmp = dis(gen);
      it->second += tmp;
      std::cout << s.getName() << " achou " << tmp << " água\n";
    }
  }
  a.ocurredEvent.push_back("Evento: getWater, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void lostWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostWaterPorcentage))
    return;

  std::shared_ptr<item> waterPtr = findWater(inventory);

  if(waterPtr)
  {
    auto it = inventory.find(waterPtr);
    if (it != inventory.end())
    {
      if (it->second <= 0)
        return;
      else if(it->second > 2)
      {
        std::uniform_int_distribution<> dis(1, 2); 
        int tmp = dis(gen);
        it->second -= tmp;
        std::cout << "Foi perdido " << tmp << " água\n";
      }
      else
      {
        it->second--;
        std::cout << "Foi perdido " << 1 << " água\n";
      }
    }
  }
  a.ocurredEvent.push_back("Evento: lostWater, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void getMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostMedkitPorcentage))
    return;

  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if(medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      it->second++;
      std::cout << "Foi perdido 1 medkit\n";
    }
  }
  a.ocurredEvent.push_back("Evento: getMedkit, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void lostMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if(!verifyEvent(a.getLostMedkitPorcentage))
    return;

  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if(medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      if (it->second > 0)
      {
        std::cout << "Foi perdido 1 medkit\n";
        it->second--;
      }
    }
  }
  a.ocurredEvent.push_back("Evento: lostMedkit, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if (!verifyEvent(a.getSickPorcentage) || !s.getIsAlive())
    return;

  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if (medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      if (it->second > 0)
      {
        it->second--;
        std::cout << s.getName() << " pegou uma doença, ainda bem que tinha um medkit e está curada\n";
        s.setDaySinceSick(0); 
      }
      else 
      {
          if (!s.getIsHealthy())
          {
            s.setIsDead();
            std::cout << s.getName() << " pegou outra doença e morreu\n";
          }
          else 
          {
            s.setIsSick();
            std::cout << s.getName() << " está doente\n";
          }
      }
    }
  }
  a.ocurredEvent.push_back("Evento: getSick, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}


void freakOut(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if (!verifyEvent(a.freakOutPorcentage))
    return;

  s.setIsDead();
  std::cout << s.getName() << " enlouqueceu e fugiu da família, morreu de radiação\n";
  a.ocurredEvent.push_back("Evento: freakOut, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

void armyHelp(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  if (!verifyEvent(a.armyHelpPorcentage))
    return;
  std::cout << "A família foi achada por militares, todos foram salvos, fim do jogo.\n";
  a.isRun = false;
  a.ocurredEvent.push_back("Evento: armyHelp, Sobrevivente: " + s.getName() + ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

std::shared_ptr<item> findMedkit(std::unordered_map<std::shared_ptr<item>, int>& inventory)
{
  for (const auto& pair : inventory) {
    if (std::dynamic_pointer_cast<medkit>(pair.first)) {
      return pair.first;
    }
  }
  return nullptr;
}
std::shared_ptr<item> findWater(std::unordered_map<std::shared_ptr<item>, int>& inventory)
{
  for (const auto& pair : inventory) {
    if (std::dynamic_pointer_cast<water>(pair.first)) {
      return pair.first;
    }
  }
  return nullptr;
}
std::shared_ptr<item> findFood(std::unordered_map<std::shared_ptr<item>, int>& inventory)
{
  for (const auto& pair : inventory) {
    if (std::dynamic_pointer_cast<food>(pair.first)) {
      return pair.first;
    }
  }
  return nullptr;
}
std::shared_ptr<item> findMask(std::unordered_map<std::shared_ptr<item>, int>& inventory)
{
  for (const auto& pair : inventory) {
    if (std::dynamic_pointer_cast<respiratoryMask>(pair.first)) {
      return pair.first;
    }
  }
  return nullptr;
}

void exploreGain(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::shared_ptr<item> waterPtr = findWater(inventory);
  std::shared_ptr<item> foodPtr = findFood(inventory);
  std::shared_ptr<item> medKitPtr = findMedkit(inventory);

  if(waterPtr && foodPtr && medKitPtr)
  {
    auto waterIt = inventory.find(waterPtr);
    auto foodIt = inventory.find(foodPtr);
    auto medIt = inventory.find(medKitPtr);
    if (waterIt != inventory.end() && foodIt != inventory.end() && medIt != inventory.end())
    {
      std::uniform_int_distribution<int> waterDist(2, 5); 
      std::uniform_int_distribution<int> foodDist(2, 5); 
      std::uniform_int_distribution<int> medkitDist(0, 1); 

      int water = waterDist(gen);
      int food = foodDist(gen);
      int medkit = medkitDist(gen);

      waterIt->second += water;
      foodIt->second += food;
      medIt->second += medkit;

      std::cout << "\tComida : " << food << "\n";
      std::cout << "\tÁgua : " << water << "\n";
      std::cout << "\tMedkit : " << medkit << "\n";
      std::cout << "\n";
    }
  }
}
