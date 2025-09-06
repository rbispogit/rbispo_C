#include <stdio.h>

// Esse programa faz uma contagem de números pares e ímpares na matriz
int main ()
{
    int tabela[3][3];
    int contaPares, contaImpares;
    int valores = 0;

    for (int i= 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabela[i][j] = valores;
            valores++;
            printf("[%d]", tabela[i][j]);

            if (tabela[i][j] % 2 == 0) // Condicional de contagem
            {
                contaPares++;
            }
            else
            {
                contaImpares++;
            }
        }
        printf("\n");
    }

    printf("Total de números pares na matriz: %d\n", contaPares);
    printf("Total de números ímpares na matriz: %d\n", contaImpares);
}