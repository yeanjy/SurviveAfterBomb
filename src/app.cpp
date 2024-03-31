#include "app.hpp"

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

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
  for (auto &member : family)
  {
    member.printData();
  }
}

void app::updateFamilyData()
{
  for (auto &member : family)
  {
    member.updateData();
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

void app::run()
{
  std::cout << openText;
  addMember();

  while (isRun) {
  printDay();  
  printFamilyData(); 

  updateFamilyData();
  goToAnotherDay();
}
}
