#include "Fila.h"

int main(){
    Fila F;
    F=criarFilaVazia();
    F=pushFila(F, 8);
    F=pushFila(F, 1);
    F=pushFila(F, 5);
    F=pushFila(F, 3);
    F=pushFila(F, 6);
    mostrarFila(F);
    return 0;
}