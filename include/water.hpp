#pragma once
#include "item.hpp"

class water : public item{
public:
  water();  
  void printItem() override;
  std::string toString() override;
};
