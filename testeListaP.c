#include <stdio.h>
#include "RicardoVeigaCoelho_ListaP.h"

//interface
ListaP newL();
void append(ListaP *, char);
void clear();
ListaP copy(ListaP *);
int count(ListaP *, char);
int index(ListaP *, char);
void insert(ListaP *, char, int);
int len(ListaP *);
char max(ListaP *);
char min(ListaP *);
void pop(ListaP *, int);
void remover(ListaP *, char);
void sort(ListaP *);
void reverse(ListaP *);
void mostrarLista(ListaP *);
int main(){
    ListaP L1;
    L1 = newL();
    append(&L1, 'a');
    append(&L1, 'b');
    append(&L1, 'e');
    append(&L1, 'b');
    append(&L1, 'c');
    append(&L1, 'e');
    append(&L1, 'd');
    append(&L1, 'a');
    mostrarLista(&L1);

    //ListaP L2;
    //L2 = copy(&L1);
    //printf("lista 2:\n");
    //mostrarLista(&L2);

    //int cont = count(&L1,'b');
    //printf("contador: %d\n", cont);

    //ListaP L3;
    //L3 = extend(&L1, &L2);
    //mostrarLista(&L3);

    //int n = index(&L1, 'c');
    //printf("primeira ocorrencia de n: %d", n);

    insert(&L1, 'f', 50);
    mostrarLista(&L1);

    //int i = len(&L1);
    //printf("Tamanho da lista: %d\n", i);

    //char maior = max(&L1);
    //printf("Maior valor: %c\n", maior);

    //char menor = min(&L1);
    //printf("Menor valor: %c\n", menor);

    //pop(&L1, 3);
    //mostrarLista(&L1);

    //remover(&L1, 'd');
    //mostrarLista(&L1);

    //reverse(&L1);
    //mostrarLista(&L1);

    //sort(&L1);
    //mostrarLista(&L1);

    //clear(&L1);
    //mostrarLista(&L1);
    return 0;
}