#include "events.hpp"
#include "food.hpp"
#include "item.hpp"
#include "medkit.hpp"
#include "repiratoryMask.hpp"
#include "variables.hpp"
#include "water.hpp"
#include <iostream>
#include <memory>
#include <random>
#include <unordered_map>

bool verifyEvent(double porcentage)
{
  std::uniform_real_distribution<double> dis(0, 99);
  double aux = dis(gen);
  return porcentage>=aux? true:false;
}

void getFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, double porcentage)
{
  bool occurred = verifyEvent(porcentage);

  if(!occurred)
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
      std::cout << "Foi achado " << tmp << "comida\n";
    }
  }
}

void getWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, double porcentage)
{
  bool occurred = verifyEvent(porcentage);

  if(!occurred)
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
      std::cout << "Foi achado " << tmp << "água\n";
    }
  }
}

void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>,int> &inventory, double porcentage)
{
  bool occurred = verifyEvent(porcentage);

  if (!occurred || !s.getIsAlive())
    return;

  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if (medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
        int quantity = it->second;

        if (quantity > 0)
        {
            it->second--;
            std::cout << s.getName() << " pegou uma doença, ainda bem que tinha um medkit e está curada\n";
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
