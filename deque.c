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
    // se o que não existir, retorna
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
    // se o que não exisitr retorna 1
    if (dq == NULL)
        return 1;
    if (dq->qtd == 0)
        return 1;
    return 0; 
}

int consultainicio_deque (struct Deque *dq, int *valor) {
    // se o deque não existir, retorna 0
    if (dq == NULL)
        return 0;
    if (dq->qtd == 0)
        return 0;
    *valor = dq->inicio->chave;
    return 1;
}

int consutlafinal_deque (struct Deque *dq, int *valor) {
    // se o deque não existir, retorna 0
    if (dq == NULL)
        return 0;
    if (dq->final == NULL)
        return 0;
    *valor = dq->final->chave;
    return 1;
}

int insereinicio_deque (Deque *dq, int valor) {
    // se o deque não tiver sido alocado retorna 0
    if (dq == NULL)
        return 0;
    Nodo *nodo = (Nodo *) malloc (sizeof (Nodo));
    // se ocorreu erro com a alocação de nodo, retorna 0
    if (nodo == NULL)
        return 0;
    nodo->chave = valor;
    nodo->prox = dq->inicio;
    nodo->ant = NULL;
    if (dq->qtd == 0)
        dq->final = nodo;
    else    
        dq->inicio->ant = nodo;
    dq->inicio = nodo;
    dq->qtd++;
    return 1;
}

int inserefinal_deque (struct Deque *dq, int valor) {
    if (dq == NULL)
        return 0;
    Nodo *nodo = (Nodo *) malloc (sizeof (Nodo));
    if (nodo == NULL)
        return 0;
    nodo->chave = valor;
    nodo->prox = NULL;
    nodo->ant = dq->final;
    if (dq->qtd == 0)
        dq->inicio = nodo;
    else    
        dq->final->prox = nodo;
    dq->final = nodo;
    dq->qtd++;
    return 1;
}

int removeinicio_deque (struct Deque *dq, int *valor) {
    if (dq == NULL)
        return 0;
    if (dq->qtd == 0)
        return 0;
    *valor = dq->inicio->chave;
    Nodo *nodo = dq->inicio;
    dq->inicio = dq->inicio->prox;
    if (dq->inicio == NULL) // se o deque ficou vazio
        dq->final = NULL;
    else    
        dq->inicio->ant = NULL;
    free (nodo);
    dq->qtd--;
    return 1;
}

int removefinal_deque (struct Deque *dq, int *valor) {
    if (dq == NULL)
        return 0;
    if (dq->qtd == 0)
        return 0;
    *valor = dq->final->chave;
    Nodo *nodo = dq->final;
    dq->final = dq->final->ant;
    if (dq->final == NULL) //se o deque ficou vazio
        dq->inicio = NULL;
    else    
        dq->final->prox = NULL;
    free (nodo);
    dq->qtd--;
    return 1;
}

void imprime_deque (struct Deque *dq) {
    Nodo *ptr = dq->inicio;
    while (ptr != NULL) {
        printf ("%d ", ptr->chave);
        ptr = ptr->prox;
    }
}


