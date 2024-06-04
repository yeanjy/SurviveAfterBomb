#pragma once
#include "item.hpp"  

class respiratoryMask : public item{
public:
  respiratoryMask();
  void printItem() override;  
  std::string toString() override;
};
