#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

struct nodo {
    struct nodo *ant;
    int chave;
    struct nodo *prox;
};

typedef struct nodo Nodo;

struct Deque {
    Nodo *inicio;
    Nodo *final;
    int qtd;
};

Deque *cria_deque() {
    Deque *dq = (Deque *)malloc (sizeof (Deque));
    if (dq == NULL)
        return NULL;
    dq->final = NULL;
    dq->inicio = NULL;
    dq->qtd = 0;
    return dq;
}

void libera_deque (Deque *dq) {
    if (dq == NULL)
        return;
    Nodo *nodo;
    while (dq->inicio != NULL) {
        nodo = dq->inicio;
        dq->inicio = dq->inicio->prox;
        free (nodo);
    }
    free (dq);
    return;  
}

int tamanho_deque (Deque *dq) {
    // se o deque estiver vazio retorna 0
    if (dq == NULL)
        return 0;
    return dq->qtd;    
}

int deque_vazio (Deque *dq) {
    if (dq == NULL)
        return 1;
    if (dq->qtd == 0)
        return 1;
    return 0; 
}

int consultainicio_deque (struct Deque *dq, int *valor) {
    if (dq == NULL)
        return 0;
    if (dq->qtd == 0)
        return 0;
    valor = dq->inicio->chave;
    return 1;
}
