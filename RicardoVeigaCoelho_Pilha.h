/*  ATIVIDADE PILHA  */
/* Arquivo: RicardoVeigaCoelho_PILHA.h
   Autor: GABRIEL CAVALCANTI FRANCISCO
          RICARDO VEIGA COELHO
   Date: 21/04/2022 20:03
   Descrição:  implementacao de funcoes de construcao, de acesso e de manipulacao de pilhas
*/

//diretivas
#include <stdio.h>
#include "booleano.h"
#define MaxPilha 50
#define sinal 0
#define fantasma '$'
typedef struct {
    int topo;
    unsigned char tabela[MaxPilha];
} Pilha;

//interface
void criarPilha(Pilha *);//entrada: endereço da variável pilha a ser criada. saída: não há
unsigned char acessarTopo(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: caracter do topo da pilha de entrada
bool verificarPilhaVazia(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: true(pilha vazia) ou false(pilha não vazia)
bool verificarPilhaCheia(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: true(pilha cheia) ou false(pilha não cheia)
int obterProfundidade(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: profundidade da pilha(igual ao topo)
void mostrarPilha(Pilha *);//entrada: endereco da variavel do tipo pilha. saída:
void pushPilha(Pilha *, char);//entrada: endereco da variavel do tipo pilha e o caracter a ser colocado no topo dela. saída: não há
void popPilha(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: não há
void inverterPilha(Pilha *);//entrada: endereco da variavel do tipo pilha. saída: não há
void copiarPilha(Pilha *, Pilha *);//1ª entrada: enderaço da variável do tipo pilha a qual será copiada, 2ª entrada: enderaço da variável do tipo pilha onde a primeira vai ser copiada. saída: não há
void esvaziarPilha(Pilha *);//entrada: enderaço da variável do tipo pilha a qual será esvaziada. saída: não há

//implementacao
void criarPilha(Pilha *ap){
    ap->topo=sinal;
    ap->tabela[0]=MaxPilha-1;
}

unsigned char acessarTopo(Pilha *ap){
    char ch;
    if(verificarPilhaVazia(ap)!=true)
        ch = ap->tabela[ap->topo];
    return ch;
}

bool verificarPilhaVazia(Pilha *ap){
    if(ap->topo==sinal) return true;
    else return false;
}

bool verificarPilhaCheia(Pilha *ap){ 
    if(ap->topo==MaxPilha-1) return true;
    else return false;
}

int obterProfundidade(Pilha *ap){
    return ap->topo;
}

void mostrarPilha(Pilha *ap){
    int i, n;
    n=obterProfundidade(ap);
    //printf("Tamanho da pilha: %d\n", n);
    if(verificarPilhaVazia(ap)) printf("Pilha vazia\n");
    else{
        for(int i=1;i<=n;i++)
            printf("%c ", ap->tabela[i]);
        printf("\n");
    }
}

void pushPilha(Pilha *ap, char ch){
    if(verificarPilhaCheia(ap)!=true){
        ap->topo+=1;
        ap->tabela[ap->topo]=ch;
    }
}

void popPilha(Pilha *ap){
    if(verificarPilhaVazia(ap)!=true) ap->topo--;
}

void inverterPilha(Pilha *ap){
    Pilha aux1, aux2;
    char ch;
    int i;
    criarPilha(&aux1);
    criarPilha(&aux2);

    if(verificarPilhaVazia(ap)!=true){
        //passar todos os elemenots da pilha original para aux1 (que estara invertida)
        i = obterProfundidade(ap);
        for(i;i>=1;i--){
            ch=acessarTopo(ap);
            pushPilha(&aux1, ch);
            popPilha(ap);
        }
        //passar todos os elemenots da pilha aux1 para a aux2 (que estara igual a pilha original no comeco da funcao)
        i = obterProfundidade(&aux1);
        for(i;i>=1;i--){
            ch=acessarTopo(&aux1);
            pushPilha(&aux2, ch);
            popPilha(&aux1);
        }
        //passar todos os elemenots da pilha aux2 para a original (que estara invertida)
        i = obterProfundidade(&aux2);
        for(i;i>=1;i--){
            ch=acessarTopo(&aux2);
            pushPilha(ap, ch);
            popPilha(&aux2);
        }
    }
}

void copiarPilha(Pilha *ap1, Pilha *ap2){
    Pilha aux; 
    criarPilha(&aux);
    char ch;
    //primeiro, esvaziar a segunda pilha
    esvaziarPilha(ap2);
    while(verificarPilhaVazia(ap1)!=true){
        //pilha auxiliar recebe a pilha de ap1 (invertida)
        ch=acessarTopo(ap1);
        pushPilha(&aux, ch);
        popPilha(ap1);
    }
    while(verificarPilhaVazia(&aux)!=true){
        //as pilhas ap1 e ap2 recebem a pilha auxiliar (inverte novamente, fazendo com que as duas pilhas fiquem iguais a pilha ap1 do inicio da funcao)
        ch=acessarTopo(&aux);
        pushPilha(ap1, ch);
        pushPilha(ap2, ch);
        popPilha(&aux);
    }
}

void esvaziarPilha(Pilha *ap){
    //ap->topo=sinal; 
    while(verificarPilhaVazia(ap)!=true) popPilha(ap);
}