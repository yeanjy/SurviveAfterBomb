#include <cstdio>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "app.hpp"
#include "json.hpp" 
#include "survivor.hpp"
using json = nlohmann::json;

int main(){
  //input de quantidade de simulacoes e sobreviventes
  int n;
  std::cout << "Quantas simulacoes? \n";
  std::cin >> n;
  size_t s;
  std::cout << "Quantos sobreviventes? \n";
  std::cin >> s;

  //transformar jsonString em json
  json survivorsJson = json::parse(jsonString);

  //dia recorde
  unsigned int recordDay = 0;
  int simulationCounter = 1;
  int simulationRecord;
  //vetor de evnetos do dia recorde
  std::vector<std::string> v;

  for (int i = 0; i < n; i++)
  { 
    //vetor de sobreviventes
    std::vector<survivor> family;

    //verificar se a quantidade de sobreviventes e maior 
    //que o total de sobreviventes do json
    if (s > survivorsJson.size())
    {
      std::cout << "Quantidade de sobreviventes maior que o total de sobreviventes\n";
      return 0;
    }

    //adicionar sobreviventes ao vetor
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

    //instanciar app e rodar
    std::unique_ptr<app> mApp = std::make_unique<app>();
    mApp->run(family);
    //verificar se o dia atual e maior que o dia recorde
    if (mApp->dayCounter > recordDay)
    {
      recordDay = mApp->dayCounter;
      v = mApp->ocurredEvent;
      simulationRecord = simulationCounter;
    }
    simulationCounter++;
  }

  //imprimir o dia recorde 
  std::cout << "----------------------------------\n";
  std::cout << "Dia recorde : " << recordDay-1 << std::endl;
  std::cout << "Simulacao numero : " << simulationRecord << std::endl;

  //imprimir eventos do dia recorde
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
