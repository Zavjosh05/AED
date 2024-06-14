#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
int comportamientOnda(int,int);
void arbolOnda(int,int,int,int);

void presentacion(int);

int main(void)
{
    int p, base;
    unsigned int x;

    presentacion(5);

    puts("Ingresar la base del arbol");
    scanf("%d",&base);
    puts("Ingrese la profundidad del arbol (nivel desde 0 hasta n)");
    scanf("%d",&p);
    puts("Ingrese la magnitud incial de la onda");
    scanf("%d",&x);

    arbolOnda(base,0,p,x);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Primer examen de estructura de datos");
    printf("Ejercicio No. %d\n\n", n);
}

int comportamientOnda(int val,int base)
{
    int x;

    #ifdef NDEBUG
        srand(time(NULL));
    #endif

    x = rand()%3;

    if(x > 0)
        return val/base;
    else return 0;//esta opcion significa que la onda choco con algun objeto
}

void arbolOnda(int base, int lvl,int Lmax, int val)
{
    int i,j,x;

    if(lvl == 0)
    {
        printf("Nivel: 0, Nodo: 0, Valor: %d\n",val);
        arbolOnda(base,++lvl,Lmax,val);
    }

    if(lvl <= Lmax)
        for(i = 0; i < base; i++)
        {
            x = comportamientOnda(val,base);
            for(j = 0; j < lvl; j++)
                putchar('\t');
            printf("Nivel: %d, Nodo: %d, Valor: %d\n",lvl,i,x);
            if(x != 0)
                arbolOnda(base, lvl+1, Lmax,x);
        }
}