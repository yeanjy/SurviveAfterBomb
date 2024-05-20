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
#include <random>
#include <set>
#include <thread>
#include <vector>

app::app(){};

int app::dayCounter = 1; 

void app::initEvents()
{
  events.push_back(&getSick);
}

void app::consumeEvents()
{
  for(size_t i = 0; i < 3; i++)
  {
    std::uniform_int_distribution<int> dis(0, events.size()-1) ;
    std::uniform_int_distribution<int> d(0, family.size()-1) ;
    int e = dis(gen);
    int m = d(gen);
    events[e](family[m], inventory, 99);
  }
  // std::uniform_int_distribution<int> dis(0, events.size()-1) ;
  // std::uniform_int_distribution<int> d(0, family.size()-1) ;
  //
  // std::set<int> event;
  // std::set<int> member;
  //
  // while (event.size() < 3)
  // {
  //   int e = dis(gen);
  //   event.insert(e);
  // }
  // while(member.size() < 3)
  // {
  //   int m = d(gen);
  //   member.insert(m);
  // }
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
    member.printData();
}

void app::updateFamilyData()
{
  for (auto &member : family)
    member.updateData();
}

void app::checkMenberIsAlive()
{
  for (auto &member : family)
    member.checkIsAlive();
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
  for (auto &member : family)
  {
    if (!member.getIsAlive())
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
  initEvents();

  while (isRun)
  {
  checkMenberIsAlive();
  printDay();  
  printInventory();
  consumeEvents();
  printFamilyData(); 

  updateFamilyData();
  std::this_thread::sleep_for(std::chrono::seconds(1));
  checkEndOfGame();
  }
}
