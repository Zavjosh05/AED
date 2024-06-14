#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
void quickSortInt(int*,int);
void swapInt(int*,int*);
int* crearArreglo(int);
void fillZeroArr(int*,int);
void llenarAleatoriamenteArreglo(int*,int);
void liberarArreglo(int**);
void printArreglo(int*,int);

int main(void)
{
    int *arr;
    int n;

    presentacion(4);

    puts("Ingresar extension del arreglo");
    scanf("%d",&n);

    arr = crearArreglo(n);
    fillZeroArr(arr,n);
    llenarAleatoriamenteArreglo(arr,n);
    printArreglo(arr,n);

    quickSortInt(arr,n-1);

    puts("Arreglo ordenado:");
    printArreglo(arr,n);


    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Primer examen de estructura de datos");
    printf("Ejercicio No. %d\n\n", n);
}

int* crearArreglo(int n)
{
    return (int*)malloc(n*sizeof(int));
}

void fillZeroArr(int *arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
        *(arr+i) = 0;
}

void liberarArreglo(int **arr)
{
    free(*arr);

    *arr = NULL;
}

void printArreglo(int *arr,int n)
{
    int i;

    for(i = 0; i < n; i++)
        printf("%d ",*(arr + i));

    putchar('\n');
}

void llenarAleatoriamenteArreglo(int *arr, int n)
{
    int i;

    srand(time(NULL));

    for(i = 0; i < n; i++)
        *(arr + i) = rand() % n;
}

void swapInt(int *a1,int *a2)
{
    int aux;

    aux = *a1;
    *a1 = *a2;
    *a2 = aux;
}

void quickSortInt(int *arr,int pivot)
{
    int *check = arr-1;
    int i, count = -1;

    for(i = 0; i <= pivot; i++)
        if(*(arr + i) <= *(arr+pivot))
        {
            check++;
            count++;
            if(arr+i > check)
                swapInt(arr+i,check);
        }

    if(count > 1)
        quickSortInt(arr,count-1);
    if(pivot-count > 1)
        quickSortInt(++check,pivot-count-1);
}

void quickSort_I(int *arr, int n, int pivot)
{
    
}