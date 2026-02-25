// ===============================================================================
// PRÁTICA: SISTEMA DE BIBLIOTECA

// OBJETIVO:
// Adicionar a funcionalidade de empréstimo e introduzir alocação dinâmica.
// - Os arrays de livros e empréstimos são alocados com malloc/calloc.
// - Nova struct para Empréstimo.
// - Liberação de memória com free.
// ===============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// --- Constantes Globais ---
#define MAX_LIVROS 50
#define MAX_EMPRESTIMOS 100 // define a capacidade para empréstimos.
#define TAM_STRING 100

// --- Definição das Estruturas ---
// Struct Livro tem um campo 'disponível' para controlar o status.
struct Livro
{
    char nome[TAM_STRING];
    char autor[TAM_STRING];
    char editora[TAM_STRING];
    int edicao;
    int disponivel; // 1 para sim, 0 para não.
};

// Nova struct para armazenar informações do empréstimo
struct Emprestimo
{
    int indiceLivro; // Para saber qual livro do array 'biblioteca' foi emprestado.
    char nomeUsuario[TAM_STRING];
};

// --- Função limpar o buffer ---
void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

// --- Função principal (main) ---
int main()
{
    // 1. ALOCAÇÃO DINÂMICA DE MEMÓRIA
    // Agora, ao invés de arrays estáticos, usamos ponteiros
    struct Livro *biblioteca;
    struct Emprestimo *emprestimos;

    // Usamos calloc para array de livros. calloc(num_elementos, tam_de_cada_elemento)
    // Vantagem: inicializa toda memória com zeros. Isso significa que 'disponível' já começa com zeros
    biblioteca = (struct Livro *)calloc(MAX_LIVROS, sizeof(struct Livro));

    // Usamos malloc para o array de empréstimos. malloc(tam_total_em_bytes)
    emprestimos = (struct Emprestimo *)malloc(MAX_EMPRESTIMOS * sizeof(struct Emprestimo));

    // VERIFICAÇÃO: É crucial verificar se a alocação de memória deu certo.
    if (biblioteca == NULL || emprestimos == NULL)
    {
        printf("Erro: Falha ao alocar memória.\n");
        return 1; // Retorna 1 para indicar um erro.
    }

    int totalLivros = 0;
    int totalEmprestimos = 0;
    int opcao;

    do
    {
        printf("===================================\n");
        printf("          - BIBLIOTECA -           \n");
        printf("===================================\n");
        printf("1. Cadastrar novo livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Realizar empréstimo\n");
        printf("4. Listar empréstimos\n");
        printf("0. Sair\n");
        printf("-----------------------------------\n");
        printf("Escolha uma opção: \n");
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao)
        {
            case 1: // CADASTRO DE LIVRO
            printf("--- Cadastro de Novo Livro ---\n");
            se (totalLivros < MAX_LIVROS)
            {
                // O acesso aos campos é igual ao do array estático.
                printf("Digite o nome do livro: ");
                fgets(biblioteca[totalLivros].nome, TAM_STRING, stdin);
            }
        }
    }

    return 0;
}