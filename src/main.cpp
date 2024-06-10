#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <fstream>
#include "app.hpp"
#include "json.hpp" 
#include "survivor.hpp"
using json = nlohmann::json;

int main(){
  int n;
  std::cout << "Quantas simulacoes? \n";
  std::cin >> n;
  size_t s;
  std::cout << "Quantos sobreviventes? \n";
  std::cin >> s;

  // std::ifstream i("survivors.json");
  // json j = json::parse(i);
  json survivorsJson = json::parse(jsonString);
  unsigned int recordDay = 0;
  int simulationCounter = 1;
  int simulationRecord;
  std::vector<std::string> v;

  for (int i = 0; i < n; i++)
  { 
    std::vector<survivor> family;

    if (s > survivorsJson.size())
    {
      std::cout << "Quantidade de sobreviventes maior que o total de sobreviventes\n";
      return 0;
    }

    for (size_t i = 0; i < s; ++i) 
    {
      family.emplace_back(
          survivorsJson[i]["name"],
          survivorsJson[i]["age"],
          survivorsJson[i]["gender"].get<std::string>()[0],
          survivorsJson[i]["height"],
          survivorsJson[i]["weight"]
      );
    }

    std::unique_ptr<app> mApp = std::make_unique<app>();
    mApp->run(family);
    if (mApp->dayCounter > recordDay)
    {
      recordDay = mApp->dayCounter;
      v = mApp->ocurredEvent;
      simulationRecord = simulationCounter;
    }
    simulationCounter++;
  }

  std::cout << "----------------------------------\n";
  std::cout << "Dia recorde : " << recordDay-1 << std::endl;
  std::cout << "Simulacao numero : " << simulationRecord << std::endl;

  for (size_t i = 0; i < v.size(); i++)
    std::cout << v[i] << "\n" ;

  return 0;
}

// int main()
// {
//   std::ifstream i("survivors.json");
//   json j = json::parse(i);
//
//   std::vector<survivor> family;
//
//   for (auto it : j)
//     family.emplace_back(it["name"], it["age"], it["gender"].get<std::string>()[0], it["height"], it["weight"]);
//
//   std::unique_ptr<app> mApp = std::make_unique<app>();
//   mApp->run(family);
//
//   return 0;
// }
