#include <stdio.h>
#include "RicardoVeigaCoelho_Pilha.h"
#include "booleano.h"

int main(){
    Pilha P;
    criarPilha(&P);
    pushPilha(&P, 'x');
    pushPilha(&P, 'm');
    pushPilha(&P, 'h');
    pushPilha(&P, 'u');
    pushPilha(&P, 'a');
    pushPilha(&P, 'o');
    printf("Pilha: ");
    mostrarPilha(&P);
	printf("\n");

    char c;
    c = acessarTopo(&P);
    printf("Ultimo elemento da pilha: %c\n", c);
	printf("\n");

    bool q;
    q=verificarPilhaVazia(&P);
    printf("vazia(0=false, 1=true)? %d\n", q);
    q=verificarPilhaCheia(&P);
    printf("cheia(0=false, 1=true)? %d\n", q);
	printf("\n");

    int tam = obterProfundidade(&P);
    printf("profundidade da pilha: %d\n",tam);
	printf("\n");
	
    popPilha(&P);
    printf("Pilha sem ultimo elemento:");
    mostrarPilha(&P);
	printf("\n");

    inverterPilha(&P);
    printf("Pilha invertida: ");
    mostrarPilha(&P);
	printf("\n");

    Pilha P2;
    criarPilha(&P2);
    copiarPilha(&P, &P2);
    printf("Pilha copiada(P2): ");
    mostrarPilha(&P2);
	printf("\n");

    esvaziarPilha(&P);
    printf("Pilha vazia: ");
    mostrarPilha(&P);
}