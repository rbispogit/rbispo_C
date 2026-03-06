// Lista encadeada

#include <stdio.h>
#include <stdlib.h>

struct No
{
    int dado; // Onde guardamos a informação
    struct No* proximo; // A "seta" que aponta para o próximo nó
};

int main()
{
    struct No* primeiro = (struct No*) malloc(sizeof(struct No));
    struct No* segundo = (struct No*) malloc(sizeof(struct No));
    struct No* terceiro = (struct No*) malloc(sizeof(struct No));

    

    return 0;
}