// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : Implementação Fila 2 - (fila2.c) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>
#include "fila2.h"
#include "lista.h"

typedef struct lista Lista;
typedef struct fila Fila;

struct lista {
    int info;
    Lista *prox;
};

struct fila {
    Lista *ini;
    Lista *fim;
};

Fila* fila_cria(void) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }
    
    f -> ini = NULL;
    f -> fim = NULL;
    return f;
}

void fila_insere(Fila *f, int info) {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    l -> info = info;
    l -> prox = NULL;

    if(!fila_vazia(f)) {
        f -> fim -> prox = l;
    } else {
        f -> ini = l;
    }
    
    f -> fim = l;
}

int fila_vazia(Fila *f) {
    return f -> ini == NULL;
}

int fila_remove(Fila *f) {
    Lista *l; 
    int a;
    
    if (fila_vazia(f)) {
        printf("Fila Vazia!!!\n");
        exit(1);
    }

    a = f -> ini -> info;
    l = f -> ini;
    f -> ini = f -> ini -> prox;
    free(l);
    
    if(fila_vazia(f)) {
        f->fim = NULL;
    }

    return a;
}

void fila_imprime(Fila *f) {
    Lista *lAux = f -> ini;
    while(lAux != NULL){
        printf("%d\n", lAux -> info);
        lAux = lAux -> prox;
    }
}

void fila_libera(Fila *f) {
    Lista* l = f -> ini;
    Lista* lAux;
    
    while (l != NULL) {
        lAux = l -> prox;
        free(l);
        l = lAux;
    }

    free(f);
}

// Item a)
int ehPrimo(int n) {
    int i;
    for (i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }

    return (n != 1);
}

int qtd_primos(Fila* f) {
    Lista *lAux = f -> ini;
    int sum = 0;
    while(lAux != NULL){
        int valor = lAux -> info;
        if (ehPrimo(valor)) sum++;
        lAux = lAux -> prox;
    }

    return sum;
}

Fila* invertida;

void percorre_lst_rec (Lista* l) {
    if (lst_vazia(l)) return;
    else {
        percorre_lst_rec(l -> prox);
        int valor = l -> info;
        fila_insere(invertida, valor);
    }
}

Fila* inverte_fila(Fila* f) {
    invertida = fila_cria();
    Lista* lAux = f -> ini;
    percorre_lst_rec(lAux);
    return invertida;
}