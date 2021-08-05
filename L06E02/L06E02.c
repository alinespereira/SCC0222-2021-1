#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NAME_SIZE 51
#define MAX_TYPENAME_SIZE 21
#define MAX_ATTACK_SIZE 21
#define MAX_ATTACKS 4

typedef struct attribute
{
    int hp;
    int attack;
    int defense;
    int special_attack;
    int special_defense;
    int speed;
} attribute_t;

typedef struct attack
{
    char name[MAX_TYPENAME_SIZE];
    int base_power;
    float accuracy;
    char attack_class;
} attack_t;

typedef struct pokemon
{
    char name[MAX_NAME_SIZE];
    char primary_type[MAX_TYPENAME_SIZE];
    char secondary_type[MAX_TYPENAME_SIZE];
    attribute_t attr;
    attack_t attack[MAX_ATTACKS];
    int n_attacks;
} pokemon_t;

typedef struct pokedex
{
    pokemon_t *pokemon;
    int n_pokemon;
} pokedex_t;

typedef enum command
{
    STOP = 0,
    ADD_POKEMON = 1,
    ADD_ATTACK = 2,
    SHOW_POKEMON = 3,
    SHOW_ATTACK = 4
} command_t;

pokemon_t read_pokemon();
void show_pokemon(pokemon_t pokemon);
void add_pokemon(pokedex_t *pokedex);
attack_t read_attack();
void show_attack(attack_t attack);

int main()
{
    int option;
    int pokemon_id;
    int attack_id;
    pokedex_t pokedex = {NULL, 0};

    do
    {
        scanf("%d\n", &option);
        switch (option)
        {
        case ADD_POKEMON:
            add_pokemon(&pokedex);
            break;
        case ADD_ATTACK:
            scanf("%d\n", &pokemon_id);
            scanf("%d\n", &attack_id);
            pokedex.pokemon[pokemon_id].attack[attack_id] = read_attack();
            break;
        case SHOW_POKEMON:
            scanf("%d\n", &pokemon_id);
            show_pokemon(pokedex.pokemon[pokemon_id]);
            break;
        case SHOW_ATTACK:
            scanf("%d\n", &pokemon_id);
            scanf("%d\n", &attack_id);
            show_attack(pokedex.pokemon[pokemon_id].attack[attack_id]);
            break;
        case STOP:
            break;
        }
    } while (option != STOP);

    free(pokedex.pokemon);

    return EXIT_SUCCESS;
}

pokemon_t read_pokemon()
{
    pokemon_t pokemon;

    scanf("%s\n", pokemon.name);
    scanf("%s\n", pokemon.primary_type);
    scanf("%s\n", pokemon.secondary_type);
    scanf("%d\n", &pokemon.attr.hp);
    scanf("%d\n", &pokemon.attr.attack);
    scanf("%d\n", &pokemon.attr.defense);
    scanf("%d\n", &pokemon.attr.special_attack);
    scanf("%d\n", &pokemon.attr.special_defense);
    scanf("%d\n", &pokemon.attr.speed);

    return pokemon;
}

void show_pokemon(pokemon_t pokemon)
{
    printf("Nome do Pokemon: %s\n", pokemon.name);
    printf("Tipo primario: %s\n", pokemon.primary_type);
    printf("Tipo secundario: %s\n", pokemon.secondary_type);
    printf("Status:\n");
    printf("\tHP: %d\n", pokemon.attr.hp);
    printf("\tAtaque: %d\n", pokemon.attr.attack);
    printf("\tDefesa: %d\n", pokemon.attr.defense);
    printf("\tAtaque Especial: %d\n", pokemon.attr.special_attack);
    printf("\tDefesa Especial: %d\n", pokemon.attr.special_defense);
    printf("\tVelocidade: %d\n\n", pokemon.attr.speed);
}

void add_pokemon(pokedex_t *pokedex)
{
    pokedex->n_pokemon++;
    pokedex->pokemon = (pokemon_t *)realloc(pokedex->pokemon, pokedex->n_pokemon * sizeof(pokemon_t));
    pokedex->pokemon[pokedex->n_pokemon - 1] = read_pokemon();
}

attack_t read_attack()
{
    attack_t attack;

    scanf("%s\n", attack.name);
    scanf("%d\n", &attack.base_power);
    scanf("%f\n", &attack.accuracy);
    scanf("%c\n", &attack.attack_class);

    return attack;
}

void show_attack(attack_t attack)
{
    printf("Nome do Ataque: %s\n", attack.name);
    printf("Poder base: %d\n", attack.base_power);
    printf("Acuracia: %f\n", attack.accuracy);
    printf("Classe: %c\n\n", attack.attack_class);
}
