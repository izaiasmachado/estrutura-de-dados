// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : TAD Lista - (lista.h) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
Lista* lst_cria();
int lst_vazia(Lista *l);
Lista* lst_insere(Lista *l, int info);
Lista* lst_busca(Lista *l, int info);
void lst_imprime(Lista *l);
Lista* lst_remove(Lista *l, int info);
void lst_libera(Lista *l);
Lista* lst_remove_rec(Lista *l, int info);
void lst_imprime_invertida_rec(Lista* l);

// Q1 - Item a)
int menores(Lista* l, int n);

// Q1 - Item b)
int soma(Lista* l);

// Q1 - Item c)
int num_ndivp(Lista* l, int n);

// Q1 - Item d)
Lista* lst_intersec(Lista* l1, Lista* l2);

// Q1 - Item d)
Lista* lst_conc(Lista* l1, Lista* l2);

// Q1 - Item f)
Lista* lst_diferenca(Lista* l1, Lista* l2);