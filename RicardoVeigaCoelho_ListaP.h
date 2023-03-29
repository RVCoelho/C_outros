/*  ATIVIDADE ListaP  */
/* Arquivo: RicardoVeigaCoelho_ListaP.h
   Autor: GABRIEL CAVALCANTI FRANCISCO
          RICARDO VEIGA COELHO
   Date: 20/04/2022 19:02
   Descrição:  Implementação de métodos do tipo list da linguagem Python.
*/

#define Max 50
typedef struct{
    int tam;
    unsigned char vetor[Max];
}ListaP;

ListaP newL(){
    ListaP L;
    L.tam=0;
    return L;
}

void append(ListaP *ap, char ch) {
    ap->tam += 1;
    ap->vetor[ap->tam] = ch;
}

void clear(ListaP *ap){
    ap->tam=0;
}

ListaP copy(ListaP *ap) {
    ListaP newLista = newL();
    int n;
    n = ap->tam;
    newLista.tam = n;
    if (n > 0) {
        for (int i = 1; i <= n; i++)
        {
            newLista.vetor[i] = ap->vetor[i];
        }
    }
    return newLista;
}

int count(ListaP *ap, char ch){
    int i, cont;
    cont=0;
    if(ap->tam!=0){
        for(i=0;i<ap->tam;i++){
            if(ap->vetor[i]==ch)
                cont++;
        }
    }
    else cont=0;
    return cont;
}

ListaP extend(ListaP *A, ListaP *B) {
    int i, j;
    ListaP C = newL();
    for (i = 1; i <= A->tam; i++)
    {
        C.vetor[i] = A->vetor[i];
        C.tam++;
    }
    for (j = 1; j <= B->tam+1; j++)
    {
        C.vetor[j+i] = B->vetor[j];
        C.tam++;
    }
    return C;
}

int index(ListaP *ap, char ch){
    int i;
    i=0;
    if(ap->tam!=0){
        while(ap->vetor[i]!=ch)
            i++;
    }
    return i;
}

void insert(ListaP *ap, char val, int pos) {
    if ((ap->tam > 0) && (pos < Max))
    {
        int tam = ap->tam;
        int i, j;  i = tam+1;
        ap->tam += 1;
        for (j=tam; j >= pos+1; j--)
        {
            ap->vetor[i] = ap->vetor[j];
            i--;
        }
        ap->vetor[pos+1] = val;
    }
}

int len(ListaP *ap){
    return ap->tam;
}

char max(ListaP *ap) {
    int max = -1;
    if (ap->tam > 0)
    {
        max = ap->vetor[1]; int i;
        for (i = 2; i <= ap->tam; i++)
        {
            if (ap->vetor[i] > max) max = ap->vetor[i];
        }
    }
    return max;
}

char min(ListaP *ap){
    int min = -1;
    if (ap->tam > 0)
    {
        min = ap->vetor[1]; int i;
        for (i = 2; i <= ap->tam; i++)
        {
            if (ap->vetor[i] < min) min = ap->vetor[i];
        }
    }
    return min;
}

void pop(ListaP *ap, int pos) {
    int tam = ap->tam; int i;
    if (tam > 0)
    {
        for (i = pos; i <= tam; i++)
        {
            ap->vetor[i] = ap->vetor[i+1];
        }
        ap->tam = ap->tam - 1;
    }
}

void remover(ListaP *ap, char ch){
    int i, j;
    i=0;
    if(ap->tam>0){
        while(ap->vetor[i]!=ch) i++;
        for(j=i;j<ap->tam;j++)
            ap->vetor[j]=ap->vetor[j+1];
        ap->tam--;
    }
}

void reverse(ListaP *ap){
    int i, j;
    if (ap->tam > 0)
    {
        ListaP aux = newL();
        j = ap->tam;
        for (i = 1; i <= ap->tam; i++)
        {
            aux.tam = aux.tam + 1;
            aux.vetor[i] = ap->vetor[j];
            j--;
        }
        
        for (i = 1; i <= ap->tam; i++)
        {
            ap->vetor[i] = aux.vetor[i];
        }
    }
}

void sort(ListaP *ap){
    int i, j, aux;
    for(i=2;i<=ap->tam;i++){
        aux=ap->vetor[i];
        j=i-1;
        while(j>0 && ap->vetor[j]>aux){
            ap->vetor[j+1]=ap->vetor[j];
            j--;
        }
        ap->vetor[j+1]=aux;
    }
}

void mostrarLista(ListaP *ap){
     int n,i;
     n = ap->tam;
     printf("tamanho da lista = %d \n",n);
     if(n==0)printf("\n lista vazia\n");
     else{
        for(i=1;i<=n;i++){ printf(" %c ",ap->vetor[i]);}
        printf("\n");
     }
}
