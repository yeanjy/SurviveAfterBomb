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
