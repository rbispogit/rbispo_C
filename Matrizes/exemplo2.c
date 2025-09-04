#include <stdio.h>
// Definindo duas constantes
#define LINHAS 2
#define COLUNAS 10

// Exibe valores crescentes em uma matriz
int main()
{
    int matriz[LINHAS][COLUNAS];
    int soma = 0;

    for (int i = 0; i < LINHAS; i++)
    {
        for (int j = 0; j < COLUNAS; j++)
        {
            soma++;
            matriz[i][j] = soma;
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}