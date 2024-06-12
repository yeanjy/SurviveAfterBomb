#include <random>
#include "variables.hpp"

std::string openText = "Após a eclosão da Terceira Guerra Mundial e a subsequente guerra nuclear, uma família de Frankenmuth emerge como sobrevivente, confrontada não apenas pela devastação imediata, mas também pelo desafio constante de manter-se viva em um mundo transformado em um deserto radioativo e hostil. Com sua casa resistindo ao impacto direto da bomba, eles agora enfrentam a difícil tarefa de sobreviver em um ambiente de recursos escassos, radiação perigosa e a constante ameaça de outros sobreviventes desesperados.\n";

std::string endText = "Todos os membros morreram, fim do jogo\n";
std::random_device rd;
std::mt19937 gen(rd());

std::string jsonString = R"([
        {"name": "Ted", "age": 35, "gender": "m", "height": 173.0, "weight": 90.0},
        {"name": "Dolores", "age": 31, "gender": "f", "height": 181.0, "weight": 72.0},
        {"name": "Timmy", "age": 14, "gender": "m", "height": 142.0, "weight": 42.0},
        {"name": "Mary Jane", "age": 17, "gender": "f", "height": 163.0, "weight": 62.0},
        {"name": "John", "age": 68, "gender": "m", "height": 165.0, "weight": 70.0},
        {"name": "Evelyn", "age": 66, "gender": "f", "height": 160.0, "weight": 65.0},
        {"name": "Mike", "age": 40, "gender": "m", "height": 175.0, "weight": 85.0},
        {"name": "Linda", "age": 38, "gender": "f", "height": 170.0, "weight": 68.0},
        {"name": "Jack", "age": 16, "gender": "m", "height": 160.0, "weight": 55.0},
        {"name": "Tom", "age": 45, "gender": "m", "height": 178.0, "weight": 88.0}
    ])";
