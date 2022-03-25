// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : TAD Pilha - (pilha.h) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct pilha Pilha;

Pilha* pilha_cria(void);
int pilha_vazia(Pilha *p);
void pilha_push(Pilha *p, int info);
int pilha_pop(Pilha *p);
void pilha_imprime(Pilha *p);
void pilha_libera(Pilha *p);

// Q2 - Item a)
Pilha* inverte_pilha(Pilha* p);

// Q2 - Item b)
Pilha* empilha_elem_comuns(Lista* l1, Lista* l2);