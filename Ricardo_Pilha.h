/*
  Arquivo: Ricardo_Pilha.h
  Autores: Ricardo veiga Coelho
  Date: 01/04/2022 7:56
  Descrição: Este programa e a implementa as funcoes de manipulacao de pilha
*/

//estruturas de dados
//#include "booleano.h"
#define MaxPilha 10
#define sinal 0
#define ghost 36 
typedef struct{
    int topo;
    unsigned char Vetor[MaxPilha];
}PilhaCh;

//interface
PilhaCh criarPilha();//cria uma pilha(vazia)
//bool PilhaVazia(PilhaCh);//checa se a pilha esta vazia
unsigned char acessarPilha(PilhaCh);//mostra o elemento da pilha que esta no topo
PilhaCh pushPilha(PilhaCh,unsigned char);//adiciona um elemento no topo da pilha
PilhaCh popPilha(PilhaCh);//remove o ultimo elemento da pilha
PilhaCh esvaziarPilha(PilhaCh);//"remove" todos os elementos da pilha (topo recebe 0)

//implementacao
PilhaCh criarPilha(){
    PilhaCh p;
    p.topo = sinal;
    p.Vetor[MaxPilha]= MaxPilha-1;
    return p;
}

/*bool PilhaVazia(PilhaCh p){
    if(p.topo=sinal) return true;
    else return false;
}*/

unsigned char acessarPilha(PilhaCh p){
    int S;
    unsigned char c;
    if(p.topo!=sinal){
        S=p.topo;
        c = p.Vetor[S];
    }
    else return ghost;
    return c;
}

PilhaCh pushPilha(PilhaCh p, unsigned char c){
    if(p.topo!=p.Vetor[0]){ 
        p.topo++;
        p.Vetor[p.topo]=c;
    }
    return p;
}

PilhaCh popPilha(PilhaCh p){
    p.topo--;
}

PilhaCh esvaziarPilha(PilhaCh p){
    p.topo=sinal;

}