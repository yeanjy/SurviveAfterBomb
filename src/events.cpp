#include "events.hpp"

void getSick(survivor &s)
{
  if (!s.getIsHealthy())  
    s.setIsDead();  
  else 
    s.setIsSick();
}
