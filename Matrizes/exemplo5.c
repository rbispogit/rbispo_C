#include <stdio.h>

// Este programa altera valores multiplos de 3 - de uma matriz, para -1
int main ()
{
    int tabela[3][3];
    int valores = 1;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabela[i][j] = valores;
            valores++;

            if (tabela[i][j] % 3 == 0) // Altera o multiplo de 3 para -1
            {
                tabela[i][j] = - 1;
            }

            printf("[%d]", tabela[i][j]);
        }
        printf("\n");
    }
}