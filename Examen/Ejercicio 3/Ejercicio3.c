#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
void mSortProcess(int*,int,int);
void mSortProcess2(int*,int,int);
void mergeSort_R(int*,int,int);
void mergeSort_I(int*,int);
int* crearArreglo(int);
void fillZeroArr(int*,int);
void llenarAleatoriamenteArreglo(int*,int);
void liberarArreglo(int**);
void printArreglo(int*,int);
int powJ(unsigned int base, unsigned int exponente);
int detectPow2(int);
int detectExp2(int);
int sumNivelesB2(int);

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

int powJ(unsigned int base, unsigned int exponente)
{
    if(exponente == 0)
        return 1;
    else
        return base*powJ(base,exponente-1);
}

int detectPow2(int n){
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

int sumNivelesB2(int n) //toma como entrada detectPow2(int)
{
    int x, i, count;
    
    x = detectExp2(n);
    x--;
    count = 0;

    for(i = x; i >=0; i--)
        count += powJ(2,i);

    return count;
}

void mSortProcess2(int *arr, int inf, int sup)
{
    int i,j,k,l = sup-inf, middle;
    int *aux;

    aux = crearArreglo(l+1);
    fillZeroArr(aux,l+1);

    i = inf;
    if(l == 1)
        j = inf + 1;
    else
        if(l%2 == 0)
            j = inf + l/2;
        else
            j = inf + (l/2)+1;
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

void mergeSort_I(int *arr, int n)
{
    int limn, i, j, x, count;
	int *lims,*limi,*dif;

	limn = sumNivelesB2(detectPow2(n));

	lims = crearArreglo(limn);
	limi = crearArreglo(limn);
    dif = crearArreglo(limn);
    fillZeroArr(lims,limn);
    fillZeroArr(limi,limn);
    fillZeroArr(dif,limn);

    for(i = 0;i< limn; i++){
        if(i == 0)
        {
            *limi = 0;
            *lims = n-1;
            *dif = *lims - *limi;
            count = 1;
        }
        else
        {
            *(limi + i) = *(limi + i-count);
            if(*(dif + i-count) % 2 != 0)
                *(lims + i) = (*(dif + i-count)/2)+*(limi+i);
            else
                *(lims + i) = (*(dif + i-count)/2)-1+*(limi+i);
            *(dif + i) = *(lims + i) - *(limi + i);
            count++;
            i++;
            *(limi + i) = *(lims + i-1)+1;
            *(lims + i) = *(lims + i-count);
            *(dif + i) = *(lims + i) - *(limi + i);
        }
    }

    for(j = limn-1; j >= 0; j--)
        if(*(limi+j) !=*(lims+j))
            mSortProcess2(arr,*(limi + j),*(lims + j));

    liberarArreglo(&limi);
    liberarArreglo(&lims);
    liberarArreglo(&dif);
}