#include <iostream>
#include <string>
#include "food.hpp"

food::food()
{}

void food::printItem()
{
  std::cout << "🥫";
}

std::string food::toString()
{
  return "🥫"; 
}
