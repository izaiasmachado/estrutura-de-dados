// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sa Junior
// Descricao       : TAD Arvore Binaria - (arvb.h) - Trabalho 02
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 17/08/2021

#include <stdlib.h>
#include <stdio.h>

typedef struct arvb ArvB;

ArvB* arvb_cria_vazia(void);
int arvb_vazia(ArvB* a);
ArvB* arvb_busca(ArvB* a,int c);
void arvb_imprime(ArvB* a);
ArvB* arvb_insere(ArvB* a, int c);
ArvB* arvb_remove(ArvB* a, int c);
void arvb_libera(ArvB* a);
int arvb_altura(ArvB *a);

// Letra a)
int folhas_ndivp(ArvB* a, int n);

// Letra b)
int dois_filhos(ArvB* a);

// Letra c)
int nos_igual_altura(ArvB* a);

// Letra d)
int arv_iguais(ArvB* a, ArvB* b);

// Letra e)
void impressao_arv_niveis(ArvB* a);
