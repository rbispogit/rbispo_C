// Pilhas

#include <stdio.h>
#include <stdlib.h>

#define MAX 5
 
typedef struct {
    char nome[30];
    int idade;
} Pessoa;
 
// Pilha: contém um vetor de Pessoa e um inteiro topo, que representa o índice do último elemento inserido. Quando a pilha está vazia, o topo é -1.
typedef struct {
    Pessoa itens[MAX];
    int topo;
} Pilha;

// Tal procedimento prepara a pilha para uso.
void inicializarPilha(Pilha *p) {
    p->topo = -1;
}

// O valor retorna verdadeiro (1) se o topo for igual a -1.
// A verificação evita remoções em uma pilha já vazia, o que causaria erro.
int pilhaVazia(Pilha *p) {
    return p->topo == -1;
}

// A verificação evita inserções que ultrapassariam o tamanho permitido da pilha.
int pilhaCheia(Pilha *p) {
    return p->topo == MAX - 1; // O valor retorna verdadeiro (1) se o topo estiver no último índice possível do vetor.
}

// Adiciona um novo elemento no topo da pilha.
void push(Pilha *p, Pessoa nova) {
    if (pilhaCheia(p)) {
        printf("Pilha cheia. Não é possível inserir.\n");
        return;
    }
 
    p->topo++;
    p->itens[p->topo] = nova;
}

// Retira o elemento do topo da pilha.
void pop(Pilha *p, Pessoa *removida) {
    if (pilhaVazia(p)) { // O método verifica se a pilha está vazia antes de tentar remover.
        printf("Pilha vazia. Não é possível remover.\n");
        return; // Não deixa executar os passos seguintes.
    }

    *removida = p->itens[p->topo];
    p->topo--;
}

//  Peek consulta o elemento no topo sem removê-lo.
void peek(Pilha *p, Pessoa *visualizada) {
    if (pilhaVazia(p)) {
        printf("Pilha vazia. Nada para espiar.\n");
        return;
    }

    *visualizada = p->itens[p->topo];
}

// Possibilita visualizar todos os elementos da pilha, do topo até a base.
void mostrarPilha(Pilha *p) {
    printf("Pilha (topo -> base):\n");
    for (int i = p->topo; i >= 0; i--) {
        printf("[%s, %d]\n", p->itens[i].nome, p->itens[i].idade);
    }
    printf("\n");
}

int main() {
    Pilha p;
    inicializarPilha(&p);
 
    Pessoa a = {"Ana", 20};
    Pessoa b = {"Bruno", 35};
    Pessoa c = {"Carlos", 28};
 
    push(&p, a);
    push(&p, b);
    push(&p, c);
 
    mostrarPilha(&p);
 
    Pessoa removida;
    pop(&p, &removida);
    printf("Removida: %s, %d\n", removida.nome, removida.idade);
 
    mostrarPilha(&p);
 
    Pessoa topo;
    peek(&p, &topo);
    printf("Topo atual: %s, %d\n", topo.nome, topo.idade);
 
    return 0;
}