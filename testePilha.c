/* Teste pilha de inteiros */
/*
  Arquivo: testePilha.c
  Autor: Lisbete Madsen Barbosa
  Date: 11/10/09 10:58
  Descrição: Executa testes para o header Pilha.h
  	que define o tipo Pilha e implementa algumas operações. 
  
*/

#include <stdio.h>
#include "booleano.h"
#include "Ricardo_Pilha.h"

int main (){
    int y;
    bool ok;
    PilhaCh s1;
    criarPilhaVazia();
   	ok = verificarPilhaVazia(s1); printf("\n\npilha vazia = %d \n\n\n", ok);
   	 
    pushPilha(s1,1);

    pushPilha(s1,2);

    pushPilha(s1,3);
    
	y = acessarTopo(s1);  printf("item topo pilha s1 = %d \n\n", y); popPilha(s1);
    y = acessarTopo(s1);  printf("item topo pilha s1 = %d \n\n", y); popPilha(s1);
    
	pushPilha(s1,4);

    y = acessarTopo(s1);  printf("item topo pilha s1 = %d \n\n", y); popPilha(s1);
    y = acessarTopo(s1);  printf("item topo pilha s1 = %d \n\n", y); popPilha(s1);
    
	ok = verificarPilhaCheia(s1); printf("\npilha cheia = %d \n", ok);
     
    return 0;
}