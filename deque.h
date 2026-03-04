#ifndef DEQUE_H
#define DEQUE_H

#include <stdio.h>

typedef struct Deque Deque;
// Cria o deque e retorna um ponteiro para ele
struct Deque *cria_deque ();
// libere todos nodos do deque, inclusive ele mesmo
void libera_deque (struct Deque *dq);
// retorna o tamanho do deque;
int tamanho_deque (struct Deque *dq);
// se o deque não existir ou tiver 0 elementos, retorna 1. Caso contrário, retorna 0
int deque_vazio (struct Deque *dq);
// se o deque não existir ou estiver vazio, retorna 0. Caso contrário, valor recebe dq->incio e retorna 1
int consultainicio_deque (struct Deque *dq, int *valor);

#endif
