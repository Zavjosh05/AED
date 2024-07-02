//Hyper creation
void Hyp1d(int **arr, int n)
{
	*arr = (int*)malloc(n*sizeof(int));
}

void Hyp2d(int ***arr, int ni, int nj)
{
	int i;

	*arr = (int**)malloc(ni*sizeof(int*));

	for(i = 0; i < ni; i++)
		Hyp1d(*arr + i, nj);
}

void Hyp3d(int ****arr, int ni, int nj, int nk)
{
	int i;

	*arr = (int***)malloc(ni*sizeof(int**));

	for(i = 0; i < ni; i++)
		Hyp2d(*arr + i, nj, nk);
}

void Hyp4d(int *****arr, int ni, int nj, int nk, int nl)
{
	int i;

	*arr = (int****)malloc(ni*sizeof(int***));

	for(i = 0; i < ni; i++)
		Hyp3d(*arr + i, nj, nk, nl);
}

void Hyp5d(int ******arr, int ni, int nj, int nk, int nl, int nm)
{
	int i;

	*arr = (int*****)malloc(ni*sizeof(int****));

	for(i = 0; i < ni; i++)
		Hyp4d(*arr + i, nj, nk, nl, nm);
}

void Hyp6d(int *******arr, int ni, int nj, int nk, int nl, int nm, int nn)
{
	int i;

	*arr = (int******)malloc(ni*sizeof(int*****));

	for(i = 0; i < ni; i++)
		Hyp5d(*arr + i, nj, nk, nl, nm, nn);
}

//Free Hyper

void FreeH1(int **arr)
{
	free(*arr);
	*arr = NULL;
}

void FreeH2(int ***arr, int ni) //ni number of unidimensional arrays 
{
	int i;

	for(i = 0; i < ni; i++)
		FreeH1(*arr + i);
	
	free(*arr);
	*arr = NULL;
}

void FreeH3(int ****arr, int ni, int nj)
{
	int i;

	for(i = 0; i < ni; i++)
		FreeH2(*arr + i, nj);

	free(*arr);
	*arr = NULL;
}

void FreeH4(int *****arr, int ni, int nj, int nk)
{
	int i;

	for(i = 0; i < ni; i++)
		FreeH3(*arr + i, nj, nk);

	free(*arr);
	*arr = NULL;
}

void FreeH5(int ******arr, int ni, int nj, int nk, int nl)
{
	int i;

	for(i = 0; i < ni; i++)
		FreeH4(*arr + i, nj, nk, nl);

	free(*arr);
	*arr = NULL;
}

void FreeH6(int *******arr, int ni, int nj, int nk, int nl, int nm)
{
	int i;

	for(i = 0; i < ni; i++)
		FreeH5(*arr + i, nj, nk, nl, nm);

	free(*arr);
	*arr = NULL;
}

//print functions for hypers

void PrH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		printf("Hyper[%d] = %d\n",i,*(arr + i));
}

void PrH2(int **arr, int ni, int nj)
{
	int i, j;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			printf("Hyper[%d][%d] = %d\n",i,j,*(*(arr + i) + j));
}

void PrH3(int ***arr, int ni, int nj, int nk)
{
	int i, j, k;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				printf("Hyper[%d][%d][%d] = %d\n",i,j,k,*(*(*(arr + i) + j) + k));
}

void PrH4(int ****arr, int ni, int nj, int nk, int nl)
{
	int i, j, k, l;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					printf("Hyper[%d][%d][%d][%d] = %d\n",i,j,k,l,*(*(*(*(arr + i) + j) + k) + l));
}

void PrH5(int *****arr, int ni, int nj, int nk, int nl, int nm)
{
	int i, j, k, l, m;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					for(m = 0; m < nm; m++)
						printf("Hyper[%d][%d][%d][%d][%d] = %d\n",i,j,k,l,m,*(*(*(*(*(arr + i) + j) + k) + l) + m));
}

void PrH6(int ******arr, int ni, int nj, int nk, int nl, int nm, int no)
{
	int i, j, k, l, m, o;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					for(m = 0; m < nm; m++)
						for(o = 0; o < no; o++)
							printf("Hyper[%d][%d][%d][%d][%d][%d] = %d\n",i,j,k,l,m,o,*(*(*(*(*(*(arr+i)+j)+k)+l)+m)+o));
}

//Initialization functions

void InicH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		*(arr + i) = 0;
}

void InicH2(int **arr, int ni, int nj)
{
	int j;

	for(j = 0; j < ni; j++)
		InicH1(*(arr + j), nj);
}

void InicH3(int ***arr, int ni, int nj, int nk)
{
	int k;

	for(k = 0; k < ni; k++)
		InicH2(*(arr + k), nj, nk);
}

void InicH4(int ****arr, int ni, int nj, int nk, int nl)
{
	int l;
	
	for(l = 0; l < ni; l++)
		InicH3(*(arr + l), nj, nk, nl);
}

void InicH5(int *****arr, int ni, int nj, int nk, int nl, int nm)
{
	int m;

	for(m = 0; m < ni; m++)
		InicH4(*(arr + m), nj, nk, nl, nm);
}

void InicH6(int ******arr, int ni, int nj, int nk, int nl, int nm, int no)
{
	int o;

	for(o = 0; o < ni; o++)
		InicH5(*(arr + o), nj, nk, nl, nm, no);
}

//Fill functions

void FillH1(int *arr, int n)
{
	int i;

	for(i = 0; i < n; i++)
		*(arr+i) = i;
}

void FillH2(int **arr, int ni, int nj)
{
	int i,j;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			*(*(arr+i)+j) = i*j;
}

void FillH3(int ***arr, int ni, int nj, int nk)
{
	int i,j,k;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
			*(*(*(arr+i)+j)+k) = i*j*k;
}

void FillH4(int ****arr, int ni, int nj, int nk, int nl)
{
	int i,j,k,l;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					*(*(*(*(arr+i)+j)+k)+l) = i*j*k*l;
}

void FillH5(int *****arr, int ni, int nj, int nk, int nl, int nm)
{
	int i,j,k,l,m;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					for(m = 0; m < nm; m++)
						*(*(*(*(*(arr+i)+j)+k)+l)+m) = i*j*k*l*m;
}

void FillH6(int ******arr, int ni, int nj, int nk, int nl, int nm, int no)
{
	int i, j, k, l, m, o;

	for(i = 0; i < ni; i++)
		for(j = 0; j < nj; j++)
			for(k = 0; k < nk; k++)
				for(l = 0; l < nl; l++)
					for(m = 0; m < nm; m++)
						for(o = 0; o < no; o++)
							*(*(*(*(*(*(arr + i) + j) + k) + l) + m) + o) = i*j*k*l*m*o;					
}
