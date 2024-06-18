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

//construtor
survivor::survivor(std::string name, int age, char gender, double height,
                   double weight, int hunger, int thirst)
: name(name), age(age), gender(gender), height(height), weight(weight),
  hunger(hunger), thirst(thirst), isAlive(true), isHealthy(true),
  daySinceSick(0), isExploring(false), exploringDays(0) {}

//imprimir dados do sobrevivente
void survivor::printData()
{
  //verificar se o sobrevivente esta vivo
  if (isAlive)
  {
    //verificar se o sobrevivente esta explorando
    if (isExploring && exploringDays <= 2)
    {
      std::cout << name << " : explorando. Volta em " << 3-exploringDays << " dia\n";
      return;
    }

    std::cout << name << " : " << "fome:" << std::setprecision(2)<< hunger 
     << " sede:" << thirst;
    //caso o sobrevivente esteja doente
    if (!isHealthy)
    {
      std::cout << " 💀x" << daySinceSick;
    }
    std::cout << "\n";
  }
  //caso o sobrevivente esteja morto
  else
   std::cout << name << ": Morto\n";
}

//ir explorar
void survivor::goToExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, bool &exploring, bool &tookTheMask)
{
  isExploring = true;

  //achar o ponteiro do item mascara
  std::shared_ptr<item> maskPtr = findMask(inventory);
  //se o item existir
  if (maskPtr)
  {
    auto it = inventory.find(maskPtr);
    if (it != inventory.end())
    {
      //se nao tiver mascara
      if (!tookTheMask)
      {
        //verificar se o sobrevivente vai morrer
        //75% se nao tiver mascara
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
        //5% de chance de morrer caso tenha mascara
        if (verifyEvent(5))
        { 
          setIsDead();
          it->second = 0;
          tookTheMask = false;
          exploring = false;
          isExploring = false;
          std::cout << name << " morreu por causa da radiação\n";
        }
      }
    }
  }
}

//verificar se o sobrevivente esta vivo
void survivor::checkIsAlive()
{
   if (hunger <= 0 || thirst <= 0 || daySinceSick >= 7)
    isAlive = false;
}

//atualizar dados do sobrevivente
void survivor::updateData(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  //verificar se o sobrevivente esta vivo
  if (isAlive)
  {
    //verificar se o sobrevivente esta explorando
    if (isExploring)
      return;

    //achar ponteiro do item medkit
    std::shared_ptr<item> medkitPtr = findMedkit(inventory);
    auto itMedkit = inventory.find(medkitPtr);
    //verificar se o inventorio tiver mais de um medkit 
    //e se o sobrevivente esta doente
    if (!isHealthy && itMedkit != inventory.end() && itMedkit->second > 0)
    {
      daySinceSick = 0;
      isHealthy = true;
      itMedkit->second--;
      std::cout << name << " se curou com um medkit\n";
    }
    //verificar se o sobrevivente esta doente
    else if (!isHealthy)
      daySinceSick++;

    //atualizar fome e sede
    double metabolicLoss = updateHunger();
    hunger -= metabolicLoss;
    double thirstLoss = updateThirst();
    thirst -= thirstLoss;
  }
}

//funcao comer
void survivor::eat(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  //verificar se necessario comer
  if (isAlive && !isExploring && hunger <= 2)
  { 
    //achar ponteiro do item comida
    std::shared_ptr<item> foodPtr = findFood(inventory);
    if (foodPtr)
    {
      auto itFood = inventory.find(foodPtr);
      //verificar se o inventorio tem comida
      if (itFood != inventory.end() && itFood->second > 0)
      {
        itFood->second--;
        hunger += 2;
      }
    }
  }
}

//funcao beber
void survivor::drink(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  //verificar se necessario beber
  if(isAlive && !isExploring && thirst <= 2)
  {
    //achar ponteiro do item agua
    std::shared_ptr<item> waterPtr = findWater(inventory);
    if (waterPtr)
    {
      auto itWater = inventory.find(waterPtr);
      //verificar se o inventorio tem agua
      if (itWater != inventory.end() && itWater->second > 0)
      {
        itWater->second--;
        thirst += 2;
      }
    }
  }
}

//funcao atualizar fome
double survivor::updateHunger() {
  double metabolicRate;

  //cacular taxa metabolica de acordo
  //com o genero do sobrevivente
  if (gender == 'm') 
    metabolicRate = 66.5 + 13.7 * weight + 5 * height - 6.8 * age;
  else 
    metabolicRate = 655 + 9.6 * weight + 1.8 * height - 4.7 * age;
  
 
  metabolicRate -= metabolicRate*0.99;
  double result = metabolicRate;
  result -= result*0.97;

  return result;
}

//funcao atualizar sede
double survivor::updateThirst()
{
  double thirstLoss;
  //calcular perda de sede de acordo com o genero
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

//funcao trocar o estado de saude
void survivor::setIsSick() {
  if(isHealthy)
    isHealthy = false;
}

//funcao definir o sobrevivente como morto
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

double survivor::getHunger() const {return hunger;}

double survivor::getThirst() const {return thirst;}

std::string survivor::getName() {return name;}
