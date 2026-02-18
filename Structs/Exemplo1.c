#include <stdio.h>

// Definindo uma estrutura para um Aluno
typedef struct {
    char nome[50];
    int idade;
    float media;
} Aluno;


int main(){

// Criando e inicializando uma variável do tipo Aluno
Aluno aluno1 = {"João", 20, 9.5};

// Acessando os dados com o operador '.' (ponto)
printf("Aluno: %s\n", aluno1.nome);
printf("Idade: %d\n", aluno1.idade);
printf("Nota: %.1f\n", aluno1.media);


return 0;
}