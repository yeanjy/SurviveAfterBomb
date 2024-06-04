#pragma once
#include "item.hpp"

class food : public item{
public:
  food();
  void printItem() override; 
  std::string toString() override;
}; 
