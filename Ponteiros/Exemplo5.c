// Este código da um exemplo de como utilizar ponteiros com strucs

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char nome[30];
    int idade;
}Ficha;

int main()
{
    Ficha* p = (Ficha*)malloc(sizeof(Ficha));
    if (p == NULL) return 1;

    printf("Digite o nome: ");
    scanf("%s", p->nome);
    printf("Digite a idade: ");
    scanf("%d", &p->idade);

    printf("%s tem %d anos.\n\n", p->nome, p->idade);
    free(p);

    return 0;
}