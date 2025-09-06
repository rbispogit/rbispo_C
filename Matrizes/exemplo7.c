#include <stdio.h>
#include <stdbool.h>

#define LINHA 10 // Constante de linhas
#define COLUNA 10 // Constante de colunas

// Este programa é uma versão melhorada do exemplo 6
int main ()
{
    int tabela[LINHA][COLUNA];
    int valores = 1;
    int alvo = 51;
    bool encontrado = false;
    
    // Cria a tabela e atribui os valores de 1 a 9
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            tabela[i][j] = valores; // Atribuindo os valores de 1 a 9
            valores++; 
            printf("[%d]", tabela[i][j]);
        }
        printf("\n");
    }

    // Procura o valor determinado na variável "alvo"
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            if (tabela[i][j] == alvo)
            {
                printf("Número %d encontrado no índice [%d][%d]\n", alvo, i, j);
                encontrado = true;
                break; // Sai do loop interno
            }
        }
        if (encontrado) break; // Sai do loop externo, apenas se a variável "encontrado" for verdade
    }

    if (!encontrado) // Poderia ser escrito: (encontrado == false)
    {
        printf("Elemento %d não encontrado na matriz.\n", alvo);
    }

return 0;
}