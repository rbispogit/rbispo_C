// Como declarar ponteiros

#include <stdio.h>

int main()
{
    int x = 10; // supondo que x está armazenado no endereço de memória 01F
    int* p = &x; // a variavel ponteiro p, recebe o endereço de x (01F)

    printf("Valor de x: %d\n", x);
    printf("Endereço de x: %p\n", &x);
    printf("Conteúdo de p (o endereço): %p\n", p);
    printf("Valor apontado por p: %d\n", *p);

    *p = 20; // alterei o valor original de x, usando o ponteiro
    
    printf("Novo valor de x: %d\n", x);

    return 0;
}