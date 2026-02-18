#include <stdio.h>

int main() {

    // Definindo uma estrutura, com struct, para um Aluno
    struct Aluno {
        char nome[50];
        int idade;
        float nota;
    };

    // Criando e inicializando a variável aluno1 do tipo Aluno
    struct Aluno aluno1 = {"Robson", 39, 10.0};

    // Acessando os dados com o operador "."
    printf("Aluno: %s\n", aluno1.nome);
    printf("Idade: %d\n", aluno1.idade);
    printf("Nota: %.1f\n", aluno1.nota);

    return 0;
}