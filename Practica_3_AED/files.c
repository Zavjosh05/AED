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
/*quicksort personal variation
int checkOrder(char *arr, int n)
{
    int i,j;

    for(i = n-1; i >= 0; i--)
        for(j = i-1; j >= 0; j--)
            if(arr[i] < arr[j])
                return 1;
    return 0;
}

int checkGreater(char *arr, int piv)
{
    int i;

    for(i = 0; i < piv; i++)
        if(arr[piv] < arr[i])
            return i+1;
    return 0;
}

void interchage(char *f, char *d)
{
    char aux;
    
    if(*(f-1) == *d)
        swapChr(f,d);
    else
    {
        aux = *(f-1);
        *(f-1) = *f;
        *f = *d;
        *d = aux;
    }
}

void quickSortStr(char *arr, int n, int pivot) //initiali, pivote = n-1
{
    int k;

    if(checkOrder(arr, n))
    {
        k = checkGreater(arr,pivot);
        if(k)
        {
            interchage(arr+pivot,arr+k-1);
            quickSortStr(arr,n,pivot);
        }
        else
            quickSortStr(arr,n-1,pivot-1);

    }
}
*/

void quickSortStr(char *arr, int n,int pivot)
{
    char *check = arr-1;
    int i, count = -1;

    for(i = 0; i < n; i++)
        if(*(arr + i) <= *(arr+pivot))
        {
            check++;
            count++;
            if(arr+i > check)
                swapChr(arr+i,check);
        }
    if(count > 1)
        quickSortStr(arr,count,count-1);
    if(n-count > 1)
        quickSortStr(check+1,n-count,pivot);
    
}

void mergeSortStr_I(char *arr, int n)
{

}

void mergeSortStr_R(char *arr, int n)
{

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

    arrToFile("BubbleSort.txt",arr);
}

void selectionProcess(char *arr, int n)
{
    selectionSortStr(arr,n);

    arrToFile("SelectionSort.txt",arr);
}

void insertionProcess(char *arr, int n)
{
    insertionSortStr(arr,n);

    arrToFile("InsertionSort.txt",arr);
}

void quickProcess(char *arr, int n)
{
    quickSortStr(arr, n, n-1);

    arrToFile("QuickSort.txt",arr);
}

void sortFile(char **argv)
{
    int n;
    char *arr, *arr1, *arr2, *arr3;
    FILE *fil = fopen(*argv,"r");

    n = countChrFile(fil);

    printf("Num of chars without ' ' and '\\n': %d\n",n);

    arr = (char*)malloc(n*sizeof(char));
    arr1 = (char*)malloc(n*sizeof(char));
    arr2 = (char*)malloc(n*sizeof(char));
    arr3 = (char*)malloc(n*sizeof(char));

    fileToArr(fil,arr);

    copyChrArr(arr,arr1);
    copyChrArr(arr,arr2);
    copyChrArr(arr,arr3);

    //bubbleProcess(arr1,n);
    //selectionProcess(arr2,n);
    //insertionProcess(arr3,n);

    quickProcess(arr1, n);

}