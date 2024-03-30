#pragma once
#include <iostream>

class survivor{
public:
  survivor(std::string name, int age, char gender, int hunger = 5, int thirst = 5);
  void printData();

private:
  std::string name;
  int age;
  char gender;

  int hunger; //0-5
  int thirst; //0-5
  
};
