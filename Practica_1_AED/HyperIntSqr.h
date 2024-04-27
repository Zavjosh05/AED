//create Hypers

void Hyp1d(int **arr, int n)
{
	*arr = (int*)malloc(n*sizeof(int));
}

void Hyp2d(int ***arr, int n)
{
	int i;

	*arr = (int**)malloc(n*sizeof(int*));

	for(i = 0; i < n; i++)
		Hyp1d(*arr + i,n);
}

void Hyp3d(int ****arr, int n)
{
	int j;

	*arr = (int***)malloc(n*sizeof(int**));

	for(j = 0; j < n; j++)
		Hyp2d(*arr + j, n);
}

void Hyp4d(int *****arr, int n)
{
	int k;

	*arr = (int****)malloc(n*sizeof(int***));

	for(k = 0; k < n; k++)
		Hyp3d(*arr + k, n);
}

void Hyp5d(int ******arr, int n)
{
	int l;

	*arr = (int*****)malloc(n*sizeof(int****));

	for(l = 0; l < n; l++)
		Hyp4d(*arr + l, n);
}

void Hyp6d(int *******arr, int n)
{
	int m;

	*arr = (int******)malloc(n+sizeof(int*****));

	for(m = 0; m < n; m++)
		Hyp5d(*arr + m, n);
}

//free Hypers

void FreeH1(int **arr)
{
	free(*arr);
	*arr = NULL;
}

void FreeH2(int ***arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		FreeH1(*arr + i);

	free(*arr);
	*arr = NULL;
}

void FreeH3(int ****arr, int n)
{
	int j;

	for(j = 0; j < n; j++)
		FreeH2(*arr + j, n);

	free(*arr);
	*arr = NULL;
}

void FreeH4(int *****arr, int n)
{
	int k;

	for(k = 0; k < n; k++)
		FreeH3(*arr + k, n);

	free(*arr);
	*arr = NULL;
}

void FreeH5(int ******arr, int n)
{
	int l;

	for(l = 0; l < n; l++)
		FreeH4(*arr + l, n);

	free(*arr);
	*arr = NULL;
}

void FreeH6(int *******arr, int n)
{
	int m;

	for(m = 0; m < n; m++)
		FreeH5(*arr + m, n);

	free(*arr);
	*arr = NULL;
}

//print Hypers

void PrH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("Hyper[%d] = %d\n",i,*(arr + i));
}

void PrH2(int **arr, int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			printf("Hyper[%d][%d] = %d\n",i,j,*(*(arr+i)+j));
}

void PrH3(int ***arr, int n)
{
	int i,j,k;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				printf("Hyper[%d][%d][%d] = %d\n",i,j,k,*(*(*(arr+i)+j)+k));
}

void PrH4(int ****arr, int n)
{
	int i,j,k,l;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					printf("Hyper[%d][%d][%d][%d] = %d\n",i,j,k,l,*(*(*(*(arr+i)+j)+k)+l));
}

void PrH5(int *****arr, int n)
{
	int i,j,k,l,m;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					for(m = 0; m < n; m++)
						printf("Hyper[%d][%d][%d[%d][%d] = %d\n",i,j,k,l,m,*(*(*(*(*(arr+i)+j)+k)+l)+m));
}

void PrH6(int ******arr, int n)
{
	int i,j,k,l,m,o;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					for(m = 0; m < n; m++)
						for(o = 0; o < n; o++)
							printf("Hyper[%d][%d][%d][%d][%d][%d] = %d\n",i,j,k,l,m,o,*(*(*(*(*(*(arr+i)+j)+k)+l)+m)+o));
}

//inic Hypers

void InicH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		*(arr + i) = 0;
}

void InicH2(int **arr, int n)
{
	int j;

	for(j = 0; j < n; j++)
		InicH1(*(arr + j),n);
}

void InicH3(int ***arr, int n)
{
	int k;

	for(k = 0; k < n; k++)
		InicH2(*(arr + k), n);
}

void InicH4(int ****arr, int n)
{
	int l;

	for(l = 0; l < n; l++)
		InicH3(*(arr + l), n);
}

void InicH5(int *****arr, int n)
{
	int m;

	for(m = 0; m < n; m++)
		InicH4(*(arr + m),n);
}

void InicH6(int ******arr, int n)
{
	int o;

	for(o = 0; o < n; o++)
		InicH5(*(arr + o), n);
}

//fill Hypers (the value will be the product of the indexes)

void FillH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		*(arr + i) = i;
}

void FillH2(int **arr, int n)
{
	int i,j;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			*(*(arr+i)+j) = i*j;
}

void FillH3(int ***arr, int n)
{
	int i,j,k;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				*(*(*(arr+i)+j)+j) = i*j*k;
}

void FillH4(int ****arr, int n)
{
	int i,j,k,l;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					*(*(*(*(arr+i)+j)+k)+l) = i*j*k*l;
}

void FillH5(int *****arr, int n)
{
	int i,j,k,l,m;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					for(m = 0; m < n; m++)
						*(*(*(*(*(arr+i)+j)+k)+l)+m) = i*j*k*l*m;
}

void FillH6(int ******arr, int n)
{
	int i,j,k,l,m,o;

	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			for(k = 0; k < n; k++)
				for(l = 0; l < n; l++)
					for(m = 0; m < n; m++)
						for(o = 0; o < n; o++)
							*(*(*(*(*(*(arr+i)+j)+k)+l)+m)+o) = i*j*k*l*m*o;
}
