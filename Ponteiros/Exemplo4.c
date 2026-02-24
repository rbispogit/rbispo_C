// Código que executa uma função através de um ponteiro

#include <stdio.h>

void saudacao()
{
    printf("Olá, mundo!\n\n");
}

int main()
{
    void (*ptr)() = saudacao; // ponteiro para a funcao
    ptr();                    // chamada indireta

    return 0;
}