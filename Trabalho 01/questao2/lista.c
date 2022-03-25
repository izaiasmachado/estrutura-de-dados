// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : Implementação Lista - (lista.c) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#define MAXN 100000

struct lista {
    int info;
    Lista *prox;
};

Lista* lst_cria() {
    return NULL;
}

int lst_vazia(Lista *l) {
    return (l == NULL);
}

Lista* lst_insere(Lista *l, int info) {
    Lista* ln = (Lista*) malloc(sizeof(Lista));
    ln -> info = info;
    ln -> prox = l;
    return ln;
}

Lista* lst_busca(Lista *l, int info) {
    Lista* lAux = l;
    while (lAux != NULL) {
    if (lAux -> info == info) return lAux;
        lAux = lAux->prox;
    }
    return NULL;
}

void lst_imprime(Lista *l) {
    Lista* lAux = l;
    while (lAux != NULL) {
        printf("Info = %d\n", lAux -> info);
        lAux = lAux -> prox;
    }
}

Lista* lst_remove(Lista *l, int info) { 
    if (l != NULL) {
        Lista* lAux = l-> prox;
        if (l -> info == info) {
            free(l);
            return lAux;
        } else {
            Lista* lAnt = l;
            while (lAux != NULL) {
                if (lAux -> info == info) {
                    lAnt -> prox = lAux -> prox;
                    free(lAux);
                    break;
                } else {
                    lAnt = lAux;
                    lAux = lAux -> prox;
                }
            }
        }
    }

    return l;
}

void lst_libera(Lista* l) {
    Lista* lProx;
    while (l != NULL) {
        lProx = l -> prox;
        free(l);
        l = lProx;
    }
}

Lista* lst_remove_rec(Lista *l, int info) {
    if (!lst_vazia(l) && l -> info == info) {
        Lista* lAux = l;
        l = l -> prox;
        free(lAux);
    } else{
        l -> prox = lst_remove_rec(l -> prox, info);
    }
    return l;
}

void lst_imprime_invertida_rec(Lista* l) {
    if (lst_vazia(l)) return;
    else {
        lst_imprime_invertida_rec(l -> prox);
        printf("Info = %d\n", l -> info);
    }
}

Lista* lst_inverte(Lista* l) {
    Lista* ant = NULL;
    Lista* atual = l;
    Lista* prox = l;
    while(atual != NULL) {
        prox = prox -> prox;
        atual -> prox = ant;
        ant = atual;        
        atual = prox;
    }  

    return ant;
}

// Item a)
int menores(Lista* l, int n) {
    Lista* listaAuxiliar = l;
    int count = 0;

    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        if (valor < n) count++;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    return count;
}

// Item b)
int soma(Lista* l) {
    Lista* listaAuxiliar = l;
    int sum = 0;

    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        sum += valor;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    return sum;
}

// Item c)
int divisores(int n) {
    int i, count = 0;
    for (i = 1; i < n; i++) {
        if (n % i == 0) count++;
    }

    return count;
}

int num_ndivp(Lista* l, int n) {
    Lista* listaAuxiliar = l;
    int count = 0;

    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        int divisoresDoValor = divisores(valor);

        if (divisoresDoValor == n) count++;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    return count;
}

// Item d)
Lista* lst_intersec(Lista* l1, Lista* l2) {
    Lista* listaAuxiliar = l1;
    
    int vec[MAXN + 1];  
    memset(vec, 0, sizeof(MAXN));

    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;

        vec[valor] += 1;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    listaAuxiliar = l2;
    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;

        vec[valor] += 1;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    int i;
    Lista* listaIntesecao = lst_cria();
    
    for (i = 10000; i >= 0; i--) {
        if (vec[i] >= 2) {
            listaIntesecao = lst_insere(listaIntesecao, i);
        };
    }

    return listaIntesecao;
}

// Item e)
Lista* lst_conc(Lista* l1, Lista* l2) {
    Lista* concatenada = lst_cria();
    Lista* listaAuxiliar = l2;
    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        concatenada = lst_insere(concatenada, valor);
        listaAuxiliar = listaAuxiliar -> prox;
    }

    listaAuxiliar = l1;
    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        concatenada = lst_insere(concatenada, valor);
        listaAuxiliar = listaAuxiliar -> prox;
    }

    concatenada = lst_inverte(concatenada);
    return concatenada;
}

// Item f)
Lista* lst_diferenca(Lista* l1, Lista* l2) {
    if (lst_vazia(l1)) {
        return NULL;
    } else if (lst_vazia(l2)) {
        return l1;
    }

    int i = 0;
    int vecA[MAXN + 1], vecB[MAXN + 1];  
    memset(vecA, 0, sizeof(vecA));
    memset(vecB, 0, sizeof(vecB));

    Lista* inicio = l1;
    Lista* listaAuxiliar = l1;
    while (listaAuxiliar != NULL) {
        int valor = listaAuxiliar -> info;
        vecA[valor] = 1;
        listaAuxiliar = listaAuxiliar -> prox;
    }

    Lista* listaAuxiliar2 = l2;
    while (listaAuxiliar2 != NULL) {
        int valor = listaAuxiliar2 -> info;
        vecB[valor] = 1;
        listaAuxiliar2 = listaAuxiliar2 -> prox;
    }

    for (i = MAXN; i >= 0; i--) {
        if (vecA[i] == 1 && vecB[i] == 1) {
            lst_remove(l1, i);
        }
    }

    return inicio;
}