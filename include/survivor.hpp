#pragma once
#include <iostream>

class survivor{
public:
  survivor(std::string name, int age, char gender, int hunger = 5, int thirst = 5);
  void printData();
  void updateData();

private:
  std::string name;
  int age;
  char gender;

  float hunger; //0-5
  float thirst; //0-5
  
};
