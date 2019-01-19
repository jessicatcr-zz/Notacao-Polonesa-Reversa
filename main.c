/*******************************************************************************
 * main.c                                                                      *
 * Propósito: Fazer a leitura da expressão e seu respectivo resultado e        *
 * a partir disso, usando o módulo resolução, gerar as possíveis soluções      *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 22/04/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include "resolucao.h"

/******************************************************************************* 
* Função: Lê a entrada e resolve para que imprima as soluções possíveis        *
* Entrada: Expressao com números e '?'; resultado da expressao                 *
* Saída: Todas as possibilidades de operandos que satisfaz a expressão inicial *
*******************************************************************************/
int main(void){
    char expressao[201];
    int resultado;

    scanf("%200[^\n]", expressao);
    scanf("%d", &resultado);

    //printf("%s\n", expressao);
    //printf("%d\n", resultado);

    resolve(expressao, resultado);

    return 0;
}