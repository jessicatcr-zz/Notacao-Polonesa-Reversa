/*******************************************************************************
 * resolucao.c                                                                 *
 * Propósito: Gera os possíveis operadores para a expressão e então a compara  *
 *                                                                             *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 22/04/2017                                                     *
 ******************************************************************************/

#include <stdio.h>
#include <string.h>
#include "polonesa_reversa.h"
#include "resolucao.h"

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void imprimeOperandos(char *exp, int tamExp){
    int i;
    
    for(i = 0; i < tamExp; i++){
        if(exp[i] == '+' || exp[i] == '*'){
            printf("%c", exp[i]);
        }
    }
    printf("\n");
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void expPossivel(char *exp, int tamExp, int resultado, int posAtual){
    if(posAtual == tamExp){
        int eIgual;
        eIgual = compResultado(exp, resultado);
        if(eIgual){
            imprimeOperandos(exp, tamExp);
        }

    }else if(exp[posAtual] == '?' || exp[posAtual] == '+' || exp[posAtual] == '*'){
        exp[posAtual] = '+';
        expPossivel(exp, tamExp, resultado, posAtual+1);
        exp[posAtual] = '*';
        expPossivel(exp, tamExp, resultado, posAtual+1);
    }else{
        while(!(exp[posAtual] == '?' || exp[posAtual] == '+' || exp[posAtual] == '*')){
            posAtual++;
        }
        expPossivel(exp, tamExp, resultado, posAtual);
    }
    
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
void resolve(char *expressao, int resultado){
    expPossivel(expressao, strlen(expressao), resultado, 0);
}
