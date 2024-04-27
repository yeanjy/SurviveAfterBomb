#pragma once
#include "survivor.hpp"
#include <string>

class events{
public:
  events(std::string eventText, survivor s);

private:
  std::string eventText;
  survivor s;
};
