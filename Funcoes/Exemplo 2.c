// Exemplo de como usar uma função com passagem de parâmetros por referência
// Ela faz modificações nos valores originais

#include <stdio.h>

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void dobrador(int* x)
{
    *x = (*x) * 2;
}

int main()
{
    int numero;

    printf("Digite um valor: ");
    scanf("%d", &numero);
    limparBuffer();

    printf("Antes de chamar a função, o valor original é: %d\n", numero);
    
    printf("Chamando a função . . .\n");
    dobrador(&numero);

    printf("Depois de chamar a função, o valor é: %d\n", numero);

    return 0;
}