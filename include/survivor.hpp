#pragma once
#include <iostream>

class survivor{
public:
  survivor(std::string name, int age, char sex, int hunger, int thirst);

private:
  std::string name;
  int age;
  char sex;

  int hunger; //0-10
  int thirst; //0-10
  
  // int power; //0-100
};
