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

//app constructor
app::app()
:isRun(true), getSickPorcentage(5), getLostFoodPorcentage(15), getLostWaterPorcentage(15), 
getLostMedkitPorcentage(10), armyHelpPorcentage(0), dayCounter(1), freakOutPorcentage(1)
{};

//randomizar eventos e consumir
void app::consumeEvents(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, std::vector<FunctionPointer> &events)
{
  std::uniform_int_distribution<int> dis(0, events.size()-1) ;
  std::uniform_int_distribution<int> d(0, family.size()-1) ;

  std::set<int> event;
  std::vector<int> member;

  //adicionar eventos e membros no set para nao repetir
  while (event.size() < 3)
  { 
    int temp = dis(gen);
    event.insert(temp);
  }

  //adicionar membros no vetor
  for(int i = 0; i < 3; i++)
  {
    int temp = d(gen);
    member.push_back(temp);
  }

  //converter set para vector
  std::vector<int> event_indices(event.begin(), event.end());

  for (int i = 0; i < 3; i++)
    //verificar se o membro nao esta explorando e vivo
    if (!family[member[i]].getIsExploring() && family[member[i]].getIsAlive())
      events[event_indices[i]](family[member[i]], inventory, *this);

  std::cout << "\n";
}

//verificar se necessario explorar
void app::checkExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, bool &exploring, bool &tookTheMask)
{
  //procurar ponteiro do item mascara
  std::shared_ptr<item> maskPtr = findMask(inventory);
  auto maskIt = inventory.find(maskPtr);

  //se alguem ja estiver explorando
  if (exploring)
  {
    for (auto &menber : family)
    {
      //se o membro estiver explorando
      if (menber.getIsExploring())
      {
        //adicionar dias de exploracao
        menber.addExploringDays();
        //se o membro ja tiver explorado 3 dias
        if (menber.getExploringDay() >= 3)
        {
          if (tookTheMask && maskPtr && maskIt != inventory.end())
          {
            tookTheMask = false;
            maskIt->second++;
          }
          //atualizar dados do membro apos a exploracao
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

  //procurar ponteiro do item comida e agua
  std::shared_ptr<item> foodPtr = findFood(inventory);
  std::shared_ptr<item> waterPtr = findWater(inventory);

  if (foodPtr && waterPtr)
  {
    auto foodIt = inventory.find(foodPtr);
    auto waterIt = inventory.find(waterPtr);

    if (foodIt != inventory.end() && waterIt != inventory.end())
    {
      //se a comida ou agua for menor que 3
      if (foodIt->second <= 3 || waterIt->second <= 3)
      {
        //verificar se todos os membros estao mortos ou doentes
        if (checkFamilyHealth(family))
          return;

        exploring = true;

        std::uniform_int_distribution<int> dis(0, family.size() - 1);
        int e = dis(gen);

        //procurar membro vivo e saudavel para explorar
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

        //se encontrar membro
        if (foundExplorer)
        {
          std::cout << family[e].getName() << " foi explorar, devido a falta de comida/água\n";
          std::cout << "\n";
          //verificar se o inventorio possuir mascara
          if (maskPtr && maskIt != inventory.end() && maskIt->second > 0)
          {
            tookTheMask = true;
            maskIt->second--;
          }
          family[e].goToExplore(inventory, exploring, tookTheMask);
        }
        else
          exploring = false;
      }
    }
  }
}

//imprimir dados da familia
void app::printFamilyData(std::vector<survivor> &family)
{
  for (survivor &member : family)
    member.printData();
  std::cout << "\n";
}

//atualizar dados da familia
void app::updateFamilyData(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::vector<survivor*> thirstVector;
  std::vector<survivor*> hungerVector; 

  for (auto& member : family)
  {
    thirstVector.push_back(&member);
    hungerVector.push_back(&member);
  }

  //alimentar os menbros de acordo com a fome e sede
  std::sort(thirstVector.begin(), thirstVector.end(), [](const survivor* s1, const survivor* s2) {
    return s1->getThirst() < s2->getThirst();
  });

  std::sort(hungerVector.begin(), hungerVector.end(), [](const survivor* s1, const survivor* s2) {
    return s1->getHunger() < s2->getHunger();
  });

  //atualizar os dados dos membros
  for (auto &member : family)
    member.updateData(inventory);

  for (auto *menber : thirstVector)
    menber->drink(inventory);

  for (auto *menber : hungerVector)
    menber->eat(inventory);
}

//verificar se membro esta vivo
void app::checkMemberIsAlive(std::vector<survivor> &family)
{
  for (auto &member : family)
    member.checkIsAlive();
}

//verificar saude da familia
bool app::checkFamilyHealth(std::vector<survivor> &family)
{
    size_t n = 0;
    for (auto &member : family) 
      if (!member.getIsAlive() || !member.getIsHealthy()) 
        n++; 
    //retornar true se todos os membros estiverem mortos ou doentes
    return n == family.size(); 
}

//verificar fim do jogo
void app::checkEndOfGame(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  size_t survivorCounter = 0;
  for (auto &member : family)
  {
    if (!member.getIsAlive())
      survivorCounter++;
  }

  //se a quantidade de membros mortos for igual a quantidade de membros
  if (survivorCounter == family.size()) 
  {
    std::cout << endText; 
    inventory.clear();
    isRun = false;
  }
}

//imprimir dia
void app::printDay()
{
  std::cout << "----------------------------------\n";
  std::cout << "Dia : " << dayCounter << "\n";
  std::cout << "\n";
  dayCounter++;
}

//converter inventario para string
std::string app::toStringInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::string result = "Inventário: " ;
  for (auto &item : inventory)
  {
    result += item.first->toString() + "x" + std::to_string(item.second) + " ";
  }
  return result;
}

//imprimir inventario
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

//atualizar porcentagem de eventos
void app::updatePorcentage()
{
  getSickPorcentage += 0.5;
  getLostMedkitPorcentage += 0.3;
  getLostFoodPorcentage += 0.4;
  getLostWaterPorcentage += 0.4;
  armyHelpPorcentage += 0.3;
  freakOutPorcentage += 0.2;
}

//inicializar inventario
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

//executar app
void app::run(std::vector<survivor> &family)
{
  bool exploring = false;
  bool tookTheMask = false;
  std::vector<FunctionPointer> events = {getSick, getFood, getWater, lostFood, lostWater, getMedkit, lostMedkit, armyHelp, freakOut};
  std::unordered_map<std::shared_ptr<item>, int> inventory;
  std::cout << openText;
  initInventory(inventory);

  //loop principal 
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
