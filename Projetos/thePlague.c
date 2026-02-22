//Projeto de um game 2D

#include <stdio.h>

struct Profile
{
    char nome[20];
    int força;
    int inteligencia;
    int agilidade;
};

int main()
{
    struct Profile personagem1 = {"Damien Lesaint", 29, 5, 10}; //human bruto, cidade natal Paris, recebe a dadiva de dragão
    struct Profile personagem2 = {"Lucie Lesaint", 3, 28, 15}; //human mage, cidade natal Paris, recebe a dadiva de magia
    struct Profile personagem3 = {"Aleron Bloodraine", 14, 15, 25}; //vampiro gunblade, cidade natal Valoria
    int opcao = 0;

    printf("********************\n");
    printf("***  THE PLAGUE  ***\n");
    printf("********************\n\n");
    printf("   - Start Game -   \n\n");

    /*switch (opcao)
    {

    }*/

    return 0;
}