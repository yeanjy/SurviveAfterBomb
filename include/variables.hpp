#include <random>
#include <fstream>
#include <string>
#include "json.hpp" 
using json = nlohmann::json;

extern std::string openText;
extern std::string endText;
extern std::random_device rd;
extern std::mt19937 gen;
extern std::string jsonString;
