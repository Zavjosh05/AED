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
void queenPositioning(queen*,int,int);
void eliminateQueen(queen*,int,int);
void queenCheck(queen*);
void addQueen(queen*,int,int);
void queenCheck(queen*);

int main(int argc, char **argv)
{
	queen q;
	
	q.n = chessDimension();
	createChessboard(&q);
	fillZero(&q);
	printChessboard(q);
	addQueen(&q,5,6);
	printChessboard(q);
	addQueen(&q,2,4);
	addQueen(&q,7,2);
	printChessboard(q);
	eliminateQueen(&q,2,4);
	printChessboard(q);

	return 0;
}

int chessDimension(){
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

	putchar('\n');

	for(i = 0; i < q.n; i++){
		for(j = 0; j < q.n; j++)
			printf("%d ",q.chessboard[i][j]);
		printf("\n\n");
	}
	putchar('\n');

}

void queenPositioning(queen *q, int m, int n)
{
	int i,j;

	q->chessboard[m][n] = 2;
	printChessboard(*q);

	//cambios en columna
	for(i = m-1; i >= 0; i--)
		if(q->chessboard[i][n] == 0)
			q->chessboard[i][n] = 1;
	for(i = m+1; i < q->n; i++)
		if(q->chessboard[i][n] == 0)
			q->chessboard[i][n] = 1;
	//cambios en fila
	for(i = n-1; i >= 0; i--)
		if(q->chessboard[m][i] == 0)
			q->chessboard[m][i] = 1;
	for(i = n+1; i < q->n; i++)
		if(q->chessboard[m][i] == 0)
			q->chessboard[m][i] = 1;
	//cambios en diagonal
	//ij
	//++
	for(i = m+1, j = n+1; i < q->n && j < q->n; i++,j++)
		if(q->chessboard[i][j] == 0)
			q->chessboard[i][j] = 1;
	//+-
	for(i = m+1, j = n-1; i < q->n && j >= 0; i++, j--)
		if(q->chessboard[i][j] == 0)
			q->chessboard[i][j] = 1;
	//--
	for(i = m-1, j = n-1; i >= 0 && j >= 0; i--, j--)
		if(q->chessboard[i][j] == 0)
			q->chessboard[i][j] = 1;
	//-+
	for(i = m-1, j = n+1; i >= 0 && j < q->n; i--, j++)
		if(q->chessboard[i][j] == 0)
			q->chessboard[i][j] = 1;
}

void addQueen(queen *q, int m, int n)
{
	if(q->chessboard[m][n] == 0)
		queenPositioning(q,m,n);
	else
		puts("no");
}

void queenCheck(queen *q)
{
	int i,j;

	for(i = 0; i < q->n; i++)
		for(j = 0; j < q->n; j++)
			if(q->chessboard[i][j] == 2)
				queenPositioning(q,i,j);
}

void eliminateQueen(queen *q,int m, int n)
{
	int i,j;

	q->chessboard[m][n] = 0;
	printChessboard(*q);

	//cambios en columna
	for(i = m-1; i >= 0; i--)
		if(q->chessboard[i][n] == 1)
			q->chessboard[i][n] = 0;
	for(i = m+1; i < q->n; i++)
		if(q->chessboard[i][n] == 1)
			q->chessboard[i][n] = 0;
	//cambios en fila
	for(i = n-1; i >= 0; i--)
		if(q->chessboard[m][i] == 1)
			q->chessboard[m][i] = 0;
	for(i = n+1; i < q->n; i++)
		if(q->chessboard[m][i] == 1)
			q->chessboard[m][i] = 0;
	//cambios en diagonal
	//ij
	//++
	for(i = m+1, j = n+1; i < q->n && j < q->n; i++,j++)
		if(q->chessboard[i][j] == 1)
			q->chessboard[i][j] = 0;
	//+-
	for(i = m+1, j = n-1; i < q->n && j >= 0; i++, j--)
		if(q->chessboard[i][j] == 1)
			q->chessboard[i][j] = 0;
	//--
	for(i = m-1, j = n-1; i >= 0 && j >= 0; i--, j--)
		if(q->chessboard[i][j] == 1)
			q->chessboard[i][j] = 0;
	//-+
	for(i = m-1, j = n+1; i >= 0 && j < q->n; i--, j++)
		if(q->chessboard[i][j] == 1)
			q->chessboard[i][j] = 0;

	queenCheck(q);
}
