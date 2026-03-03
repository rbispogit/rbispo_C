// Exemplo de como usar uma função com passagem de parâmetros por valor
// Ela não modifica o valor original

#include <stdio.h>

void dobrador(int x)
{
    x = x * 2;
    printf("Dentro da função, o valor da cópia é: %d\n", x);
}

int main()
{
    int x;

    printf("Digite um valor: ");
    scanf("%d", &x);

    printf("Antes de chamar a função, o valor original é: %d\n", x);
    printf("Chamando a função . . .\n");
    dobrador(x);

    return 0;
}