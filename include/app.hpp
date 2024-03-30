#pragma once
#include "survivor.hpp"

class app{
public:
  app();
  void run();
  void printDay(); 
  void goToAnotherDay();
  
private:
  bool isRun = true;
  static int dayCounter;
};
