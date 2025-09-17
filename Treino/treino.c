#include <stdio.h>

int main()
{
    int matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            matriz[i][j] = i + j;
            printf("matriz[%d][%d] %d\n", i, j, matriz[i][j]);
        }
    }

    int num1, num2;
    int soma;
    int multiplicacao;

    printf("Digite o 1o número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        soma = num1 + num2;
        printf("A soma dos números é %d\n", soma);
    }
    else if (num1 < num2)
    {
        multiplicacao = num2 * num1;
        printf("O produto dos números é: %d\n", multiplicacao);
    }
    else
    {
        printf("Números iguais.\n");
    }




    return 0;
}