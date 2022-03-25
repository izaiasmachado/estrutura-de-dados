// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sá Júnior
// Descrição       : TAD Fila 1 - (fila1.h) - Trabalho 01
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 08/07/2021

#include <stdio.h>
#include <stdlib.h>

typedef struct fila Fila;
Fila* fila_cria(void);
int fila_vazia(Fila *f);
void fila_insere(Fila *f, int info);
int fila_remove(Fila *f);
void fila_imprime(Fila *f);
void fila_libera(Fila *f);

// Q3 - Item a)
int qtd_primos(Fila* f);

// Q3 - Item b)
Fila* inverte_fila(Fila* f);