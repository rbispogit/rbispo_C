/*Desenvolvimento de um sistema de inventário em C, comparando vetor e lista encadeada, 
  com inserção, remoção, listagem e busca linear, explorando os limites, 
  a flexibilidade e o desempenho de cada estrutura.*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Biblioteca necessária para funções de string (strcpy, strcmp).

// Define uma constante para o comprimento máximo que cada texto pode ter.
#define MAX_STR_LEN 50 // Tamanho máximo de cada string/texto.

// Define uma constante para um número máximo de itens que nossa lista pode conter.
#define TAM_MAX 10 // Define o número máximo de itens na lista estática.

// Estrutura que representa a lista estática
typedef struct 
{
    char dados[TAM_MAX][MAX_STR_LEN]; // Matriz: 10 linhas, 50 colunas.
    int quantidade; // Este é o nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista 
} ListaEstatica;



