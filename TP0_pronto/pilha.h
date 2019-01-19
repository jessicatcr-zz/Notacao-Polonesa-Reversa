/*******************************************************************************
 * pilha.h                                                                     *
 * Propósito: Estruturar o tipo pilha com suas respectivas operações           *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 22/04/2017                                                     *
 ******************************************************************************/

#ifndef _PILHA_H_
#define _PILHA_H_

typedef struct celula {
    void *item; //Item de qualquer tipo
    struct celula *abaixo;
} Celula;

typedef struct pilha {
    Celula *topo;
} Pilha;

Pilha *inicializaPilha(void);
int pilhaVazia(Pilha *p);
void empilha(Pilha *p, void *item);
void *desempilha(Pilha *p);
void liberaPilha(Pilha *p);


#endif