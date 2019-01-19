/*******************************************************************************
 * pilha.c                                                                     *
 * Propósito: Criar operações básicas a serem realizadas em uma pilha          *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 22/04/2017                                                     *
 ******************************************************************************/

#include <stdlib.h>
#include "pilha.h"

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
Pilha *inicializaPilha(void){
    Pilha *p;
    p = malloc(sizeof(Pilha));
    if(p != NULL){
        p->topo = NULL;
    }
    return p;
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
int pilhaVazia(Pilha *p){
    return (p->topo == NULL);
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void empilha(Pilha *p, void *item){
    Celula *novaCelula;
    novaCelula = malloc(sizeof(Celula));
    if(novaCelula != NULL){
        novaCelula->item = item;
        novaCelula->abaixo = p->topo;
        p->topo = novaCelula;
    }
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void *desempilha(Pilha *p){
    void *item = NULL; //Para caso a pilha esteja vazia
    if(!pilhaVazia(p)){
        item = p->topo->item;
        Celula *aux;
        aux = p->topo->abaixo;
        free(p->topo);
        p->topo = aux;
    }
    return item;
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void liberaPilha(Pilha *p){
    if(pilhaVazia(p)){
        free(p);
    }
}