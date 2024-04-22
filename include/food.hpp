#pragma once
#include "item.hpp"
#include <ostream>

class food : public item{
public:
  food();
  void printItem() override; 
}; 
