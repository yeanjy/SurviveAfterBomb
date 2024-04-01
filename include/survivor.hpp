#pragma once
#include "food.hpp"
#include "water.hpp"
#include <string>

class survivor{
public:
  survivor(std::string name, int age, char gender, double height,
          double weight, int hunger = 5, int thirst = 5, bool isAlive = true);
  void printData();
  void updateData();
  void eat(food &f);
  void drink(water &w);
  void checkIsAlive();
  double updateHunger();
  double updateThirst();
  bool getIsAlive();

private:
  std::string name;
  int age;
  char gender;
  double height;
  double weight;
  float hunger; //0-5
  float thirst; //0-5
  bool isAlive; 

};
