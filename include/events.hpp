#pragma once
#include "item.hpp"
#include "survivor.hpp"
#include <memory>
#include <string>
#include <vector>

class events{
public:
  events(std::string eventText, survivor s, std::vector<std::shared_ptr<item>> inventory);

private:
  std::string eventText;
  std::vector<std::shared_ptr<item>> inventory;
  survivor s;
};
