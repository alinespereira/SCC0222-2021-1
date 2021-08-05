#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int power;
    int type;
} Attack;

int main()
{
    int types;
    float **type_ratios;
    Attack *attack_power;
    int attacks = 0;
    int power = 0, type;
    int target;
    int best_type;
    float damage;

    scanf("%d\n", &types);

    type_ratios = (float **)malloc(types * sizeof(float *));
    for (int i = 0; i < types; i++)
        type_ratios[i] = (float *)malloc(types * sizeof(float));

    for (int i = 0; i < types; i++)
        for (int j = 0; j < types; j++)
            scanf("%f", &type_ratios[i][j]);

    while (1)
    {
        scanf("%d", &power);
        if (power == -1)
            break;
        scanf("%d", &type);
        attacks++;

        if (attacks == 1)
            attack_power = (Attack *)malloc(sizeof(Attack));
        else
            attack_power = (Attack *)realloc(attack_power, attacks * sizeof(Attack));

        Attack a = {.power = power, .type = type};
        attack_power[attacks - 1] = a;
    }
    scanf("%d", &target);

    // for (int i = 0; i < types; i++)
    // {
    //     for (int j = 0; j < types; j++)
    //     {
    //         printf("%.2f ", type_ratios[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");

    // for (int i = 0; i < attacks; i++)
    //     printf("power: %3d | type: %3d\n", attack_power[i].power, attack_power[i].type);

    // printf("target: %d\n", target);

    best_type = 0;
    damage = 0.0f;

    for (int i = 0; i < attacks; i++)
    {
        power = attack_power[i].power;
        type = attack_power[i].type;
        if (power * type_ratios[type][target] > damage)
        {
            damage = power * type_ratios[type][target];
            best_type = i;
        }
    }

    printf("O melhor ataque possui indice %d e dano %.2f\n", best_type, damage);

    for (int i = 0; i < types; i++)
        free(type_ratios[i]);
    free(type_ratios);
    free(attack_power);

    return 0;
}
