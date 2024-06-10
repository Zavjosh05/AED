#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
void mSortProcess(int*,int,int);
void mergeSort_R(int*,int,int);
void mergeSort_I(int*,int);
int* crearArreglo(int);
void fillZeroArr(int*,int);
void llenarAleatoriamenteArreglo(int*,int);
void liberarArreglo(int**);
void printArreglo(int*,int);

int main(void)
{
    int *arr;
    int n;

    presentacion(3);

    puts("Ingresar el tamaño del arreglo");
    scanf("%d",&n);

    arr = crearArreglo(n);
    fillZeroArr(arr,n);

    llenarAleatoriamenteArreglo(arr,n);
    puts("Arreglo orginal: ");
    printArreglo(arr,n);

    //mergeSort_R(arr,0,n-1);
    mergeSort_I(arr,n);

    puts("Arreglo ordenado por mergesort recursivo: ");
    printArreglo(arr,n);

    liberarArreglo(&arr);

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

void mSortProcess(int *arr, int inf, int sup)
{
    int i,j,k,l = sup-inf, middle;
    int *aux;


    aux = crearArreglo(l+1);
    fillZeroArr(aux,l+1);

    i = inf;
    if(l == 1)
        j = inf + 1;
    else
        j = inf + l/2;
    middle = j;
    k = 0;

    while(k <= l)
    {
        if(i < middle && j <= sup)
        {
            if(*(arr + i) >= *(arr + j))
            {
                *(aux + k) = *(arr + j);
                k++;
                j++;
            }
            else
            {
                *(aux + k) = *(arr + i);
                k++;
                i++;
            }
        }
        else
            if(i < middle)
            {
                *(aux + k) = *(arr + i);
                i++;
                k++;
            }
            else
            {
                *(aux + k) = *(arr + j);
                j++;
                k++;
            }
    }

    for(i = inf, k = 0; k <= l; k++, i++)
        *(arr + i) = *(aux + k);
}

void mergeSort_R(int *arr, int inf, int sup)
{
    int x; 

    if(sup-inf >= 1)
    {
        x = (sup - inf)/2;

        if(sup-inf >= 2)
        {
            mergeSort_R(arr,inf,inf+x-1);
            mergeSort_R(arr,inf+x,sup);
        }
        mSortProcess(arr,inf,sup);
    }     
}

int factorialJ(unsigned int base, unsigned int exponente)
{
    if(exponente == 0)
        return 1;
    else
        return base*factorialJ(base,exponente-1);
}

int arbolBinarioNumNodos(int lvl)
{
    return (factorialJ(2,lvl+1)-1)/1;
}

int numsMiddle(int n)
{
    if(n%4 == 0)
        return n/4;
    else
        if(n%4 == 2)
            return (n+2)/4;
        else
            if(n%4 == 1)
                (n+3)/4;
            else return (n+1)/4;
}

void mergeSort_I(int *arr, int n)
{
    int *stackS,*stackI,*middle;
    int limn,x,k,m;

    if(n%2 == 0)
    {
        limn = n/2;
        printf("limn =%d\n",limn);
        stackS = crearArreglo(limn);
        stackI = crearArreglo(limn);
    }
    else
    {
        limn = n+1/2;
        printf("limn =%d\n",limn);
        stackS = crearArreglo(limn);
        stackI = crearArreglo(limn);
    }

    m = numsMiddle(n);

    middle = crearArreglo(m);
    fillZeroArr(middle,m);
    fillZeroArr(stackI,limn);
    fillZeroArr(stackS,limn);

    for(k = 0; k < limn; k++)
    {
        if(k == 0)
        {
            *(stackI + k) = 0;
            if(limn == 1)
                *(stackS + k) = 1;
            else
            {
                *(stackS + k) = (n/2)-1;
            }
        }
        else
        if(*(stackS +k-1)-*(stackI +k-1) >= 1)
        {
            x = (*(stackS +k-1)-*(stackI +k-1))/2;

            *(stackI + k) = *(stackI +k-1);
            *(stackS + k) = x + *(stackI + k);
            k++;
        }

    }

    puts("Inferiores");
    printArreglo(stackI,limn);
    puts("Superiores");
    printArreglo(stackS,limn);
    puts("ll");

}