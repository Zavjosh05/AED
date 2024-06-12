#include<stdio.h>

typedef struct nodo
{
    int nivel;
    int num;
    int valor;
} *Nodo,SNodo;

int main(void)
{
    Nodo tree;
    int n;


    return 0;
}

void arregloNodos(Nodo *arr,int n)
{
    *arr = (Nodo)malloc(n*sizeof(SNodo));
}

int arbolNumNodos(int base,int lvl)
{
    return (factorialJ(base,lvl+1)-1)/(base-1);
}

void comportamientoOnda(Nodo av)
{
    int x;

    #ifdef NDEBUG
        srand(time(NULL));
    #endif

    x = rand()%3;
}

void arbol(Nodo nod, int base, int lvl,int Lmax)
{
    int i;

    if(lvl <= Lmax)
        for(i = 0; i < base; i++)
        {
            (nod+i)->nivel = lvl;
            (nod+i)->num = i;
            (nod+i)->valor = ;
            arbol(++nod, base, ++lvl, Lmax);
        }
}