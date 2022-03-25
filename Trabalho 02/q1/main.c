// Disciplina      : ECO0016 - Estruturas de Dados
// Professor       : Jarbas Joaci de Mesquita Sa Junior
// Descricao       : Questao 1 - (main.c) - Trabalho 02
// Autor(a)        : Izaias Machado Pessoa Neto
// Data de Entrega : 17/08/2021

#include <stdio.h>
#include <stdlib.h>
#include "arvb.h"

int main(void){
    ArvB* arvA = arvb_cria_vazia();    
    arvA=arvb_insere(arvA,33);
    arvA=arvb_insere(arvA,5);
    arvA=arvb_insere(arvA,21);
    arvA=arvb_insere(arvA,4);
    arvA=arvb_insere(arvA,45);
    arvA=arvb_insere(arvA,28);
    arvA=arvb_insere(arvA,3);
    arvA=arvb_insere(arvA,2);
    arvA=arvb_remove(arvA,4);
    printf("Qtd de nos dois filhos %d\n",dois_filhos(arvA));
    printf("Nos igual altura %d\n",nos_igual_altura(arvA));
    printf("Folhas: info com 6 div. %d\n",folhas_ndivp(arvA,6));
    
    ArvB* arvB = arvb_cria_vazia();
    
    arvB=arvb_insere(arvB,8);
    arvB=arvb_insere(arvB,9);
    arvB=arvb_insere(arvB,11);
    
    ArvB* arvC = arvb_cria_vazia();
    
    arvC=arvb_insere(arvC,9);
    arvC=arvb_insere(arvC,8);
    arvC=arvb_insere(arvC,11);
    
    ArvB* arvD = arvb_cria_vazia();
    
    arvD=arvb_insere(arvD,8);
    arvD=arvb_insere(arvD,9);
    arvD=arvb_insere(arvD,11);
    
    printf("------\n");
    impressao_arv_niveis(arvA);
    printf("------\n");
    
    int comp = arv_iguais(arvA,arvB);
    printf("arvores iguais %d\n",comp);
    printf("------\n");
    comp = arv_iguais(arvB,arvC);
    printf("arvores iguais %d\n",comp);
    printf("------\n");
    comp = arv_iguais(arvB,arvD);
    printf("arvores iguais %d\n",comp);
    
    arvb_libera(arvA);
    arvb_libera(arvB);
    arvb_libera(arvC);
    arvb_libera(arvD);

	system("PAUSE");
    return 0;
}