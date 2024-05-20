#pragma once

class item{
public:
  virtual ~item() = default;
  virtual void printItem() = 0;
};
