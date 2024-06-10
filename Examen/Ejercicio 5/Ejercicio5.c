#include<stdio.h>

typedef struct nodo
{
    int nivel;
    int num;
    int valor;
} *Nodo,SNodo;

int main(void)
{


    return 0;
}

void arbol(Nodo nod, int base, int lvl,int Lmax)
{
    int i;

    if(lvl <= Lmax)
        for(i = 0; i < base; i++)
        {
            
            arbol(++nod, base, ++lvl, Lmax);
        }
}