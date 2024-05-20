#include "variables.hpp"
#include "survivor.hpp"
#include <random>

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";

survivor dad("Ted", 35, 'm', 173, 90);
survivor mon("Dolores", 31, 'f', 181, 72);
survivor son("Timmy", 14, 'm', 142, 42);
survivor daughter("Mary Jane", 17, 'f', 163, 62);
std::random_device rd;
std::mt19937 gen(rd());
