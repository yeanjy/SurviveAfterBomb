#include "app.hpp"
#include "repiratoryMask.hpp"
#include "food.hpp"
#include "medkit.hpp"
#include "survivor.hpp"
#include "water.hpp"
#include "events.hpp"
#include "variables.hpp"
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <memory>
#include <thread>
#include <vector>

app::app(){};

int app::dayCounter = 1; 

void app::initEvents()
{
  // events.push_back(&getSick);
}

void app::addMember()
{
  family.push_back(dad); 
  family.push_back(mon);
  family.push_back(son);
  family.push_back(daughter);
}

void app::printFamilyData()
{
  for (survivor &member : family)
  {
    member.printData();
  }
}

void app::updateFamilyData()
{
  for (auto &member : family)
  {
    member.updateData();
  }
}

void app::checkMenberIsAlive()
{
  for (auto &menber : family)
  {
    menber.checkIsAlive();
  }
}

void app::initInventory()
{
  std::shared_ptr<item> f = std::make_shared<food>();
  std::shared_ptr<item> w = std::make_shared<water>();
  std::shared_ptr<item> m = std::make_shared<medkit>();
  std::shared_ptr<item> mask = std::make_shared<respiratoryMask>();
  inventory.insert({f, 5});
  inventory.insert({w, 5});
  inventory.insert({m, 1});
  inventory.insert({mask, 1});
}

void app::checkEndOfGame()
{
  size_t survivorCounter = 0;
  for (auto &menber : family)
  {
    if (!menber.getIsAlive())
      survivorCounter++;
  }

  if (survivorCounter == family.size()) 
  {
    std::cout << endText; 
    isRun = false;
  }
}

void app::printDay()
{
  std::cout << "\n";
  std::cout << "Dia : " << dayCounter << "\n";
  std::cout << "\n";
  dayCounter++;
}

void app::goToAnotherDay()
{
  // std::cout << "Pressione enter para ir pro próximo dia\n";
  // getchar();
  std::this_thread::sleep_for(std::chrono::seconds(1));
}

void app::printInventory()
{
  std::cout << "Inventório: ";
  for (auto item : inventory)
  {
    item.first->printItem();
    std::cout  << "x" << item.second << " "; 
  }
  std::cout << "\n";
}

void app::run()
{
  std::cout << openText;
  addMember();
  initInventory();

  while (isRun)
  {
  checkMenberIsAlive();
  printDay();  
  printInventory();
  printFamilyData(); 

  updateFamilyData();
  goToAnotherDay();
  checkEndOfGame();
  }
}
