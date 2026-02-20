// Alocação dinâmica usando malloc (COM ERRO PROPOSITAL)
// Erros corrigidos no Exemplo3.c

#include <stdio.h>

int main()
{
    int *a, b;

    b = 10;
    a = (int*) malloc(sizeof(int)); // função de alocação de memoria dinamica

    *a = 20;

    a = &b; // ERRO - perdeu a referencia do espaço alocado
    free (a); // ERRO - tentou liberar memoria estatica

    return 0;
}