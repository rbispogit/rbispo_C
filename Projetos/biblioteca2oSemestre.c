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
                printf("Digite o autor: ");
                fgets(biblioteca[totalLivros].autor, TAM_STRING, stdin);
                printf("Digite a editora: ");
                fgets(biblioteca[totalLivros].editora, TAM_STRING, stdin);

                biblioteca[totalLivros].nome[strcspn(biblioteca[totalLivros].nome)], "\n" = '0';
                biblioteca[totalLivros].autor[strcspn(biblioteca[totalLivros].autor)], "\n" = '0';
                biblioteca[totalLivros].editora[strcspn(biblioteca[totalLivros].editora)], "\n" = '0';

                printf("Digite a edição: ");
                scanf("%d", &biblioteca[totalLivros].edicao);
                limparBuffer();

                // Ao cadastrar, o livro se torna automaticamento disponível.
                biblioteca[totalLivros].disponivel = 1;

                totalLivros++;
                printf("Livro cadastrado com sucesso!\n");
            }
            else
            {
                printf("Biblioteca cheia.\n");
            }
            printf("Pressione enter para continuar . . .\n");
            getchar();
            break;

        case 2: // LISTAGEM DE LIVROS
            printf("--- Lista de Livros Cadastrados ---\n\n");
            if (totalLivros == 0)
            {
                printf("Nenhum livro cadastrado ainda.\n");
            }
            else
            {
                for (int i = 0; i < totalLivros; i++)
                {
                    printf("----------------------------------------\n");
                    printf("LIVRO %d\n", i + 1);
                    printf("-Nome: %s", biblioteca[i].nome);
                    printf("-Autor: %s", biblioteca[i].autor);
                    // Mostra o status de disponibilidade
                    printf("-Status: %s", biblioteca[i].disponivel ? "Disponivel" : "Emprestado");
                }
                printf("----------------------------------------\n");
            }
            printf("Pressione enter para continuar . . .\n");
            getchar();
            break;

        case 3: // Realizar Emprestimo
            printf("--- Lista de Livros Cadastrados ---\n\n");

            if (totalEmprestimos >= MAX_EMPRESTIMOS)
            {
                printf("Limite de empréstimos atingido.\n");
            }
            else
            {
                printf("Livros disponíveis:\n");
                int disponiveis = 0;
                for (int i = 0; i < totalLivros; i++)
                {
                    if (biblioteca[i].disponivel)
                    {
                        printf("%d - %s\n", i + 1, biblioteca[i].nome);
                        disponiveis++;
                    }
                }

                if (disponiveis == 0)
                {
                    printf("Nenhum livro disponível para empréstimo.\n");
                }
                else
                {
                    printf("Digite o número do livros que deseja emprestar: ");
                    int numLivro;
                    scanf("%d", &numLivro);
                    limparBuffer();

                    int indice = numLivro - 1; // Converte para o índice do array (0 a N - 1)

                    // Validação da escolha do usuário.
                    if (indice >= 0 && indice < totalLivros && biblioteca[indice].disponivel)
                    {
                        printf("Digite o nome do usuário que está pegando o livro: ");
                        fgets(emprestimos[totalEmprestimos].nomeUsuario, TAM_STRING, stdin);
                        emprestimos[totalEmprestimos].nomeUsuario[strcspn(emprestimos[totalEmprestimos].nomeUsuario, "\n")] = '0'; // NO VIDEO FALTOU ESSA PARTE DO CÓDIGO

                        // Registra o empréstimo.
                        emprestimos[totalEmprestimos].indiceLivro = indice;

                        // Atualiza o status do livro para indisponível.
                        biblioteca[indice].disponivel = 0;

                        totalEmprestimos++;
                        printf("Empréstimo realizado com sucesso!\n");
                    }
                    else
                    {
                        printf("Número de livro inválido, ou livro indisponível.\n");
                    }
                }
            }
            printf("\nPressione enter para continuar . . .\n");
            getchar();
            break;

        case 4: // LISTAR EMPRÉSTIMOS
            printf("--- Lista de Empréstimos ---\n\n");
            if (totalEmprestimos == 0)
            {
                printf("Nenhum empréstimo realizado.\n");
            }
            else
            {
                for (int i = 0; i < totalEmprestimos; i++)
                {
                    // Usa o indice armazenado no emprestimo para buscar o nome do livro.
                    int indiceLivro = emprestimos[i].indiceLivro;
                    printf("----------------------------------------\n");
                    printf("EMPRESTIMO %d\n", i + 1);
                    printf("Livro: %s\n", biblioteca[indiceLivro].nome);
                    printf("Usuário: %s\n", emprestimos[i].nomeUsuario);
                }
                printf("----------------------------------------\n");
            }
            printf("\nPressione enter para continuar . . .\n");
            getchar();
            break;

        case 0:
            printf("Saindo do Sistema . . .\n");
            break;
        default:
            printf("Opção inválida.\n");
            printf("\nPressione enter para continuar . . .");
            getchar();
            break;
        }
    } while (opcao != 0);

    free(biblioteca);
    free(emprestimos);

    return 0;
}