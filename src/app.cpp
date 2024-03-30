#include "app.hpp"
#include <iostream>
#include <string>

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

int dayCounter = 1;

app::app(){};

void app::run()
{
  survivor dad("Ted", 35, 'm', 10, 10);
  survivor mom("Dolores", 31, 'f',10 ,10);
  survivor son("Timmy", 14, 'm', 10, 10);
  survivor daughter("Mary Jane", 17, 'f', 10, 10);

  std::cout << openText;
  while (isRun) {
  
  std::cout << "\n";
  std::cout << "Dia : " << dayCounter << "\n";
  std::cout << "\n";

  dad.printData();
  mom.printData();
  son.printData();
  daughter.printData();
  
  dayCounter++;
  break;
}
};
