#include <random>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>
#include "item.hpp"
#include "survivor.hpp"
typedef void (*FunctionPointer)(survivor&, std::unordered_map<std::shared_ptr<item>,int>&, double porcentage);

extern std::string openText;
extern std::string endText;
extern survivor dad;
extern survivor mon;
extern survivor son;
extern survivor daughter;
extern std::random_device rd;
extern std::mt19937 gen;
extern std::vector<survivor> family;
extern std::vector<FunctionPointer> events;
extern std::unordered_map<std::shared_ptr<item>, int> inventory;
extern bool isRun;
extern int dayCounter;
void initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory);
