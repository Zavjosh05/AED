#include<stdio.h>
#include<stdlib.h>

//Sort related functions

void swapChr(char *c1, char *c2)
{
    char aux;

    aux = *c1;
    *c1 = *c2;
    *c2 = aux;
}

int* crearArregloInt(int n)
{
    return (int*)malloc(n*sizeof(int));
}

char* crearArregloChar(int n)
{
    return (char*)malloc(n*sizeof(char));
}

void fillZeroArrInt(int *arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
        *(arr+i) = 0;
}

void fillZeroArrChar(char *arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
        *(arr+i) = 0;
}

void liberarArregloInt(int **arr)
{
    free(*arr);
    arr = NULL;
}

void liberarArregloChar(char **arr)
{
    free(*arr);
    *arr = NULL;
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

int powJ(unsigned int base, unsigned int exponente)
{
    if(exponente == 0)
        return 1;
    else
        return base*powJ(base,exponente-1);
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

void bubbleSortStr(char *bub,int n)
{
    int i,j;

    for(i = 0; i < n; i++)
		for(j = 0; j < n-1; j++)
			if(*(bub + j) > *(bub + j + 1))
				swapChr(bub+j,bub+j+1);
}

void selectionSortStr(char *select,int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++)
			if(*(select+i) > *(select+j))
				swapChr(select+i,select+j);
}

void insertionSortStr(char *insert, int n)
{
	int i,j,k;
	char aux;

		for(i = 1; i < n; i++)
			for(j = 0; j < i; j++)
				if(*(insert+i) < *(insert+j))
				{
					aux = *(insert+i);
					for(k = i; k > j; k--)
						*(insert+k) = *(insert+k-1);
					
					*(insert+j) = aux;
				}
}

void quickSortStr_R(char *arr, int pivot)
{
    char *check = arr-1;
    int i, count = -1;

    for(i = 0; i <= pivot; i++)
        if(*(arr + i) <= *(arr+pivot))
        {
            check++;
            count++;
            if(arr+i > check)
                swapChr(arr+i,check);
        }
    if(count > 1)
        quickSortStr_R(arr,count-1);
    if(pivot-count > 1)
        quickSortStr_R(++check,pivot-count-1);
    
}

void quickSortStr_I(char *arr, int n)
{
    int i, j, m, count, aux;
    int *lims, *limi;

    if(n <= 1)
        return;

    m = detectExp2(detectPow2(n));

    lims = crearArregloInt(m);
    limi = crearArregloInt(m);

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
                    swapChr(arr+i,arr+count);
            }
        }

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

void mSortProcess2(char *arr, int inf, int sup)
{
    int i,j,k,l = sup-inf, middle;
    char *aux;

    aux = crearArregloChar(l+1);
    fillZeroArrChar(aux,l+1);

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
    
    liberarArregloChar(&aux);
}

void mergeSortStr_I(char *arr, int n)
{
    int limn, i, j, x, count;
	int *lims,*limi,*dif;

	limn = sumNivelesB2(detectPow2(n));

	lims = crearArregloInt(limn);
	limi = crearArregloInt(limn);
    dif = crearArregloInt(limn);
    fillZeroArrInt(lims,limn);
    fillZeroArrInt(limi,limn);
    fillZeroArrInt(dif,limn);

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

    liberarArregloInt(&limi);
    liberarArregloInt(&lims);
    liberarArregloInt(&dif);
}

void mSortProcess(char *arr, int inf, int sup)
{
    int i,j,k,l = sup-inf, middle;
    char *aux;


    aux = crearArregloChar(l+1);
    fillZeroArrChar(aux,l+1);

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
        
    liberarArregloChar(&aux);
}

void mergeSortStr_R(char *arr, int inf, int sup)
{
    int x; 

    if(sup-inf >= 1)
    {
        x = (sup - inf)/2;

        if(sup-inf >= 2)
        {
            mergeSortStr_R(arr,inf,inf+x-1);
            mergeSortStr_R(arr,inf+x,sup);
        }
        mSortProcess(arr,inf,sup);
    }  
}

void recombMerg(char *arr, int inf, int sup)
{
    char *aux;
    int i,j,k;

    aux = (char*)malloc((sup-inf+1)*sizeof(char));

    for(i = 0; i <= (sup - inf); i++)
    {
        j = (sup/2) + 1;
        if(*(arr + i) < *(arr + j))
        {
            aux;
        }
    }
}

int sortedArrayVerification(char *arr, int n)
{
    int i, j;

    for(i = 0; i < n; i++)
        for(j = i+1; j < n; j++)
            if(*(arr + i) > *(arr + j))
                return 0;
    
    return 1;
}

//File related functions

int countChrFile(FILE *fil)
{
    char c;
    int count = 0;

    rewind(fil);

    while((c=fgetc(fil))!=EOF)
        if(c != ' ' && c != '\n')
            count++;

    return count;
}

void copyChrArr(char *arr1, char *arr2)
{
    int i = 0;

    while(*(arr1 + i) != '\0')
    {
        *(arr2 + i) = *(arr1 + i);
        i++;
    }

    *(arr2 + i) = '\0';
}

void fileToArr(FILE *fil, char *arr)
{
    rewind(fil);

    char c;
    int i=0;

    while((c=fgetc(fil))!=EOF)
        if(c != ' ' && c != '\n')
        {
            *(arr + i) = c;
            i++;
        }

    *(arr + i) = '\0';
}

void arrToFile(char *nom,char *arr)
{
    int i = 0;
    char c;
    FILE *fil;

    fil = fopen(nom, "w");

    while(*(arr+i) != '\0')
    {
        fputc(*(arr+i),fil);
        i++;
    }

    fclose(fil);
}

void bubbleProcess(char *arr, int n)
{
    bubbleSortStr(arr,n);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/BubbleSort.txt",arr);
        puts("BubbleSort exitoso");
    }
    else puts("Error en BubbleSort");

    
}

void selectionProcess(char *arr, int n)
{
    selectionSortStr(arr,n);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/SelectionSort.txt",arr);
        puts("SelectionSort exitoso");
    }
    else puts("Error en SelectionSort");

    
}

void insertionProcess(char *arr, int n)
{
    insertionSortStr(arr,n);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/InsertionSort.txt",arr);
        puts("InsertionSort exitoso");
    }
    else puts("Error en InsertionSort");

    
}

void quick_RProcess(char *arr, int n)
{
    quickSortStr_R(arr,n-1);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/QuickSort_R.txt",arr);
        puts("QuickSort recursivo exitoso");
    }
    else puts("Error en QuickSort recursivo");
}

void quick_IProcess(char *arr, int n)
{
    quickSortStr_I(arr,n);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/QuickSort_I.txt",arr);
        puts("QuickSort iterativo exitoso");
    }
    else puts("Error en quicksort iterativo");
    
}

void merge_IProcess(char *arr, int n)
{
    mergeSortStr_I(arr,n);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/MergeSort_I.txt",arr);
        puts("MergeSort iterativo exitoso");
    }
    else puts("Error en MergeSort iterativo");

    
}

void merge_RProcess(char *arr, int n)
{
    mergeSortStr_R(arr,0,n-1);
    if(sortedArrayVerification(arr,n))
    {
        arrToFile("Sorts/MergeSort_R.txt",arr);
        puts("MergeSort recursivo exitoso");
    }
    else puts("Error en mergesort recursivo");

    
}

void sortFile(char **argv)
{
    int n;
    char *arr, *arr1, *arr2, *arr3, *arr4, *arr5, *arr6;
    FILE *fil = fopen(*argv,"r");

    n = countChrFile(fil);

    printf("Num of chars without ' ' and '\\n': %d\n",n);

    arr = (char*)malloc(n*sizeof(char));
    arr1 = (char*)malloc(n*sizeof(char));
    arr2 = (char*)malloc(n*sizeof(char));
    arr3 = (char*)malloc(n*sizeof(char));
    arr4 = (char*)malloc(n*sizeof(char));
    arr5 = (char*)malloc(n*sizeof(char));
    arr6 = (char*)malloc(n*sizeof(char));

    fileToArr(fil,arr);

    copyChrArr(arr,arr1);
    copyChrArr(arr,arr2);
    copyChrArr(arr,arr3);
    copyChrArr(arr,arr4);
    copyChrArr(arr,arr5);
    copyChrArr(arr,arr6);

    quick_IProcess(arr,n);
    quick_RProcess(arr1, n);
    merge_IProcess(arr2,n);
    merge_RProcess(arr3,n);
    bubbleProcess(arr4,n);
    selectionProcess(arr5,n);
    insertionProcess(arr6,n);

    liberarArregloChar(&arr);
    liberarArregloChar(&arr1);
    liberarArregloChar(&arr2);
    liberarArregloChar(&arr3);
    liberarArregloChar(&arr4);
    liberarArregloChar(&arr5);
    liberarArregloChar(&arr6);
}