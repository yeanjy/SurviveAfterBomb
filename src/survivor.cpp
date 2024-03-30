#include "survivor.hpp"

survivor::survivor(std::string name, int age, char gender, int hunger , int thirst)
:name(name), age(age), gender(gender), hunger(hunger), thirst(thirst) 
{};

void survivor::printData()
{
  std::cout << this->name << " : " << "fome:"<< this->hunger << " sede:" << this->thirst << "\n";
}

void survivor::updateData()
{
  this->hunger-= 0.3;
  this->thirst-= 0.5;
}
