#pragma once
#include "survivor.hpp"
#include <unordered_map>
#include "item.hpp"
#include <memory>

bool verifyEvent(double porcentage);
void getSick(survivor &s, std::unordered_map<std::shared_ptr<item>,int> &inventory, double porcentage);
std::shared_ptr<item> findMedkit(std::unordered_map<std::shared_ptr<item>, int>& inventory);
