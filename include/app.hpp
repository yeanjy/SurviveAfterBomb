#pragma once
#include <item.hpp>

class app{
public:
  app();
  ~app() = default;
  void run();
  void printDay(); 
  void printFamilyData();
  void updateFamilyData();
  void checkMenberIsAlive();
  void checkEndOfGame();
  void consumeEvents();
  void checkExplore();
  void printInventory();
  bool checkFamilyHealth();
};
