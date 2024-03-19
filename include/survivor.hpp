#pragma once

#include <iostream>

class survivor{
public:
  survivor();
  survivor(std::string name, int age, char sex);

private:
  std::string name;
  int age;
  char sex;

  int hunger; //0-10
  int thirst; //0-10
  
  int power; //0-100
};
