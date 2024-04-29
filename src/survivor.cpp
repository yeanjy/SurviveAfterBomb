#include "survivor.hpp"
#include <iomanip>
#include <random>
#include <iostream>

survivor::survivor(std::string name, int age, char gender, double height,
                   double weight, int hunger, int thirst, bool isAlive, bool isHealthy)
: name(name), age(age), gender(gender), height(height), weight(weight),
  hunger(hunger), thirst(thirst), isAlive(isAlive), isHealthy(isHealthy),
  daySinceSick(0) {}

void survivor::printData()
{
  if (isAlive)
  {
    std::cout << this->name << " : " << "fome:" << std::setprecision(2)<< this->hunger 
     << " sede:" << this->thirst;
    if (!isHealthy)
    {
      std::cout << " 💀";
    }
    std::cout << "\n";
  }
  else
   std::cout << this->name << ": Morto\n";
}

void survivor::checkIsAlive()
{
  if (!isHealthy)
    daySinceSick++;

  if (hunger <= 0 || thirst <= 0 || daySinceSick >= 7)
    isAlive = false;
}

void survivor::updateData()
{
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
   hunger++;
  else
   std::cout << "Personagem morto";
}

void survivor::drink()
{
  if(isAlive)
    thirst++;
  else
   std::cout << "Personagem morto";
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
  result -= result*0.98;

  return result;
}

double survivor::updateThirst()
{
  std::random_device rd;
  std::mt19937 gen(rd());
  double thirstLoss;
  if (gender == 'm')
  { 
    std::uniform_real_distribution<> dis(0.8, 1);
    thirstLoss = dis(gen);
  }
  else
  { 
    std::uniform_real_distribution<> dis(0.7, 0.9);
    thirstLoss = dis(gen);
  }
  return thirstLoss;
}

void survivor::setIsSick() {isHealthy = !isHealthy;}

void survivor::setIsDead() {isAlive = !isAlive;}

bool survivor::getIsAlive() {return isAlive;}

bool survivor::getIsHealthy() {return isHealthy;}
