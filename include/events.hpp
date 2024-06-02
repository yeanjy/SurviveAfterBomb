#pragma once
#include <unordered_map>
#include <memory>
#include "survivor.hpp"
#include "item.hpp"

bool verifyEvent(double porcentage);
void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void getFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void getWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void getMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void lostFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void lostWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void armyHelp(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory);
void exploreGain(std::unordered_map<std::shared_ptr<item>, int> &inventory); 
std::shared_ptr<item> findMedkit(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findWater(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findFood(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findMask(std::unordered_map<std::shared_ptr<item>, int>& inventory);
