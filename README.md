# SurviveAfterBomb
Simulação de sobrevivência feito em C++

## Como rodar

```bash
cmake .
make -j4
./bin/bomba
```

## Estratégia

Você pode configurar a sua estratégia de sobrevivência no arquivo [strategy.json](https://github.com/yeanjy/SurviveAfterBomb/blob/main/strategy.json)

| Variável    | Descrição                                                  |
|:------------|------------------------------------------------------------|
| eat_e       | Comer quando a fome for menor que `eat_e`                  |
| drink_e     | Beber quando a sede for menor que `drink_e`                |
| explore_e   | Explorar quando a comida ou água for menor ou igual a `explore_e` |
| food_q      | Quantidade inicial de comida no inventário                 |
| water_q     | Quantidade inicial de água no inventário                   |
| mask_q      | Quantidade inicial de máscaras no inventário               |
| medkit_q    | Quantidade inicial de kits médicos no inventário           |

## Sobreviventes

Você pode adicionar mais sobreviventes ou configurar as informações dos sobreviventes no arquivo [survivors.json](https://github.com/yeanjy/SurviveAfterBomb/blob/main/survivors.json).

## Gráficos

Todas as simulações foram utilizadas as estratégias do arquivo [strategy.json](https://github.com/yeanjy/SurviveAfterBomb/blob/main/strategy.json)

![1000 simulações SurviveAfterBomb](https://github.com/yeanjy/SurviveAfterBomb/assets/129001484/bc9815de-eeb2-432e-8f43-9f8ab9785bf0)

![10000 simulações SurviveAfterBomb](https://github.com/yeanjy/SurviveAfterBomb/assets/129001484/6602b1b6-260a-4a16-a644-f1882c9ebcc3)

![100000 simulações SurviveAfterBomb](https://github.com/yeanjy/SurviveAfterBomb/assets/129001484/96265935-9866-4ef0-b611-84cc284ffdbe)

Exemplo de uma saída pode ser visto no arquivo [exec.txt](https://github.com/yeanjy/SurviveAfterBomb/blob/main/exec.txt)

## Diagrama de classes
![diagrama](https://github.com/yeanjy/SurviveAfterBomb/assets/129001484/a04a03fc-654e-4663-bae6-26486a8c7de2)


