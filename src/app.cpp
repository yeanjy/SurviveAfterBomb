#include "app.hpp"
#include <cstdio>
#include <iostream>
#include <string>

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

app::app(){};

int app::dayCounter = 1;
  
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
  survivor dad("Ted", 35, 'm');
  survivor mom("Dolores", 31, 'f');
  survivor son("Timmy", 14, 'm');
  survivor daughter("Mary Jane", 17, 'f');

  std::cout << openText;

  while (isRun) {
  printDay();  

  dad.printData();
  mom.printData();
  son.printData();
  daughter.printData();

  goToAnotherDay();
}
}
