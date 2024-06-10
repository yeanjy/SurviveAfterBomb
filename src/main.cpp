#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "app.hpp"

int main(){
  unsigned int recordDay = 0;
  int simulationCounter = 1;
  int simulationRecord;
  std::vector<std::string> v;

  for (int i = 0; i < 10; i++)
  { 
    std::unique_ptr<app> mApp = std::make_unique<app>();
    mApp->run();
    if (mApp->dayCounter > recordDay)
    {
      recordDay = mApp->dayCounter;
      v = mApp->ocurredEvent;
      simulationRecord = simulationCounter;
    }
    simulationCounter++;
  }

  std::cout << "----------------------------------\n";
  std::cout << "Dia recorde : " << recordDay-1 << std::endl;
  std::cout << "Simulacao numero : " << simulationRecord << std::endl;

  for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << "\n" ;

  return 0;
}

// int main()
// {
//   std::unique_ptr<app> mApp = std::make_unique<app>();
//   mApp->run();
//
//   return 0;
// }
