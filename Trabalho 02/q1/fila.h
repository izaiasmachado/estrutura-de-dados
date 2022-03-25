// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sa Junior
// Descricao       : TAD Fila - (fila.h) - Trabalho 02
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 17/08/2021

#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

typedef struct fila Fila;
Fila* fila_cria(void);
int fila_vazia(Fila *f);
void fila_insere(Fila *f, ArvB* info);
ArvB* fila_remove(Fila *f);
void fila_imprime(Fila *f);
void fila_libera(Fila *f);
int fila_tamanho(Fila* f);
ArvB* fila_frente(Fila* f);
