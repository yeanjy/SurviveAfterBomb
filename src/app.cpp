#include "app.hpp"
#include "survivor.hpp"
#include "variables.hpp"
#include <chrono>
#include <cstddef>
#include <cstdio>
#include <iostream>
#include <random>
#include <set>
#include <thread>
#include <vector>

app::app(){};

app::~app(){}

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

void app::printFamilyData()
{
  for (survivor &member : family)
    member.printData();
}

void app::updateFamilyData()
{
  for (auto &member : family)
    member.updateData(inventory);
}

void app::checkMenberIsAlive()
{
  for (auto &member : family)
    member.checkIsAlive();
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
  initInventory(inventory);
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
