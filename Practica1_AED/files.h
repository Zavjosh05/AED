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

void Swapchr(char *a1,char *a2)
{
	char t;

	t = *a1;
	*a1 = *a2;
	*a2 = t;
}

void BubbleSortChar(char *bub,int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n-1; j++)
			if(*(bub + j) > *(bub + j + 1))
				Swapchr(bub+j,bub+j+1);
}

int ContCharFile(char *argv[])
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

void FileToArr(char *argv[],char *arr, int n)
{
	int i;
	char c;
	FILE *fil;

	fil = fopen(*++argv,"r");

	for(i = 0; i < n; i++)
	{
		c = fgetc(fil);
		printf("%c\n",c);
		*(arr + i) = c;
		printf("%s\n",arr);
	}
	printf("%s\n",arr);
	fclose(fil);
}

void ArrToFile(char *argv[], char *arr)
{
	int i;
	FILE *fil;

	fil = fopen(*++argv, "w");
	
	for(i = 0; i < sizeof(arr); i++){
		fputc(*(arr + i), fil);
		printf("%c\n", *(arr +i));
	}

	fclose(fil);
}

void BubbleSort_File(char *argv[])
{
	int n;
	char *arr;

	n = ContCharFile(argv);
	printf("%d\n", n);

	arr = (char*)malloc(n*sizeof(char));
	
	printf("%d\n", sizeof(arr));	

	FileToArr(argv, arr, n);

	printf("%s\n",arr);

	//BubbleSortChar(arr,n);
	
	ArrToFile(++argv,arr);
}
