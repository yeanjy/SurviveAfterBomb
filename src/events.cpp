#include "events.hpp"
#include <random>

std::random_device rd;
std::mt19937 gen(rd());


void getSick(survivor &s)
{
  if (!s.getIsHealthy())  
    s.setIsDead();  
  else 
    s.setIsSick();
}
