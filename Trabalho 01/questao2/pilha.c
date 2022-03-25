// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : Implementação Pilha - (pilha.c) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "pilha.h"
#define MAXN 3

struct pilha {
    Lista *prim;
};

struct lista {
    int info;
    Lista *prox;
};

Pilha* pilha_cria(void) {
    Pilha *p = (Pilha*) malloc(sizeof(Pilha));
    if(p == NULL){
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }
    p -> prim = NULL;
    return p;
}

void pilha_push(Pilha *p, int info) {
    Lista *l = (Lista*) malloc(sizeof(Lista));
    if (l == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    l -> info = info;
    l -> prox = p -> prim;
    p -> prim = l;
}

int pilha_vazia(Pilha *p) {
    return p -> prim == NULL;
}

int pilha_pop(Pilha *p) {
    int a;
    Lista *l;
    if (pilha_vazia(p)) {
        printf("Pilha Vazia!!!\n");
        exit(1);
    }

    l = p->prim;
    a = l->info;
    p->prim = l->prox;
    free(l);
    return a;
}

void pilha_imprime(Pilha *p) {
    Lista *lAux = p -> prim;
    while (lAux != NULL) {
        printf("%d\n", lAux -> info);
        lAux = lAux -> prox;
    }
}

void pilha_libera(Pilha *p) {
    Lista* l = p->prim;
    Lista* lAux;
    while (l != NULL) {
        lAux = l->prox;
        free(l);
        l = lAux;
    }
    free(p);
}

Pilha* inverte_pilha(Pilha* p) {
    Pilha* resposta = pilha_cria();
    Lista* lAux = p -> prim;
    while (lAux != NULL) {
        int valor = lAux->info;
        pilha_push(resposta, valor);
        lAux = lAux -> prox;
    }

    return resposta;
}

Pilha* empilha_elem_comuns(Lista* l1, Lista* l2) {
    Lista* intersecao = lst_intersec(l1, l2);
    Lista* listaAuxiliar = intersecao;
    Pilha* resposta = pilha_cria();

    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        pilha_push(resposta, valor);
        listaAuxiliar = listaAuxiliar -> prox;
    }

    return resposta;
}