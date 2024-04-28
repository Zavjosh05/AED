#include<stdio.h>
#include<stdlib.h>

typedef struct {
int **chessboard;
int n;
} queen;

int chessDimension();
void createChessboard(queen*);
void fillZero(queen*);
void printChessboard(queen);

int main(int argc, char **argv)
{
	queen q;
	
	q.n = chessDimension();
	createChessboard(&q);
	fillZero(&q);
	printChessboard(q);

	return 0;
}

int chessDimension()
{
	int n;

	printf("Ingrese la dimension del tablero\n");
	scanf("%d",&n);
	printf("La dimension de tablero es de %d x %d\n",n,n);

	return n;
}

void createChessboard(queen *q)
{
	int x = q->n,i;

	q->chessboard = (int**)malloc(x*sizeof(int*));
	for(i = 0; i < x; i++)
		*(q->chessboard+i) = (int*)malloc(x*sizeof(int));
}

void fillZero(queen *q)
{
	int i,j;

	for(i = 0; i < q->n; i++)
		for(j = 0; j < q->n; j++)
			*(*(q->chessboard+i)+j) = 0;
}

void printChessboard(queen q)
{
	int i,j;

	for(i = 0; i < q.n; i++){
		for(j = 0; j < q.n; j++)
			printf("%d",q.chessboard[i][j]);
		putchar('\n');
	}

}

void queenAppear(queen *q,int m, int n)
{
	int i,j;

	for(i = 0; i < q->n; i++)
}
