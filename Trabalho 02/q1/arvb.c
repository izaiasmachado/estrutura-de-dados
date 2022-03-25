// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sa Junior
// Descricao       : Implementacao Arvore Binaria - (arvb.c) - Trabalho 02
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 17/08/2021

#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct arvb {
    char info;
    ArvB *esq;
    ArvB *dir;
}; 

ArvB* arvb_cria_vazia() {
    return NULL;
}

ArvB* arvb_cria_no(char c, ArvB *sae, ArvB *sad) {
    ArvB* a = (ArvB*) malloc(sizeof(ArvB));
    a -> info = c;
    a -> esq = sae;
    a -> dir = sad;
    return a;
}

int arvb_vazia(ArvB *a) {
    return a == NULL;
}

int arvb_pertence(ArvB *a, char c){
    if (arvb_vazia(a)) {
        return 0;
    }
    
    return a -> info == c || arvb_pertence(a -> esq, c) || arvb_pertence(a -> dir, c);
}

void arvb_libera(ArvB *a) {
    if (!arvb_vazia(a)) {
        arvb_libera(a -> esq);
        arvb_libera(a -> dir);
        free(a);
    }
}

int arvb_altura(ArvB *a) {
    if(arvb_vazia(a)) {
        return -1;
    } 
    
    int hSAE = arvb_altura(a -> esq);
    int hSAD = arvb_altura(a -> dir);
    int h = (hSAE > hSAD) ? hSAE : hSAD;
    return h + 1;
}

ArvB* arvb_busca(ArvB *a, int c){
    if (arvb_vazia(a)) {
        return NULL;
    } else if (a->info < c) {
        return arvb_busca(a -> dir, c);
    } else if (a->info > c) {
        return arvb_busca(a -> esq, c);
    } else {
        return a;
    }
}

void arvb_imprime(ArvB *a){
    if (!arvb_vazia(a)) {
        arvb_imprime(a -> esq);
        printf("%d ", a -> info);
        arvb_imprime(a -> dir);
    }
}

ArvB* arvb_insere(ArvB *a, int c){
    if (arvb_vazia(a)) {
        a = (ArvB*) malloc(sizeof(ArvB)); 
        a -> info = c;
        a -> esq = NULL;
        a -> dir = NULL;
    } else if (a -> info > c) {
        a -> esq = arvb_insere(a -> esq, c);
    } else if (a -> info < c) {
        a -> dir = arvb_insere(a -> dir, c);
    } else {
        printf("\nElemento Ja Pertence a Arvore");
    }
    return a;
}

ArvB* arvb_remove(ArvB *a, int c){
    if (!arvb_vazia(a)) {
        if(a -> info > c) {
            a -> esq = arvb_remove(a -> esq, c);
        } else if (a->info < c) {
            a -> dir = arvb_remove(a -> dir, c);
        } else {
            ArvB* t;
            if (a -> esq == NULL) {
                t = a;
                a = a -> dir;
                free(t);
            } else if (a -> dir == NULL) {
                t = a; 
                a = a -> esq;
                free(t);
            } else {
                t = a -> esq;
                while(t->dir!=NULL) {
                    t = t -> dir;
                }
                a -> info = t -> info;
                t -> info = c;
                a -> esq = arvb_remove(a -> esq, c);
        }
        }
    }
    return a;
}

// Letra a)
int divisores(int n) {
    int i, count = 0;
    for (i = 1; i <= n; i++) {
        if (n % i == 0) count++;
    }

    return count;
}

int folhas_ndivp (ArvB* a, int n) {
    if (arvb_vazia(a)) return 0;

    int valorDoNo = a -> info;
    int divisoresDoNo = divisores(valorDoNo); 
    int divisoresEhIgualAN = (divisoresDoNo == n);
        
    ArvB* noEsquerdo = a -> esq;
    ArvB* noDireito = a -> dir;

    // Retornar apenas se no folha
    if (arvb_vazia(noEsquerdo) && arvb_vazia(noDireito)) return divisoresEhIgualAN;

    // Caso não seja folha, retorna a soma da esquerda e direita
    return folhas_ndivp(noEsquerdo, n) + folhas_ndivp(noDireito, n);
}

// Letra b)
int dois_filhos(ArvB* a) {
    if (arvb_vazia(a)) return 0;

    int valorDoNo = a -> info;
    ArvB* noEsquerdo = a -> esq;
    ArvB* noDireito = a -> dir;

    int temDoisNos = (!arvb_vazia(noEsquerdo) && !arvb_vazia(noDireito));
    int filhosComDoisNos = dois_filhos(noEsquerdo) + dois_filhos(noDireito);

    return temDoisNos + filhosComDoisNos;
}

// Letra c)
int nos_igual_altura(ArvB* a) {
    if (arvb_vazia(a)) return 0;

    ArvB* noEsquerdo = a -> esq;
    ArvB* noDireito = a -> dir;
    
    int alturaNoEsquerdo = arvb_altura(noEsquerdo);
    int alturaNoDireito = arvb_altura(noDireito);

    int temAlturaIgual = (alturaNoEsquerdo == alturaNoDireito);
    int nosFilhosComAlturaIgual = nos_igual_altura(noEsquerdo) + nos_igual_altura(noDireito);

    return temAlturaIgual + nosFilhosComAlturaIgual;
}

// Letra d)
int arv_iguais(ArvB* a, ArvB* b) {
    int aEhVazia = arvb_vazia(a);
    int bEhVazia = arvb_vazia(b);
    
    if (aEhVazia || bEhVazia) return (aEhVazia == bEhVazia);

    int valorArvoreA = a -> info;
    int valorArvoreB = b -> info;

    if (valorArvoreA != valorArvoreB) return 0;

    ArvB* esquerdaA = a -> esq;
    ArvB* direitaA = a -> dir;

    ArvB* esquerdaB = b -> esq;
    ArvB* direitaB = b -> dir;

    return arv_iguais(esquerdaA, esquerdaB) && arv_iguais(direitaA, direitaB);
}

// Letra e)
void impressao_arv_niveis(ArvB* a) {
    if (arvb_vazia(a)) return;
 
    int nivel = 0;
    Fila* f = fila_cria();
    fila_insere(f, a);

    while (!fila_vazia(f)) {
        int contagemDeNos = fila_tamanho(f);

        while (contagemDeNos > 0) {
            ArvB* noAuxiliar = fila_frente(f);
            int valorDoNoAuxiliar = noAuxiliar -> info;
            printf("%d%s", valorDoNoAuxiliar, ((contagemDeNos == 1) ? "" : ", "));
            
            fila_remove(f);
            contagemDeNos--;
            
            ArvB* noEsquerdo = noAuxiliar -> esq;
            ArvB* noDireito = noAuxiliar -> dir;

            if (!arvb_vazia(noEsquerdo)) {
                fila_insere(f, noAuxiliar -> esq);
            }

            if (!arvb_vazia(noDireito)) {
                fila_insere(f, noAuxiliar -> dir);
            }
        }

        printf(" - nivel %d\n", nivel++);
    }
}
