#include <iomanip>
#include <memory>
#include <random>
#include <iostream>
#include <string>
#include <unordered_map>
#include "survivor.hpp"
#include "item.hpp"
#include "variables.hpp"
#include "events.hpp"

survivor::survivor(std::string name, int age, char gender, double height,
                   double weight, int hunger, int thirst)
: name(name), age(age), gender(gender), height(height), weight(weight),
  hunger(hunger), thirst(thirst), isAlive(true), isHealthy(true),
  daySinceSick(0) {}

void survivor::printData()
{
  if (isAlive)
  {
    std::cout << this->name << " : " << "fome:" << std::setprecision(2)<< this->hunger 
     << " sede:" << this->thirst;
    if (!isHealthy)
    {
      std::cout << " 💀x" << daySinceSick;
    }
    std::cout << "\n";
  }
  else
   std::cout << this->name << ": Morto\n";
}

void survivor::checkIsAlive()
{
   if (hunger <= 0 || thirst <= 0 || daySinceSick >= 7)
    isAlive = false;
}

void survivor::updateData(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  if (!isHealthy)
    daySinceSick++;

  if (hunger < 2)
  { 
    std::shared_ptr<item> foodptr = findFood(inventory);
    if(foodptr)
    { 
      auto it = inventory.find(foodptr);
      if(it != inventory.end())
      {
        if(it->second > 0) 
        {
          eat();
          it->second--;
        }
      }
    }
  }

  if(thirst < 2)
  {
    std::shared_ptr<item> waterPtr = findWater(inventory);
        if(waterPtr)
        { 
          auto it = inventory.find(waterPtr);
          if(it != inventory.end())
          {
            if(it->second > 0) 
            {
              drink();
              it->second--;
            }
          }
        }
  }

  if (isAlive)
  {
  double metabolicLoss = updateHunger();
  hunger -= metabolicLoss;
  double thirstLoss = updateThirst();
  thirst -= thirstLoss;
  }
}

void survivor::eat()
{
  if (isAlive)
   hunger += 1.3;
}

void survivor::drink()
{
  if(isAlive)
    thirst += 1.3;
}

double survivor::updateHunger() {
  double metabolicRate;

  if (gender == 'm') {
     metabolicRate = 66.5 + 13.7 * weight + 5 * height - 6.8 * age;
  } else {
     metabolicRate = 655 + 9.6 * weight + 1.8 * height - 4.7 * age;
  }
 
  metabolicRate -= metabolicRate*0.99;
  double result = metabolicRate;
  result -= result*0.97;

  return result;
}

double survivor::updateThirst()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  double thirstLoss;
  if (gender == 'm')
  { 
    std::uniform_real_distribution<> dis(0.6, 0.8);
    thirstLoss = dis(gen);
  }
  else
  { 
    std::uniform_real_distribution<> dis(0.5, 0.7);
    thirstLoss = dis(gen);
  }
  return thirstLoss;
}

void survivor::setIsSick() {
  if(isHealthy)
    isHealthy = false;
}

void survivor::setIsDead() {
  if(isAlive)
    isAlive = false;
}

void survivor::antiWarn() {}

void survivor::setDaySinceSick(int n) {daySinceSick = n;}

bool survivor::getIsAlive() {return isAlive;}

bool survivor::getIsHealthy() {return isHealthy;}

std::string survivor::getName() {return name;}
