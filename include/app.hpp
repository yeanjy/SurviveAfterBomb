#pragma once
#include "survivor.hpp"
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
  
private:
  bool isRun = true;
  static int dayCounter;
  std::vector<survivor> family;
};
