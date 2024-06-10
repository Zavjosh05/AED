#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct avion
{
    int num;
    int piruetas;
    int aterrizaje;
} *Avion, Plane;

void presentacion(int);
Avion arregloAvion(int);
void zeroAviones(Avion,int);
void printAviones(Avion,int);
void lanzamientoAvion(Avion,int);
void vueloAvion(Avion);

int main(void)
{
    Avion paperPlane;
    int n;

    presentacion(2);

    puts("Ingrese el numero de aviones de papel");
    scanf("%d",&n);
    fseek(stdin,0,SEEK_END);

    paperPlane = arregloAvion(n);
    zeroAviones(paperPlane,n);

    puts("Aviones: \n");
    printAviones(paperPlane,n);
    puts("\n\n");

    lanzamientoAvion(paperPlane,n);

    puts("Datos finales de aviones: \n");
    printAviones(paperPlane,n);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Primer examen de estructura de datos");
    printf("Ejercicio No. %d\n\n", n);
}

Avion arregloAvion(int n)
{
    Avion arr;
    int i;

    arr = (Avion)malloc(n*sizeof(Plane));

    for(i = 0; i < n; i++)
    {
        (arr+i)->num = i;
    }

    return arr;
}

void zeroAviones(Avion av,int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        (av+i)->aterrizaje = 0;
        (av+i)->piruetas = 0;
    }
}

void printAviones(Avion arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("Avion: %d\nPiruetas: %d\nZona de aterrizaje: %d\n\n",(arr+i)->num,(arr+i)->piruetas,(arr+i)->aterrizaje);
}

void lanzamientoAvion(Avion arr, int n)
{
    int division, residuo;

    division = n/6;
    residuo = n%6;

    //printf("div: %d\nres: %d\n\n",division,residuo);

    if(division)
    {
        lanzamientoAvion(arr,division);
        lanzamientoAvion(arr+division,division);
        lanzamientoAvion(arr+2*division,division);
        lanzamientoAvion(arr+3*division,division);
        lanzamientoAvion(arr+4*division,division);
        lanzamientoAvion(arr+5*division,division+residuo);
    }
    else
    {
        if(residuo == 0)
            return;
        else
        {
            vueloAvion(arr);
            lanzamientoAvion(arr+1,n-1);
        }  
    }
}

void vueloAvion(Avion av)
{
    int x;

    #ifdef NDEBUG
        srand(time(NULL));
    #endif

    x = rand()%5;

    if(x > 2)
    {
        av->piruetas++;
        vueloAvion(av);
    }
    else
        av->aterrizaje = x+1;
}