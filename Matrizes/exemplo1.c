#include <stdio.h>

// Somar duas matrizes
// Exemplo de soma dos índices: 1+5, 2+6...
int main()
{
    int matriz1[2][2] = {{1,2}, {3,4}};
    int matriz2[2][2] = {{5,6}, {7,8}};
    int soma[2][2];

    // Faz a lógica da soma das duas matrizes, e exibe na tela
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            soma[i][j] = matriz1[i][j] + matriz2[i][j];
            printf("Matriz soma[%d][%d]: %d\n", i, j, soma[i][j]);
        }
    }
}