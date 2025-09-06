#include <stdio.h>
#include <stdbool.h>

// Este programa procura por um determinado valor na matriz e exibe sua posição
// Caso encontre o valor, ele para de procurar
int main ()
{
    int tabela[3][3];
    int valores = 1;
    int alvo = 9;
    bool encontrado = false;
    
    // Cria a tabela e atribui os valores de 1 a 9
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            tabela[i][j] = valores; // Atribuindo os valores de 1 a 9
            valores++; 
            printf("[%d]", tabela[i][j]);
        }
        printf("\n");
    }

    // Procura o valor determinado na variável "alvo"
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (tabela[i][j] == alvo)
            {
                printf("Número %d encontrado na posição [%d][%d]\n", alvo, i, j);
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