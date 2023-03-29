/*
  Arquivo: Ricardo_Coelho_SORTING.c
  Autores: Ricardo veiga Coelho, Gabriel Cavalcanti Francisco
  Date: 25/03/22 08:07
  Descrição: Este programa determina o tempo de execução de um
  dos algoritmos elementares de ordenação - bolha
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#define Max 150001

typedef struct {
      int tamanho;
      int vetor[Max];
} ListaInt;

//interface
void construirListaAleatoria(ListaInt *,int);
void copiarLista(ListaInt *, ListaInt *);

void mostrarLista(ListaInt *);

void ordenarListaCrescenteS(ListaInt *);
void ordenarListaCrescenteB(ListaInt *);
void ordenarListaCrescenteI(ListaInt *);

int main( ){
      ListaInt a, b, c;
      clock_t start, finish;
	  double pf;
	  printf(" \n\n\nConstruir uma lista com inteiros positivos menores que 150001 ");
      printf("\nTamanho da lista = %d itens", Max-1);    printf(" \n\n\n");
      construirListaAleatoria(&a, Max-1);
      copiarLista(&a, &b);
      copiarLista(&a, &c);
	  //mostrarLista(&a);
	  printf(" \n\n");      printf("    BubbleSort  ");
	  start = clock(); 
	  ordenarListaCrescenteB(&a);
	  finish = clock();
	  //mostrarLista(&a);
      pf = (double)(finish - start)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos ",pf);
	  printf(" \n\n");
	  printf(" \n\n");      printf("    SelectionSort  ");
	  start = clock(); 
	  ordenarListaCrescenteS(&b);
	  finish = clock();
	  //mostrarLista(&b);
      pf = (double)(finish - start)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos ",pf);
	  printf(" \n\n");
	  printf(" \n\n");      printf("    InsertionSort  ");
	  start = clock(); 
	  ordenarListaCrescenteI(&c);
	  finish = clock();
	  //mostrarLista(&c);
      pf = (double)(finish - start)/CLOCKS_PER_SEC;  printf("    elapsed = %f segundos ",pf);
	  printf(" \n\n");
      printf(" \n\n");
      return 0;
}

// implementação

void construirListaAleatoria(ListaInt *ap, int n){
       int i,k,g,a,b;
       if (n > Max-1) n=Max-1;
       ap->tamanho = n;
       a = 1;
       b = 150000;
       double d;
       srand((int) time(NULL));
       for(i=1; i < n+1; i++){
                d = (double)rand()/((double)RAND_MAX +1);
                k = (int)(d*(b-a));
                g = a+k;
                ap->vetor[i] = g;
                };
     }
     
void copiarLista(ListaInt *ap, ListaInt *bp){
     int i,n;
     n = ap->tamanho;
     bp->tamanho = n;
     bp->vetor[0] = ap->vetor[0];
     if (n!=0) for(i=1;i<=n;i++) bp->vetor[i] = ap->vetor[i];
}

void mostrarLista(ListaInt *ap){
     int n,i;
     n = ap->tamanho;
     printf("tamanho da lista = %d \n",n);
     if(n==0)printf("\n lista vazia\n");
     else{
        for(i=1;i<=n;i++){ printf(" %d ",ap->vetor[i]);}
        printf("\n");
     }
}


void ordenarListaCrescenteS(ListaInt *ap){      /* SelectionSort: localizar o menor e colocar no seu lugar */
     int i,j,min,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=1;i<n;i++){                          /* n-1 etapas  */
         min = i;                                                                  /* min = local onde se encontra o menor */
         for(j=i+1;j<=n; j++) if (ap->vetor[j] < ap->vetor[min]) min = j;          /* atualização de min */
         aux = ap->vetor[i]; ap->vetor[i] = ap->vetor[min]; ap->vetor[min] = aux;   /* troca com o menor */
     }
}

void ordenarListaCrescenteB(ListaInt *ap){      /* BubbleSort: trocar pares consecutivos fora da ordem */
     int i,j,fim,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     fim = n-1;
     for(i=1;i<n;i++){                          /* n-1 etapas  */
        for(j=1;j<=fim; j++){                   /* comparar/trocar do primeiro ao penultimo */
            if (ap->vetor[j] > ap->vetor[j+1]){
                 aux = ap->vetor[j]; ap->vetor[j] = ap->vetor[j+1]; ap->vetor[j+1] = aux;
            };
        }
        fim = fim -1;
     }
}

void ordenarListaCrescenteI(ListaInt *ap){      /* InsertionSort - ordenação por inserção */
     int i,k,n,aux;
     n = ap->tamanho;                           /* n = quantidade de elementos da lista */
     for(i=2;i<=n;i++){                         /* n-1 etapas  */
         aux = ap->vetor[i];
         k = i-1;
         while ((k>0) && (ap->vetor[k] > aux)) {ap->vetor[k+1] = ap->vetor[k]; k = k - 1;}  /* desloca */
         ap->vetor[k+1] = aux;                                                              /* insere  */
         }
     }