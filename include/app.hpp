#pragma once
#include "survivor.hpp"
#include <item.hpp>
#include <memory>
#include <vector>

class app{
public:
  app();
  void run();
  void printDay(); 
  void goToAnotherDay();
  void addMember();
  void printFamilyData();
  void updateFamilyData();
  void checkMenberIsAlive();
  void checkEndOfGame();
  void initInventory();
  void printInventory();
private:
  bool isRun = true;
  static int dayCounter;
  std::vector<survivor> family;
  std::vector<std::shared_ptr<item>> inventory;
};
