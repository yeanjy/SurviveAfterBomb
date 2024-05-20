#include "survivor.hpp"
#include <iomanip>
#include <random>
#include <iostream>
#include <string>

survivor::survivor(std::string name, int age, char gender, double height,
                   double weight, int hunger, int thirst)
: name(name), age(age), gender(gender), height(height), weight(weight),
  hunger(hunger), thirst(thirst), isAlive(true), isHealthy(false),
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

void survivor::updateData()
{
  if (!isHealthy)
    daySinceSick++;
  else 
    daySinceSick = 0;

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

void survivor::setIsSick() {
  if(isHealthy)
    isHealthy = false;
}

void survivor::setIsDead() {
  if(isAlive)
    isAlive = false;
}

bool survivor::getIsAlive() {return isAlive;}

bool survivor::getIsHealthy() {return isHealthy;}

std::string survivor::getName() {return name;}
