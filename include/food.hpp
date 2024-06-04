#pragma once
#include "item.hpp"
#include <string>

class food : public item{
public:
  food();
  void printItem() override; 
  std::string toString() override;
}; 
