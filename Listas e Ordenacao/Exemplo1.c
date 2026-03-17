// Listas Lineares: estáticas e dinâmicas

#include <stdio.h>

int main()

{
    // Lista estática
    int lista[5] = {10, 20, 30, 40, 50};


    // Lista dinâmica
    // Arranja um espaço na memória para guardar 3 números inteiros
    int* numeros = (int*) malloc(3 * sizeof(int));

    // Criando uma lista
    numeros[0] = 10;
    numeros[1] = 20;
    numeros[2] = 30;

    // Expandindo a lista
    numeros = (int*) realloc(numeros, 5 * sizeof(int));

    // Adicionando itens a lista
    numeros[3] = 40;
    numeros[4] = 50;


    return 0;
}