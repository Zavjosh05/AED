#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
void quickSort_R(int*,int);
void quickSort_I(int*,int);
void swapInt(int*,int*);
int* crearArreglo(int);
void fillZeroArr(int*,int);
void llenarAleatoriamenteArreglo(int*,int);
void liberarArreglo(int**);
void printArreglo(int*,int);
void printArregloParticion(int*,int,int);
int detectPow2(int);
int detectExp2(int);

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

    //quickSort_R(arr,n-1);
    quickSort_I(arr,n);

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

void printArregloParticion(int *arr, int limi, int lims)
{
    int i;

    for(i = limi; i <= lims; i++)
        printf("%d ",*(arr+i));
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

void quickSort_R(int *arr,int pivot)
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
        quickSort_R(arr,count-1);
    if(pivot-count > 1)
        quickSort_R(++check,pivot-count-1);
}

int detectPow2(int n)
{
	int x = 2;

	while(n/x != 0 || n/x==1){
	    if(n/x == 1 && n%x == 0)
	        return x;
	    else
		    x *= 2;
    }

	return x;
}

int detectExp2(int n)
{
    int count = 0, x = 1;

    if(n == 1)
        return 1;
    
    while(x != n)
    {
        x *= 2;
        count++;
    }

    return count;
}

void quickSort_I(int *arr, int n)
{
    int i, j, m, count, aux;
    int *lims, *limi;

    if(n <= 1)
        return;

    m = detectExp2(detectPow2(n));

    lims = crearArreglo(m);
    limi = crearArreglo(m);

    *limi = 0;
    *lims = n-1;

    j = 0;
    while(j > -1)
    {
        count = *(limi+j)-1;

        for(i = *(limi+j); i <= *(lims+j); i++)
        {
            if(*(arr + i) <= *(arr +*(lims+j)))
            {
                count++;
                if(i > count)
                    swapInt(arr+i,arr+count);
            }
        }
        //printArregloParticion(arr,*(limi+j),*(lims+j));

        if((count-1)-*(limi+j) >= 1 && *(lims+j)-(count+1) >= 1)
        {
            aux = *(lims+j);
            *(lims+j) = count-1;
            *(limi+j+1) = count+1;
            *(lims+j+1) = aux;
            j++;
        }
        else
            if((count-1)-*(limi+j) >= 1)
                *(lims+j) = count-1;
            else
                if(*(lims+j)-(count+1) >= 1)
                    *(limi+j) = count+1;
                else
                    j--;
    }

}