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

void BubbleSortChar(char *bub,int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n-1; j++)
			if(*(bub + j) > *(bub + j + 1))
				swapchr(bub+j,bub+j+1);
}

int countChrFile(char *argv[])
{
	char c;
	int cont = 0;
	FILE *fil;

	fil = fopen(*++argv, "r");

	
	while((c = fgetc(fil)) != EOF)
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
	{
		*(arr + i) = c;
		i++;
	}

	*(arr + i) = '\0';

	fclose(fil);
}

void ArrToFile(char *argv[], char *arr)
{
	int i = 0;
	char c;
	FILE *fil;

	fil = fopen(*++argv, "w");

	while(*(arr+i) != '\0')
	{
		fputc(*(arr+i),fil);
		i++;
	}

	fclose(fil);
}

void BubbleSort_File(char *argv[])
{
	int n;
	char *arr;

	n = countChrFile(argv);
	printf("%d\n",n);

	arr = (char*)malloc(n*sizeof(char));	

	fileToArr(argv, arr);

	BubbleSortChar(arr,n);
	
	ArrToFile(++argv,arr);
}


