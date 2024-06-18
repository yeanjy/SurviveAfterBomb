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

int main()
{
  //ler arquivo json
  std::ifstream j("survivors.json");
  json familyjson = json::parse(j);

  //input de quantidade de simulacoes e sobreviventes
  int n;
  std::cout << "Quantas simulacoes? \n";
  std::cin >> n;
  size_t s;
  std::cout << "Quantos sobreviventes? \n";
  std::cin >> s;

  //verificar se a quantidade de sobreviventes e maior que o total de sobreviventes
  if (s > familyjson.size())
  {
    std::cout << "Quantidade de sobreviventes maior que o total de sobreviventes\n";
    return 0;
  }

  //dia recorde
  unsigned int recordDay = 0;
  int simulationCounter = 1;
  int simulationRecord;
  //vetor de evnetos do dia recorde
  std::vector<std::string> v;

  //loop para rodar as simulacoes n vezes
  for (int i = 0; i < n; i++)
  { 
    //vetor de sobreviventes
    std::vector<survivor> family;

    //adicionar sobreviventes ao vetor
    for (size_t i = 0; i < s; ++i)
    {
      auto& it = familyjson.at(i);
      family.emplace_back(it["name"], it["age"], it["gender"].get<std::string>()[0], it["height"], it["weight"]);
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
