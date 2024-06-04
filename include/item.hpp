#pragma once
#include <string>

class item{
public:
  virtual ~item() = default;
  virtual void printItem() = 0;
  virtual std::string toString() = 0;
};
