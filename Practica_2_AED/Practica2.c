#include<stdio.h>
#include<stdlib.h>

typedef struct {
int **chessboard;
int n;
} queen;

int chessDimension();
void createChessboard(queen*);
void fillZero(queen*);
void printChessboardNums(queen);
void printChessboard(queen);
void queenPositioning(queen*,int,int);
void eliminateQueen(queen*,int,int);
int checkQueenPositioning(queen,int,int);
void queenElimCheck(queen*);
void queensProblem(queen*);

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
	addQueen(&q,5,2);
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

void printChessboardNums(queen q)
{
	int i,j;

	putchar('\n');

	for(i = 0; i < q.n; i++){
		for(j = 0; j < q.n; j++)
			printf("%d  ",q.chessboard[i][j]);
		printf("\n\n");
	}
	putchar('\n');

}

void printChessboard(queen q)
{
	int i,j;

	printf("Tablero %d x %d\n",q.n,q.n);

	for(i = 0; i < q.n; i++){
		for(j = 0; j < q.n; j++)
			if(q.chessboard[i][j] == 0 || q. chessboard[i][j] == 1)
				if((i+j) % 2 == 0)
					printf("%c%c",178,178);
				else
					printf("%c%c",176,176);
			else
				printf("%c%c",241,241);
		putchar('\n');
	}
}

void queenPositioning(queen *q, int m, int n)
{
	int i,j;

	q->chessboard[m][n] = 2;

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

int checkQueenPositioning(queen q, int m, int n)
{
	if(q->chessboard[m][n] == 0)
		return 1;
	else
		return 0;
}

void queenElimCheck(queen *q)
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

	queenElimCheck(q);
}

int rowAvailability(queen q, int lvl)
{
	int i;

	for(i = 0; i < q.n; i++)
		if(q.chessboard[lvl][i] == 0)
			return i+1;
	return 0;
}

//state = 1 -> keep in the way, = 0 reset and try the next one
int queensProblem(queen *q, int lvl, int state)
{
	int i;

	if(lvl == q->n - 1)
  		if(rowAvailavility(*q,lvl)) {
			queenPositioning(q,lvl,rowAvailability()-1);
			return 1 + queensProblem(q, lvl-1, 0);
		}
		else
		{
			return queensProblem(q, lvl-1, 0);
		}
	else
		if(lvl == 0)
			if(state == 0)
				for(i = 0; i < q->n; i++)
				{
					queenPositioning(q,lvl,i);
					return queensProblem(q,lvl,);
				}

	{
		
		for(i = 0; i < q->n; i++)
			if(rowAvailability(*q,lvl))
	}

			

}
