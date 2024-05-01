#pragma once
#include "survivor.hpp"
#include <item.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
typedef void (*FunctionPointer)(survivor&);

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
  void initEvents();
  void printInventory();
private:
  bool isRun = true;
  static int dayCounter;
  std::vector<survivor> family;
  std::vector<FunctionPointer> events;
  std::unordered_map<std::shared_ptr<item>, int> inventory;
};
