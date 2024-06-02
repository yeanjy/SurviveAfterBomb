#pragma once
#include "item.hpp"
#include <memory>
#include <string>
#include <unordered_map>

class survivor{
public:
  survivor(std::string name, int age, char gender, double height,
          double weight, int hunger = 5, int thirst = 5);
  void printData();
  void updateData(std::unordered_map<std::shared_ptr<item>, int> &inventory);
  void eat();
  void drink();
  void setIsDead();
  void setIsSick();
  void setIsExploring(bool n);
  void setExploringDays(int n);
  void addExploringDays();
  void checkIsAlive();
  void setHunger(int n);
  void setThirst(int n);
  void antiWarn();
  void goToExplore(std::unordered_map<std::shared_ptr<item>, int> &inventory, bool &exploring, bool &tookTheMask);
  void setDaySinceSick(int n);
  double updateHunger();
  double updateThirst();
  int getExploringDay();
  bool getIsAlive();
  bool getIsHealthy();
  bool getIsExploring();
  std::string getName();
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
  int daySinceSick;
  bool isExploring;
  int exploringDays;
};
