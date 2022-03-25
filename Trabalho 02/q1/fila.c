// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sa Junior
// Descricao       : Implementacao Fila - (fila.c) - Trabalho 02
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 17/08/2021

#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"
#include "fila.h"
#define N 100000

typedef struct fila {
    int n;
    int ini;
    ArvB* v[N];
} Fila;

Fila* fila_cria(void) {
    Fila *f = (Fila*) malloc(sizeof(Fila));
    if (f == NULL) {
        printf("Memoria insuficiente!!!\n");
        exit(1);
    }

    f -> n = 0;
    f -> ini = 0;
    return f;
}

void fila_insere(Fila *f, ArvB* info) {
    int fim;
    if(f -> n == N) {
        printf("Capacidade da Fila Estourou!!!\n");
        exit(1);
    }
    fim = (f -> ini + f->n) % N;
    f -> v[fim] = info;
    f -> n++;
}

int fila_vazia(Fila *f){
    return f -> n == 0;
}

ArvB* fila_remove(Fila *f) {
    ArvB* a;
    if (fila_vazia(f)) {
        printf("Fila Vazia!!!\n");
        exit(1);
    }
    a = f -> v[f -> ini];
    f -> ini = (f -> ini + 1) % N;
    f -> n--;
    return a;
}

void fila_imprime(Fila *f){
    int i;
    int k;
    for (i = 0; i < (f -> n); i++) {
        k = (f -> ini + i) % N;
        arvb_imprime(f -> v[k]);
        // printf("%d\n", f -> v[k]);
    }
}

void fila_libera(Fila* f) {
    free(f);
}

int fila_tamanho(Fila* f) {
    return f -> n;
}

ArvB* fila_frente(Fila* f) {
    ArvB* a = f -> v[f -> ini];
    return a;
}
