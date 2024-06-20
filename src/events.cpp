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

//verificar se o evento ocorreu
bool verifyEvent(double porcentage)
{
  //randomizar valor entre 0 e 1
  std::uniform_real_distribution<double> dis(0.0, 1.0);
  return dis(gen) < (porcentage/100.0);
}

//evento se achou comida
void getFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostFoodPorcentage))
    return;

  //achar ponteiro de comida
  std::shared_ptr<item> foodPtr = findFood(inventory);

  if(foodPtr)
  {
    auto it = inventory.find(foodPtr);
    if (it != inventory.end())
    {
      //randomizar valor entre 1 e 2
      //e adicionar ao inventorio
      std::uniform_int_distribution<> dis(1, 2); 
      int tmp = dis(gen);
      it->second += tmp;
      std::cout << s.getName() <<" achou " << tmp << " comida\n";
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: getFood, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se perdeu comida
void lostFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostFoodPorcentage))
    return;

  //achar ponteiro de comida
  std::shared_ptr<item> foodPtr = findFood(inventory);

  if(foodPtr)
  {
    auto it = inventory.find(foodPtr);
    if (it != inventory.end())
    {
      //verificar se tem comida no inventorio
      if (it->second <= 0)
        return;
      //se tiver mais de 2, randomizar entre 1 e 2
      //e subtrair do inventorio
      else if(it->second > 2)
      {
        std::uniform_int_distribution<> dis(1, 2); 
        int tmp = dis(gen);
        it->second -= tmp;
        std::cout << "Foi perdido " << tmp << " comida\n";
      }
      //se tiver 1, subtrair 1
      else
      {
        it->second--;
        std::cout << "Foi perdido " << 1 << " comida\n";
      }
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: lostFood, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se achou água
void getWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostWaterPorcentage))
    return;

  //achar ponteiro de agua
  std::shared_ptr<item> waterPtr = findWater(inventory);

  if(waterPtr)
  {
    auto it = inventory.find(waterPtr);
    if (it != inventory.end())
    {
      //randomizar valor entre 1 e 2 e adicionar ao inventorio
      std::uniform_int_distribution<> dis(1, 2); 
      int tmp = dis(gen);
      it->second += tmp;
      std::cout << s.getName() << " achou " << tmp << " água\n";
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: getWater, Sobrevivente: " + s.getName() +
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se perdeu água
void lostWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostWaterPorcentage))
    return;

  //achar ponteiro de agua
  std::shared_ptr<item> waterPtr = findWater(inventory);

  if(waterPtr)
  {
    auto it = inventory.find(waterPtr);
    if (it != inventory.end())
    {
      //verificar se tem agua no inventorio
      if (it->second <= 0)
        return;
      //se tiver mais de 2, randomizar entre 1 e 2 e subtrair do inventorio
      else if(it->second > 2)
      {
        std::uniform_int_distribution<> dis(1, 2); 
        int tmp = dis(gen);
        it->second -= tmp;
        std::cout << "Foi perdido " << tmp << " água\n";
      }
      //se tiver 1, subtrair 1
      else
      {
        it->second--;
        std::cout << "Foi perdido " << 1 << " água\n";
      }
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: lostWater, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se achou medkit
void getMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostMedkitPorcentage))
    return;

  //achar ponteiro de medkit
  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if(medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      //adicionar 1 medkit ao inventorio
      it->second++;
      std::cout << "Foi achado 1 medkit\n";
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: getMedkit, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se perdeu medkit
void lostMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if(!verifyEvent(a.getLostMedkitPorcentage))
    return;

  //achar ponteiro de medkit
  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if(medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      //verificar se tem medkit no inventorio
      if (it->second > 0)
      {
        std::cout << "Foi perdido 1 medkit\n";
        it->second--;
      }
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: lostMedkit, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se um subrevivente ficou doente
void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if (!verifyEvent(a.getSickPorcentage) || !s.getIsAlive())
    return;

  //achar ponteiro de medkit
  std::shared_ptr<item> medkitPtr = findMedkit(inventory);

  if (medkitPtr)
  {
    auto it = inventory.find(medkitPtr);
    if (it != inventory.end())
    {
      //verificar se tem medkit no inventorio
      if (it->second > 0)
      {
        it->second--;
        std::cout << s.getName() << " pegou uma doença, ainda bem que tinha um medkit e está curada\n";
        s.setDaySinceSick(0); 
      }
      else 
      {
        //verificar se o sobrevivente ja esta doente
        if (!s.getIsHealthy())
        {
          s.setIsDead();
          std::cout << s.getName() << " pegou outra doença e morreu\n";
        }
        //se nao estiver doente, setar como doente
        else 
        {
          s.setIsSick();
          std::cout << s.getName() << " está doente\n";
        }
      }
    }
  }
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: getSick, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se um subrevivente enlouqueceu
void freakOut(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if (!verifyEvent(a.freakOutPorcentage))
    return;

  //setar sobrevivente como morto
  s.setIsDead();
  std::cout << s.getName() << " enlouqueceu e fugiu da família, morreu de radiação\n";
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: freakOut, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
}

//evento se a família foi achada por militares
void armyHelp(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a)
{
  //retornar se o evento nao ocorreu
  if (!verifyEvent(a.armyHelpPorcentage))
    return;

  //setar o jogo como finalizado
  std::cout << "A família foi achada por militares, todos foram salvos, fim do jogo.\n";
  a.isRun = false;
  //adicionar evento ao vetor de eventos ocorridos
  a.ocurredEvent.push_back("Evento: armyHelp, Sobrevivente: " + s.getName() + 
                           ", Dia: " + std::to_string(a.dayCounter) + ", " + a.toStringInventory(inventory));
  //limpar inventorio
  inventory.clear();
}

//funcoes para achar ponteiro de item
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

//funcao de ganhos de itens apos exploracao
void exploreGain(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  //achar ponteiro de comida, agua e medkit
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

      //gerar valor aleatorio de ganho
      int water = waterDist(gen);
      int food = foodDist(gen);
      int medkit = medkitDist(gen);

      //adicionar os ganhos ao inventorio
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
