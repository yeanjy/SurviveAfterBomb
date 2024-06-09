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
  daySinceSick(0), isExploring(false), exploringDays(0) {}

void survivor::printData()
{
  if (isAlive)
  {
    if (isExploring && exploringDays <= 2)
    {
      std::cout << name << " : explorando. Volta em " << 3-exploringDays << " dia\n";
      return;
    }

    std::cout << name << " : " << "fome:" << std::setprecision(2)<< hunger 
     << " sede:" << thirst;
    if (!isHealthy)
    {
      std::cout << " 💀x" << daySinceSick;
    }
    std::cout << "\n";
  }
  else
   std::cout << name << ": Morto\n";
}

void survivor::goToExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, bool &exploring, bool &tookTheMask)
{
  isExploring = true;

  std::shared_ptr<item> maskPtr = findMask(inventory);
  if (maskPtr)
  {
    auto it = inventory.find(maskPtr);
    if (it != inventory.end())
    {
      if (!tookTheMask)
      {
        if (verifyEvent(75))
        {
          setIsDead();
          isExploring = false;
          exploring = false;
          std::cout << name << " morreu por causa da radiação\n";
        }
      }
      else  
      {
        if (verifyEvent(5))
        { 
          setIsDead();
          exploring = false;
          isExploring = false;
          std::cout << name << " morreu por causa da radiação\n";
        }
      }
    }
  }
}

void survivor::checkIsAlive()
{
   if (hunger <= 0 || thirst <= 0 || daySinceSick >= 7)
    isAlive = false;
}

void survivor::updateData(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  if (isAlive)
  {
    if (isExploring)
      return;

    std::shared_ptr<item> medkitPtr = findMedkit(inventory);
    auto itMedkit = inventory.find(medkitPtr);
    if (!isHealthy && itMedkit != inventory.end() && itMedkit->second > 0)
    {
      daySinceSick = 0;
      isHealthy = true;
      itMedkit->second--;
      std::cout << name << " se curou com um medkit\n";
    }
    else if (!isHealthy)
    {
      daySinceSick++;
    }

    if (hunger < 2)
    {
      std::shared_ptr<item> foodPtr = findFood(inventory);
      if (foodPtr)
      {
        auto itFood = inventory.find(foodPtr);
        if (itFood != inventory.end() && itFood->second > 0)
        {
          eat();
          itFood->second--;
        }
      }
    }

    if (thirst < 2)
    {
      std::shared_ptr<item> waterPtr = findWater(inventory);
      if (waterPtr)
      {
        auto itWater = inventory.find(waterPtr);
        if (itWater != inventory.end() && itWater->second > 0)
        {
          drink();
          itWater->second--;
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

void survivor::setDaySinceSick(int n) {daySinceSick = n;}

void survivor::addExploringDays() {exploringDays+=1;}

void survivor::setIsExploring(bool n) {isExploring = n;}

void survivor::setExploringDays(int n) {exploringDays = n;}

void survivor::setHunger(int n) {hunger = n;}

void survivor::setThirst(int n) {thirst = n;}

int survivor::getExploringDay() {return exploringDays;}

bool survivor::getIsAlive() {return isAlive;}

bool survivor::getIsHealthy() {return isHealthy;}

bool survivor::getIsExploring() {return isExploring;}

std::string survivor::getName() {return name;}
