#include <stdio.h>
#include "deque.h"

int main () {
    Deque *dq = cria_deque ();
    libera_deque (dq);
    return 0;
}