#include <stdio.h>

// Manipula a matriz, alterando os valores acima de 5 para negativos
int main ()
{
    int tabela[3][3];
    int elemento = 1;

    // Cria a estrutura da tabela adicionando valores de 1 a 9
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabela[i][j] = elemento; // Inclui o elemento na coordenada da matriz 
            elemento++; // Aumenta o valor do elemento até prrencher todas as coordenadas

            printf("[%d]", tabela[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Lógica para mudar para negativo, valores acima de 5
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabela[i][j] > 5) // Se o valor do elemento for maior que 5, então mude para negativo
            {
                tabela[i][j] = - tabela[i][j]; // Muda para negativo
                printf("[%d]", tabela[i][j]);
            }
        }
    }

    return 0;
}