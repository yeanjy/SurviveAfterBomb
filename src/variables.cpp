#include "variables.hpp"
#include "survivor.hpp"
#include "events.hpp"
#include "food.hpp"
#include "water.hpp"
#include "medkit.hpp"
#include "repiratoryMask.hpp"
#include <random>
#include <memory>
#include <vector>

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";

int dayCounter = 1;
survivor dad("Ted", 35, 'm', 173, 90);
survivor mon("Dolores", 31, 'f', 181, 72);
survivor son("Timmy", 14, 'm', 142, 42);
survivor daughter("Mary Jane", 17, 'f', 163, 62);
bool isRun = true;
std::random_device rd;
std::mt19937 gen(rd());
std::vector<survivor> family = {dad, mon, son, daughter};
std::vector<FunctionPointer> events = {getSick, getFood, getWater, lostFood, lostWater, armyHelp};
std::unordered_map<std::shared_ptr<item>, int> inventory;

void initInventory(std::unordered_map<std::shared_ptr<item>, int> &inventory)
{
  std::shared_ptr<item> w = std::make_shared<water>(); 
  std::shared_ptr<item> f = std::make_shared<food>(); 
  std::shared_ptr<item> m = std::make_shared<respiratoryMask>(); 
  std::shared_ptr<item> med = std::make_shared<medkit>(); 
  inventory.insert({f, 5});
  inventory.insert({w, 5});
  inventory.insert({m, 1});
  inventory.insert({med, 1});
}
