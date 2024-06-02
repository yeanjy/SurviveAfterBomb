#include <random>
#include <memory>
#include <vector>
#include "variables.hpp"
#include "survivor.hpp"
#include "events.hpp"
#include "food.hpp"
#include "water.hpp"
#include "medkit.hpp"
#include "repiratoryMask.hpp"

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";

survivor dad("Ted", 35, 'm', 173, 90);
survivor mon("Dolores", 31, 'f', 181, 72);
survivor son("Timmy", 14, 'm', 142, 42);
survivor daughter("Mary Jane", 17, 'f', 163, 62);
int dayCounter = 1;
bool exploring = false;
bool isRun = true;
bool tookTheMask = false;
std::random_device rd;
std::mt19937 gen(rd());
std::vector<survivor> family = {dad, mon, son, daughter};
std::vector<FunctionPointer> events = {getSick, getFood, getWater, lostFood, lostWater, getMedkit/* , armyHelp */};
std::unordered_map<std::shared_ptr<item>, int> inventory;
double getSickPorcentage = 5;
double getLostFoodPorcentage = 15;
double getLostWaterPorcentage = 15;
double getLostMedkitPorcentage = 10;
double armyHelpPorcentage = 1;


void initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::shared_ptr<item> w = std::make_shared<water>(); 
  std::shared_ptr<item> f = std::make_shared<food>(); 
  std::shared_ptr<item> m = std::make_shared<respiratoryMask>(); 
  std::shared_ptr<item> med = std::make_shared<medkit>(); 
  inventory.insert({f, 10});
  inventory.insert({w, 10});
  inventory.insert({m, 1});
  inventory.insert({med, 1});
}

void updatePorcentage()
{
  getSickPorcentage += 0.5;
  getLostMedkitPorcentage += 0.3;
  getLostFoodPorcentage += 0.4;
  getLostWaterPorcentage += 0.4;
  armyHelpPorcentage += 0.3;
}
