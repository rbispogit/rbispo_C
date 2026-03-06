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

    primeiro->dado = 10;
    primeiro->proximo = segundo;

    segundo->dado = 20;
    segundo->proximo = terceiro;

    terceiro->dado= 30;
    terceiro->proximo = NULL;

    return 0;
}