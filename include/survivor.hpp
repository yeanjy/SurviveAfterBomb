#pragma once
#include <iostream>
#include <iomanip>
#include <random>
#include "food.hpp"
#include "water.hpp"


class survivor{
public:
  survivor(std::string name, int age, char gender, double height,
          double weight, int hunger = 5, int thirst = 5, bool isAlive = true);
  void printData();
  void updateData();
  void eat(food &f);
  void drink(water &w);
  double updateHunger();
  double updateThirst();

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
