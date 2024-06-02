#include <random>
#include "variables.hpp"

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";
std::random_device rd;
std::mt19937 gen(rd());
