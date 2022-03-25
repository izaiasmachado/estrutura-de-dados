// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : Implementação Fila 1 - (fila1.c) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>
#include "fila1.h"
#define N 100000

typedef struct fila {
    int n;
    int ini;
    int v[N];
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

void fila_insere(Fila *f, int info) {
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

int fila_remove(Fila *f) {
    int a;
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
        printf("%d\n", f -> v[k]);
    }
}

void fila_libera(Fila *f) {
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
    int i;
    int k;
    int sum = 0;
    for (i = 0; i < (f -> n); i++) {
        k = (f -> ini + i) % N;
        int valor = f -> v[k];
        if (ehPrimo(valor)) sum++;
    }

    return sum;
}

// Item b)
Fila* inverte_fila(Fila* f) {
    Fila* resposta = fila_cria();
    int i;
    int k;
    for (i = (f -> n) - 1; i >= 0; i--) {
        k = (f -> ini + i) % N;
        int valor = f -> v[k];
        fila_insere(resposta, valor);
    }

    return resposta;
}