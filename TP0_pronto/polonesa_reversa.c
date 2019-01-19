/*******************************************************************************
 * polonesa_reversa.c                                                          *
 * Propósito: Simular o cálculo de uma calculadora polonesa reversa, fazendo   *
 * uso da estrutura pilha.                                                     *
 * @author Jéssica Taís C. Rodrigues                                           *
 * @version 1.0 22/04/2017                                                     *
 ******************************************************************************/

#include <stdlib.h>
#include "pilha.h"
#include "polonesa_reversa.h"

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
int calculaExp(char *expressao, int resultado){
    int i = 0, resultadoExp, *valor, *valor1, *valor2;
    Pilha *p = inicializaPilha();

    int resultadoValido = 1;
    while(expressao[i] != '\0' && resultadoValido){
        if(expressao[i] != ' '){
            valor = malloc(sizeof(int));

            if(expressao[i] == '+' || expressao[i] == '*'){
                valor1 = desempilha(p);
                valor2 = desempilha(p);
                if(expressao[i] == '+'){
                    *valor = *valor1 + *valor2;
                }else{
                    *valor = *valor1 * *valor2;
                }
                free(valor1);
                free(valor2);
                if(*valor > resultado){
                    resultadoValido = 0;
                }
                i++;
            }else{
                *valor = atoi(&expressao[i]);
                while(expressao[i] != ' ') i++; //Acha o próximo espaço
            }
            empilha(p, valor);
        }else{
            i++;
        }
    }
    if(!resultadoValido){
        resultadoExp = 0;
        while(!pilhaVazia(p)){
            valor = desempilha(p);
            free(valor);
        }
    }else{
        valor = desempilha(p);
        resultadoExp = *valor;
        free(valor);
    }
    liberaPilha(p);
    return resultadoExp;
}

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
/*int compPilhaResultado(Pilha *expPilha, int resultado, int *resValido){
    char tipo;
    int valorTermo, valor1, valor2, resOp = 0;
    Termo *termo;

    if(!(*resValido)){
        return 0;
    }

    termo = desempilha(expPilha);
    tipo = termo->tipo;
    valorTermo = termo->valor;

    free(termo);

    if(tipo == TIPO_NUM){
        if(valorTermo > resultado){
            *resValido = 0;
        }
        return valorTermo;
    }else{
        valor1 = compPilhaResultado(expPilha, resultado, resValido);
        valor2 = compPilhaResultado(expPilha, resultado, resValido);
        if(*resValido){    
            if(valorTermo == '+'){
                resOp = valor1+valor2;
            }else if(valorTermo == '*'){
                resOp = valor1*valor2;
            }
        }
        if(resOp <= resultado){
            return resOp;
        }else{
            *resValido = 0;
            return resOp;
        }
    }
}*/

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
/*int compResultado(char *expressao, int resultado){

    int resPilha, resValido = 1, eIgual;
    Pilha *expPilha;

    expPilha = inicializaPilha();  
    constroiPilhaExp(expressao, expPilha);

    resPilha = compPilhaResultado(expPilha, resultado, &resValido);
    
    if(!resValido){
        Termo *termo;
        while(!pilhaVazia(expPilha)){
            termo = desempilha(expPilha);
            free(termo);
        }
    }
    liberaPilha(expPilha);
    
    eIgual = resValido && (resPilha == resultado);

    return eIgual;

}*/

/******************************************************************************* 
* Função:                                                                      *
* Entrada:                                                                     *
* Saída:                                                                       *
*******************************************************************************/
int compResultado(char *expressao, int resultado){
    return calculaExp(expressao, resultado) == resultado;
}