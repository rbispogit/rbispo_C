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
  int quantidade;                   // Este é o nosso contador de controle. Ele informa quantos itens estão realmente armazenados na lista
} ListaEstatica;

// Funções da Lista Estática

// Esta função prepara a lista pra ser usada.
// Ela simplesmente define o contador quantidade como 0, indicando que a lista está vazia.
// Recebemos um ponteiro (*lista) para modificar a variável original passada para a função.
void inicializarListaEstatica(ListaEstatica *lista);

void inserirListaEstatica(ListaEstatica *lista, const char *texto);
void removerListaEstatica(ListaEstatica *lista, const char *texto);
void listarListaEstatica(const ListaEstatica *lista);

// ----------------------------------------
// PARTE 2: LISTA ENCADEADA (DE STRINGS)
// ----------------------------------------

// Estrutura do nó (cada elemento da lista)
// - char* dado: Este é um ponteiro. Ele não armazena o texto em si, mas sim o endereço
// de memória onde o texto está guardado.
// Isso é muito flexível, pois cada texto pode ter um tamanho diferente, e alocamos apenas
// a memória necessária para cada um.
// - struct No *proximo: Este é o ponteiro que cria a "ligação". Ele armazena o endereço do próximo nó na lista.
// O último nó da lista terá este ponteiro apontando para NULL.
typedef struct No
{
  char *dado;
  struct No *proximo; // Ponteiro para a string (alocada dinamicamente)
} No;

// Isso é um atalho. Em vez de escrever No* sempre que quisermos nos refereir a nossa lista, podemos simplesmente usar...((cortou))
// A "lista" em si é apenas um ponteiro para o primeiro nó (a "cabeça da lista").
typedef No *ListaEncadeada;

// Funções da Lista Encadeada

// Uma lista encadeada vazia é representada por um ponteiro de cabeça que aponta para NULL.
// Essa função simplesmente atribui NULL ao ponteiro que representa nossa lista.
void inicializarListaEncadeada(ListaEncadeada *lista);

void inserirListaEncadeada(ListaEncadeada *lista, const char *texto);
void removerListaEncadeada(ListaEncadeada *lista, const char *texto);
void listarListaEncadeada(const ListaEncadeada *lista);
void liberarListaEncadeada(ListaEncadeada *lista); // Função nova para limpar a memória

// -----------------------------------------------
// FUNÇÃO PRINCIPAL (main) E MENUS
// -----------------------------------------------

void menuListaEstatica();
void menuListaEncadeada();

int main()
{
  int opcao;
  do
  {
    printf("\n --- MANIPULAÇÃO DE LISTAS (TEXTO) ---\n");
    printf("1. Lista Estatica\n");
    printf("2. Lista Encadeada\n");
    printf("0. Sair do Programa\n");
    printf("Escolha uma opção: \n");
    scanf("%d", &opcao);

    switch (opcao)
    {
      case 1:
        menuListaEstatica();
        break;
      case 2:
        menuListaEncadeada();
        break;
      case 0:
        printf("Saindo...\n");
        break;

      default:
        break;
    }
  } while (opcao != 0);


  return 0;
}
