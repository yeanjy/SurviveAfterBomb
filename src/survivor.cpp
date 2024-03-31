#include "survivor.hpp"

survivor::survivor(std::string name, int age, char gender, double height,
                   double weight, int hunger, int thirst, bool isAlive)
: name(name), age(age), gender(gender), height(height), weight(weight),
  hunger(hunger), thirst(thirst), isAlive(isAlive) {}

void survivor::printData()
{
  std::cout << this->name << " : " << "fome:" << std::setprecision(2)<< this->hunger 
   << " sede:" << this->thirst << "\n";
}

double survivor::updateHunger() {
  double metabolicRate;

  if (gender == 'm') {
     metabolicRate = 66.5 + 13.7 * weight + 5 * height - 6.8 * age;
  } else {
     metabolicRate = 655 + 9.6 * weight + 1.8 * height - 4.7 * age;
  }
 
  metabolicRate -= metabolicRate*0.99;
  double result = metabolicRate;
  result -= result*0.98;

  return result;
}

double survivor::updateThirst()
{
  std::random_device rd;
  std::mt19937 gen(rd());

  if (gender == 'm')
  { 
    std::uniform_real_distribution<> dis(0.4, 0.5);
    return dis(gen);
  }
  else
  { 
    std::uniform_real_distribution<> dis(0.3, 0.4);
    return dis(gen);
  }

}

void survivor::updateData()
{
  double metabolicLoss = updateHunger();
  hunger -= metabolicLoss;
  double thirstLoss = updateThirst();
  thirst -= thirstLoss;
}
