#pragma once
#include "survivor.hpp"
#include <vector>
#include <cstdio>
#include <iostream>
#include <string>


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
