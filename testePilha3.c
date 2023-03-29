#include "Pilha.h"

int main(){
    Pilha P;
    P=criarPilha();
    P=pushPilha(P, 'b');
    P=pushPilha(P, 'd');
    P=pushPilha(P, 'e');
    P=pushPilha(P, 'k');
    P=pushPilha(P, 'v');
    P=pushPilha(P, 'y');
    P=pushPilha(P, 'f');
    P=pushPilha(P, 'c');
    
    mostrarPilha(P);
    P=inverter(P, 4);
    mostrarPilha(P);
    return 0;
}