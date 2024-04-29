#include "events.hpp"

void getSick(survivor &s)
{
  if (s.getIsHealthy())  
  {
    s.setIsHealhy();
  }
  else
  {
    s.setIsAlive();
  }
}
