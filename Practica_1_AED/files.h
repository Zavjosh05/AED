FILE* ReadFile(char *argv[])
{
	return fopen(*argv,"r");
}

FILE* WriteFile(char *argv[])
{
	return fopen(*argv,"w");
}

FILE* WRFile(char *argv[])
{
	return fopen(*argv,"r+");
}

void swapchr(char *a1,char *a2)
{
	char t;

	t = *a1;
	*a1 = *a2;
	*a2 = t;
}

void printArr(char *arr)
{
	int i = 0;

	while(*(arr + i) != '\0')
	{
		putchar(*(arr + i));
		i++;
	}
	putchar('\n');
}

//no jala :,v
int strlenJ(char *arr)
{
	int i = 0, count = 0;

	while(*(arr+i) != '\0')
	{
		count++;
		printf("%d\n",count);
	}	

	return count;
}

void bubbleSortStr(char *bub,int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n-1; j++)
			if(*(bub + j) > *(bub + j + 1))
				swapchr(bub+j,bub+j+1);
}

void selectionSortStr(char *select,int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = i+1; j < n; j++)
			if(*(select+i) > *(select+j))
				swapchr(select+i,select+j);
}

void insertionSortStr(char *insert, int n)
{
	int i,j,k;
	char aux;

		for(i = 1; i < n; i++)
			for(j = i-1; j >= 0; j++)
				if(*(insert+i) < *(insert+j))
				{
					aux = *(insert+i);
					for(k = i; k > j; k--)
						*(insert+k) = *(insert+k-1);
					
					*(insert+j) = aux;
				}
}

int countChrFile(char *argv[])
{
	char c;
	int cont = 0;
	FILE *fil;

	fil = fopen(*++argv, "r");

	
	while((c = fgetc(fil)) != EOF)
		if(c != ' ' && c != '\n')
			cont++;

	fclose(fil);
		
	return cont;
}

void fileToArr(char *argv[],char *arr)
{
	int i = 0;
	char c;
	FILE *fil;

	fil = fopen(*++argv,"r");

	while((c = fgetc(fil)) != EOF)
		if(c != ' ' && c != '\n')
		{
			*(arr + i) = c;
			i++;
		}

	*(arr + i) = '\0';

	fclose(fil);
}

void ArrToFile(char *argv, char *arr)
{
	int i = 0;
	char c;
	FILE *fil;

	fil = fopen(argv, "w");

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

	ArrToFile("BubbleSort.txt",arr);
}

void selectionProcess(char *arr,int n)
{
	selectionSortStr(arr,n);

	ArrToFile("SelectionSort.txt",arr);
}

void insertionProcess(char *arr,int n)
{
	insertionSortStr(arr, n);

	ArrToFile("InsertionSort.txt",arr);
}

void sortFile(char *argv[])
{
	int n;
	char *arr;

	n = countChrFile(argv);
	printf("%d\n",n);

	arr = (char*)malloc(n*sizeof(char));	

	fileToArr(argv, arr);

	bubbleProcess(arr,n);

	selectionProcess(arr,n);

	insertionProcess(arr,n);
}


