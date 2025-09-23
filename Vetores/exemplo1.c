#include <stdio.h>

// Este programa soma os elementos do vetor e exibe o resultado

int main()
{
    int vetor[5] = {1,2,3,4,5};
    int soma = 0;

    for (int i = 0; i < 5; i++)
    {
        soma += vetor[i]; // Somador (soma = soma + vetor[i])
    }

    printf("Soma dos valores do vetor: %d\n", soma);

    return 0;
}