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
  void run(std::vector<survivor> &family, std::vector<FunctionPointer> &events, 
              std::unordered_map<std::shared_ptr<item>, int> &inventory,int eat_e, int drink_e, int explore_e,
           int food_q, int water_q, int mask_q, int medkit_q);
  void printDay(); 
  void printFamilyData(std::vector<survivor> &family);
  void updateFamilyData(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory, int eat_e, int drink_e);
  void checkMemberIsAlive(std::vector<survivor> &family);
  void checkEndOfGame(std::vector<survivor> &family, std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void consumeEvents(std::unordered_map<std::shared_ptr<item>, int> &inventory, std::vector<survivor> &family, std::vector<FunctionPointer> &events);
  void checkExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, 
                    std::vector<survivor> &family, bool &exploring, bool &tookTheMask, int explore_e);
  void printInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void updatePorcentage();
  void initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory,
                        int food_q, int water_q, int mask_q, int medkit_q);
  std::string toStringInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  std::vector<std::string> ocurredEvent;
  bool isRun;
  double getSickPorcentage;
  double getLostFoodPorcentage;
  double getLostWaterPorcentage;
  double getLostMedkitPorcentage;
  double armyHelpPorcentage;
  unsigned int dayCounter;
  double freakOutPorcentage;
};
