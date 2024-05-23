#pragma once
#include <item.hpp>

class app{
public:
  app();
  void run();
  void printDay(); 
  void printFamilyData();
  void updateFamilyData();
  void checkMenberIsAlive();
  void checkEndOfGame();
  void consumeEvents();
  void printInventory();
};
