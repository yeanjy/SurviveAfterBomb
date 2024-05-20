#pragma once
#include "survivor.hpp"
#include <item.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
typedef void (*FunctionPointer)(survivor&, std::unordered_map<std::shared_ptr<item>,int>&, double porcentage);

class app{
public:
  app();
  void run();
  void printDay(); 
  void addMember();
  void printFamilyData();
  void updateFamilyData();
  void checkMenberIsAlive();
  void checkEndOfGame();
  void initInventory();
  void initEvents();
  void consumeEvents();
  void printInventory();
  std::unordered_map<std::shared_ptr<item>, int> inventory;
private:
  bool isRun = true;
  static int dayCounter;
  std::vector<survivor> family;
  std::vector<FunctionPointer> events;
};
