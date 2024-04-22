#include "app.hpp"
#include "food.hpp"
#include "survivor.hpp"
#include "water.hpp"
#include <cstdio>
#include <iostream>
#include <memory>
#include <string>

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";

survivor dad("Ted", 35, 'm', 173, 90);
survivor mom("Dolores", 31, 'f', 181, 72);
survivor son("Timmy", 14, 'm', 142, 42);
survivor daughter("Mary Jane", 17, 'f', 163, 62);

app::app(){};

int app::dayCounter = 1; 

void app::addMember()
{
  family.push_back(dad); 
  family.push_back(mom);
  family.push_back(son);
  family.push_back(daughter);
}

void app::printFamilyData()
{
  for (survivor &member : family)
  {
    member.printData();
  }
}

void app::updateFamilyData()
{
  for (survivor &member : family)
  {
    member.updateData();
  }
}

void app::checkMenberIsAlive()
{
  for (auto &menber : family)
  {
    menber.checkIsAlive();
  }
}

void app::initInventory()
{
  for (auto i = 0; i < 5; i++)
  {
    std::shared_ptr<item> f = std::make_shared<food>();
    inventory.push_back(f);
  }

  for (auto i = 0; i < 5; i++)
  {
    std::shared_ptr<item> w = std::make_shared<water>();
    inventory.push_back(w);
  }
}

void app::checkEndOfGame()
{
  size_t counter = 0;
   for (auto &menber : family)
  {
    if (!menber.getIsAlive())
      counter++;
  }

  if (counter == family.size()) 
  {
    std::cout << endText; 
    isRun = false;
  }
}

void app::printDay()
{
  std::cout << "\n";
  std::cout << "Dia : " << dayCounter << "\n";
  std::cout << "\n";
  dayCounter++;
}

void app::goToAnotherDay()
{
  std::cout << "Pressione enter para ir pro próximo dia\n";
  getchar();
}

void app::printInventory()
{
  std::cout << "Inventório: ";
  for (auto &item : inventory)
  {
    item->printItem(); 
  }
  std::cout << "\n";
}

void app::run()
{
  std::cout << openText;
  addMember();
  initInventory();

  while (isRun)
  {
  checkMenberIsAlive();
  printDay();  
  printInventory();
  printFamilyData(); 

  updateFamilyData();
  goToAnotherDay();
  checkEndOfGame();
  }
}
