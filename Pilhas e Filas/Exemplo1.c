#include <stdio.h>
#include <stdlib.h>

#define MAX 5

// STRUCT DO ELEMENTO
// O primeiro passo para utilizar uma fila com mais significado é definir o tipo de dado que será armazenado. 
// No nosso exemplo, cada item da fila representa uma pessoa.
// Lembre-se: esse tipo estruturado facilita a organização dos dados e resulta no uso de informações mais completas nos elementos da fila.
typedef struct
{
    char nome[30];
    int idade;
} Pessoa;

// STRUCT DA FILA
// A fila em si, precisa de um array para armazenar os elementos e as variáveis de controle, para saber onde inserir e remover.
// A struct Fila guarda os dados e controla o estado da fila com índices e contador de elementos.
typedef struct
{
    Pessoa itens[MAX];
    int inicio;
    int fim;
    int total;
} Fila;

// Antes de usar a fila, seus índices e contador precisam ser configurados.
// A inicialização define o ponto de partida da fila, visando ao seu funcionamento correto desde o início.
void InicializarFila(Fila *f)
{
    f->inicio = 0;
    f->fim = 0;
    f->total = 0;
}

// É importante para sabermos se a fila atingiu a capacidade máxima.
// Fila cheia impede novas inserções. Logo, essa verificação evita sobreposição de dados. 
void filaCheia(Fila *f)
{
    return f->total == MAX;
}

// Fazer tal verificação também confirma se há elementos disponíveis para remoção.
// Fila vazia, por sua vez, impede remoções, o que é importante para evitar acesso a posições inválidas.
void filaVazia(Fila *f)
{
    return f->total == 0;
}

// Enqueue adiciona um novo item ao final da fila, se houver espaço.
void inserir(Fila *f, Pessoa p)
{
    if (f->total == MAX)
    {
        printf("Fila cheia. Não é possível inserir.\n");
        return;
    }

    f->itens[f->fim] = p;
    f->fim = (f->fim + 1) % MAX;
    f->total++;
}

void remover(Fila *f, Pessoa *p)
{
    if (filaVazia(f))
    {
        printf("Fila vazia. Não é possível remover.\n");
        return;
    }

    *p = f->itens[f->inicio];             
    f->inicio = (f->inicio + 1) % MAX;     
    f->total--;  
}