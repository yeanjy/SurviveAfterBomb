#pragma once
#include <item.hpp>
#include <memory>
#include <unordered_map>
#include <vector>
#include "variables.hpp"
#include "survivor.hpp"

class app{
public:
  typedef void (*FunctionPointer)(survivor&, std::unordered_map<std::shared_ptr<item>,int>&, app&);
  app();
  ~app() = default;
  void run();
  void printDay(); 
  void printFamilyData(std::vector<survivor> &family);
  void updateFamilyData(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void checkMemberIsAlive(std::vector<survivor> &family);
  void checkEndOfGame(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void consumeEvents(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, std::vector<FunctionPointer> &events);
  void checkExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, bool &exploring, bool &tookTheMask);
  void printInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void updatePorcentage();
  void initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  std::string toStringInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  std::vector<std::string> ocurredEvent;
  bool checkFamilyHealth(std::vector<survivor> &family);
  bool isRun;
  double getSickPorcentage;
  double getLostFoodPorcentage;
  double getLostWaterPorcentage;
  double getLostMedkitPorcentage;
  double armyHelpPorcentage;
  unsigned int dayCounter;
};

