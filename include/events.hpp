#pragma once
#include <unordered_map>
#include <memory>
#include <app.hpp>
#include "survivor.hpp"
#include "item.hpp"

bool verifyEvent(double porcentage);
void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void getFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void getWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void getMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void lostMedkit(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void lostFood(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void lostWater(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void armyHelp(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void freakOut(survivor &s, std::unordered_map<std::shared_ptr<item>, int> &inventory, app &a);
void exploreGain(std::unordered_map<std::shared_ptr<item>, int> &inventory); 
std::shared_ptr<item> findMedkit(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findWater(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findFood(std::unordered_map<std::shared_ptr<item>, int>& inventory);
std::shared_ptr<item> findMask(std::unordered_map<std::shared_ptr<item>, int>& inventory);
