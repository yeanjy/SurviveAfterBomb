#pragma once
#include <string>

class survivor{
public:
  survivor(std::string name, int age, char gender, double height,
          double weight, int hunger = 5, int thirst = 5, bool isAlive = true,bool isHealthy = true);
  void printData();
  void updateData();
  void eat();
  void drink();
  void setIsHealhy();
  void setIsAlive();
  void checkIsAlive();
  double updateHunger();
  double updateThirst();
  bool getIsAlive();
  bool getIsHealthy();
private:
  std::string name;
  int age;
  char gender;
  double height;
  double weight;
  float hunger; //0-5
  float thirst; //0-5
  bool isAlive; 
  bool isHealthy;
};
