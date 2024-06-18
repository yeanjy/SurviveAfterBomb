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

  //verificar se a quantidade de simulacoes e sobreviventes e valida
  if (n <= 0 || s <= 0 || s > familyjson.size())
  {
    std::cout << "Numero de simulacoes ou sobreviventes invalido\n";
    return 0;
  }

  //dia recorde
  unsigned int recordDay = 0;
  //contador de simulacoes
  int simulationCounter = 1;
  //simulacao que teve o dia recorde
  int recordSimultation;
  //vetor de eventos do dia recorde
  std::vector<std::string> recordEvents;

  //loop para rodar as simulacoes n vezes
  for (int i = 0; i < n; i++)
  { 
    //vetor de sobreviventes
    std::vector<survivor> family;

    //adicionar s sobreviventes ao vetor
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
      recordEvents = mApp->ocurredEvent;
      recordSimultation = simulationCounter;
    }
    simulationCounter++;
  }

  //imprimir o dia recorde 
  std::cout << "----------------------------------\n";
  std::cout << "Dia recorde : " << recordDay-1 << std::endl;
  std::cout << "Simulacao numero : " << recordSimultation << std::endl;

  //imprimir eventos do dia recorde
  for (size_t i = 0; i < recordEvents.size(); i++)
    std::cout << recordEvents[i] << "\n" ;

  return 0;
}
