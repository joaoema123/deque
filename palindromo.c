#include <stdio.h>
#include <string.h>
#include "deque.h"

void vector_to_deque (Deque *dq, char *palavra) {
    for (int i = 0; i < strlen (palavra); i++) {
        inserefinal_deque (dq, palavra[i]);
    }
}

int eh_pal (Deque *dq) {
    char valor1, valor2;
    while (tamanho_deque(dq) > 1) {
        removeinicio_deque (dq, &valor1);
        removefinal_deque (dq, &valor2);
        if (valor1 != valor2)
            return 0;
    }
    return 1;
}



int main () {
    char palavra[100];
    Deque *dq = cria_deque ();
    scanf ("%s", palavra);
    vector_to_deque (dq, palavra);
    if (eh_pal(dq))
        printf ("eh palindromo\n");
    else    
        printf ("Nao eh palindromo\n");
    libera_deque (dq);
    return 0;
}