#include<stdio.h>

void presentacion(int);
void quickSortInt(int*,int,int);
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

void quickSortInt(int *arr, int n,int pivot)
{
    int *check = arr-1;
    int i, count = -1;

    for(i = 0; i < n; i++)
        if(*(arr + i) <= *(arr+pivot))
        {
            check++;
            count++;
            if(arr+i > check)
                swapInt(arr+i,check);
        }
    if(count > 1)
        quickSortInt(arr,count,count-1);
    if(n-count > 1)
        quickSortInt(check+1,n-count,pivot);
    
}