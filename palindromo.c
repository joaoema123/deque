#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct nodo {
    struct nodo* prox;
    char letra;
};

struct nodo* cria_lista () {
    struct nodo* head = (struct nodo*) malloc(sizeof (struct nodo));
    if (head == NULL) {
        printf ("Erro ao criar lista\n");
        return NULL;
    }
    head->prox = NULL;
    return head;
} 

int insere_fim (struct nodo *head, char letra) {
    struct nodo *temp = head;
    struct nodo *ptr = (struct nodo*) malloc(sizeof (struct nodo));
    if (ptr == NULL)
    {
        printf ("Erro ao alocar o ptr\n");
        return 0;
    }
    ptr->letra = letra;
    ptr->prox = NULL;
    while (temp->prox != NULL)
        temp = temp->prox;
    temp->prox = ptr;
    return 1;
}

int string_to_list(struct nodo *head, char *palavra, int tam) {
    if (head == NULL) {
        return 0;
    }
    for (int i = 0; i < tam; i++) {
        insere_fim (head, palavra[i]);
    }
    return 1;
}

char remove_ini (struct nodo *head, int *tam) {
    if (head == NULL) {
        printf ("A lista está vazia, logo não há elementos para serem retirados\n");
        return 'e';
    }
    char retorno = head->letra;
    struct nodo* temp = head;
    head = head->prox;
    free(temp);
    (*tam)--;
    return retorno;
}

char remove_fim (struct nodo *head, int *tam) {
    if (head == NULL) {
        printf ("O ponteio head vale NULL, logo não há o que retirar\n");
        return 'e';
    }
    struct nodo *temp = head;

        
        if (*tam == 1) {
            char retorno = head->letra;
            free (head);
            return retorno;
        }
        else if (*tam == 2) {
            char retorno = head->prox->letra;
            free (head->prox);
            head->prox = NULL;
            (*tam)--;
            return retorno;
        }
        else {
            while (temp->prox->prox != NULL) 
                temp = temp->prox;
        }
        (*tam)--;
        char retorno = temp->prox->letra;
        free(temp->prox);
        temp->prox = NULL;
        return retorno;
        
}


int eh_palindromo (struct nodo *head, int tam) {
    int limite = tam / 2;
    for (int i = 0; i < limite; i++) {
            if (remove_ini(head, &tam) != remove_fim (head, &tam)) {
                    return 0;
            }
    }
    return 1;
}


int main () {
    char palavra [100];

    printf ("Coloque uma palvra não composta: ");
    scanf ("%s", palavra);

    // calcula o tamanho da string
    int tam = strlen (palavra);
    // cria a lista
    struct nodo* head = cria_lista ();
    // transforma a string em lista
    string_to_list (head, palavra, tam);

    if (eh_palindromo(head, tam)) {
        printf ("Eh palindromo\n");
    }
    else {
        printf ("Não eh palindromo\n");
    }

    

    return 0;
}