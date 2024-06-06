#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void presentacion(int);
void hyp6(int*******,int,int,int,int,int,int);
void freeHyp6(int*******,int,int,int,int,int);
void fillZeroHyp6(int******,int,int,int,int,int,int);
void printHyp6(int******,int,int,int,int,int,int);
void CambioVientoHyp6(int******,int,int,int,int,int,int);
unsigned long long int combinationsHyp6(int,int,int,int,int,int,int);
unsigned long long int powJ(unsigned int, unsigned long long int);

int main(void)
{
	int i,j,k,l,m,n;
	int ******hyp = NULL;

	presentacion(1);

	puts("Ingrese las dimensiones del hipermatriz de 6 dimensiones\n[] [] [] [] [] []");
	scanf("%d%d%d%d%d%d",&i,&j,&k,&l,&m,&n);

	puts("Creacion de hipermatriz");
	hyp6(&hyp,i,j,k,l,m,n);
	fillZeroHyp6(hyp,i,j,k,l,m,n);
	
	puts("\nEn caso de que los valores de la hipermatriz solo puedan ser 1 o 0 como lo indica el problema:");
	printf("Combinaciones: 2^(%dx%dx%dx%dx%dx%d)\n\n",i,j,k,l,m,n);

	puts("Cambios en el viento\n");
	CambioVientoHyp6(hyp,i,j,k,l,m,n);

	puts("Imprimir matriz (si = 1/ no = 0)");
	fseek(stdin,0,SEEK_END);
	if(getchar() == '1')
		printHyp6(hyp,i,j,k,l,m,n);

	puts("\nliberacion de la hipermatriz");
	freeHyp6(&hyp,i,j,k,l,m);
	printf("Comprobacion: Hyp = %X",hyp);



	return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Primer examen de estructura de datos");
    printf("Ejercicio No. %d\n", n);
}

void hyp6(int *******hyp,int ii,int jj,int kk,int ll,int mm,int n)
{
    int i,j,k,l,m;

    *hyp = (int******)malloc(ii*sizeof(int*****));

    for(i = 0; i < ii; i++)
    {
        *(*hyp + i) = (int*****)malloc(jj*sizeof(int****));
        for(j = 0; j < jj; j++)
        {
            *(*(*hyp + i)+ j) = (int****)malloc(kk*sizeof(int***));
			for(k = 0; k < kk; k++)
			{
				*(*(*(*hyp + i)+ j)+ k) = (int***)malloc(ll*sizeof(int**));
				for(l = 0; l < ll; l++)
				{
					*(*(*(*(*hyp + i)+ j)+ k)+ l) = (int**)malloc(mm*sizeof(int*));
					for(m = 0; m < mm; m++)
						*(*(*(*(*(*hyp + i)+ j)+ k)+ l)+ m) = (int*)malloc(n*sizeof(int));
				}
			}
        }
    }
}

void freeHyp6(int *******hyp, int ii, int jj, int kk, int ll, int mm)
{
	int i,j,k,l,m;

	for(i = 0; i < ii; i++)
	{
		for(j = 0; j < jj; j++)
		{
			for(k = 0; k < kk; k++)
			{
				for(l = 0; l < ll; l++)
				{
					for(m = 0; m < mm; m++)
						free(*(*(*(*(*(*hyp + i)+ j)+ k)+ l)+ m));
					free(*(*(*(*(*hyp + i) + j) + k) + l));
				}
				free(*(*(*(*hyp + i) + j) + k));
			}
			free(*(*(*hyp + i) + j));
		}
		free(*(*hyp + i));
	}

	free(*hyp);

	*hyp = NULL;
}

void fillZeroHyp6(int ******hyp, int ii, int jj, int kk, int ll, int mm, int nn)
{
	int i,j,k,l,m,n;

	for(i = 0; i < ii; i++)
		for(j = 0; j < jj; j++)
			for(k = 0; k < kk; k++)
				for(l = 0; l < ll; l++)
					for(m = 0; m < mm; m++)
						for(n = 0; n < nn; n++)
							*(*(*(*(*(*(hyp + i) + j) + k) + l) + m) + n) = 0;
}

void printHyp6(int ******hyp, int ii, int jj, int kk, int ll, int mm, int nn)
{
	int i,j,k,l,m,n;

	putchar('\n');
	for(i = 0; i < ii; i++)
		for(j = 0; j < jj; j++)
			for(k = 0; k < kk; k++)
				for(l = 0; l < ll; l++)
					for(m = 0; m < mm; m++)
						for(n = 0; n < nn; n++)
							printf("hyp[%d][%d][%d][%d][%d][%d] = %d\n",i,j,k,l,m,n,*(*(*(*(*(*(hyp + i) + j) + k) + l) + m) + n));
}

void CambioVientoHyp6(int ******hyp, int i, int j, int k, int l, int m, int n)
{
	int ii,jj,kk,ll,mm,nn;

	srand(time(NULL));

	for(ii = 0; ii < i; ii++)
		for(jj = 0; jj < j; jj++)
			for(kk = 0; kk < k; kk++)
				for(ll = 0; ll < l; ll++)
					for(mm = 0; mm < m; mm++)
						for(nn = 0; nn < n; nn++)
							*(*(*(*(*(*(hyp + ii) + jj) + kk) + ll) + mm) + nn) = rand() % 2;
}

unsigned long long int combinationsHyp6(int i, int j, int k, int l, int m, int n, int states)
{
	int total;

	total = i*j*k*l*m*n;

	return powJ(states,total);
}

unsigned long long int powJ(unsigned int b, unsigned long long int exp)
{
	int i;

	for(i = 1; i <= exp; i++)
		b *= b;

	return b;
}