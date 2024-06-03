#include<stdio.h>
#include<stdlib.h>

typedef struct {
int **chessboard;
int n;
} queen;

int chessDimension();
void createChessboard(queen*);
void freeQueen(queen*);
void fillZero(queen*);
void printChessboardNums(queen);
void printChessboard(queen);
void printChessScreen(queen);
void queenPositioning(queen*,int,int);
void eliminateQueen(queen*,int,int);
int checkQueenPositioning(queen,int,int);
void queenElimCheck(queen*);
void ifExistElimQueen(queen*,int);
int rowAvailability(queen,int);
int queenPositionAvaliability(queen*,int,int);
int queenCount(queen);
int queensProblem(queen*,int);
void queenMenu(queen*);
void queenInic();
void staticQueens(queen*);

int main(void)
{
	
	queenInic();

	return 0;
}

int chessDimension(){
	int n;

	printf("Insert chessboard dimension\n");
	scanf("%d",&n);
	printf("The chessboard dimensions are %d x %d\n\n",n,n);

	return n;
}

void createChessboard(queen *q)
{
	int x = q->n,i;

	q->chessboard = (int**)malloc(x*sizeof(int*));
	for(i = 0; i < x; i++)
		*(q->chessboard+i) = (int*)malloc(x*sizeof(int));
}

void freeQueen(queen *q)
{
	int i;

	for(i = 0; i < q->n; i++)
		free(*(q->chessboard + i));

	free(q->chessboard);

	q->n = 0;

	free(q);
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

	putchar('\n');
	printf("  ");
	for(i = 0; i < q.n; i++)
		printf("%c ",65+i);
	putchar('\n');

	for(i = 0; i < q.n; i++){
		for(j = 0; j < q.n; j++){
			if(j == 0)
				printf("%d ",i+1);
			if(q.chessboard[i][j] == 0 || q. chessboard[i][j] == 1)
				if((i+j) % 2 == 0)
					printf("%c%c",178,178);
				else
					printf("%c%c",176,176);
			else
				if(q.chessboard[i][j] == 2)
					printf("%c%c",241,241);
				else
					printf("%c%c",156,156);
		}
		putchar('\n');
	}
}

void printChessScreen(queen q)
{
	system("cls");

	printf("chessboard %d x %d\n",q.n,q.n);

	printChessboard(q);
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

void staticQueenPositioning(queen *q, int m, int n)
{
	int i,j;

	q->chessboard[m][n] = 3;

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
	if(q.chessboard[m][n] == 0)
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

void ifExistElimQueen(queen *q, int lvl)
{
	int i;

	for(i = 0; i < q->n; i++)
		if(q->chessboard[lvl][i] == 2)
			eliminateQueen(q,lvl,i);
}

int rowAvailability(queen q, int lvl)
{
	int i;

	for(i = 0; i < q.n; i++)
		if(q.chessboard[lvl][i] == 0)
			return i+1;
	return 0;
}

int queenPositionAvaliability(queen *q,int i, int j)
{
	if(q->chessboard[i][j] == 0)
		return 1;
	else
		return 0;
}

int queenCount(queen q)
{
	int i,j, count = 0;

	for(i = 0; i < q.n; i++)
		for(j = 0; j < q.n; j++)
			if(q.chessboard[i][j] = 2)
				count += 1;
	return count;
}

int queensProblem(queen *q, int lvl)
{
	int i,j, count = 0, qcount;

	
	ifExistElimQueen(q,lvl);

	if(lvl == q->n - 1)
	{
		qcount = rowAvailability(*q,lvl);
		if(qcount){
			queenPositioning(q,lvl,qcount-1);
			printChessScreen(*q);
			//system("pause");
			eliminateQueen(q,lvl,qcount-1);
			return 1;
		}
	}
	else 
	{
		for(i = 0; i < q->n; i++)
			if(q->chessboard[lvl][i] == 0){
				queenPositioning(q,lvl,i);
				printChessScreen(*q);
				count += queensProblem(q,lvl+1);
				eliminateQueen(q,lvl,i);
			}
		return count;
	}
}

void staticQueens(queen *q)
{
	int qcount = 0,wait = 1, x, y;
	char op;

	while(wait)
	{
		fseek(stdin,0,SEEK_END);
		system("cls");
		printChessboard(*q);
		printf("\nStatic queens = %d\n",qcount);
		printf("Insert the coordinates of the static queen (row, col): \n");
		scanf("%d%d",&x,&y);
		if((x >= 0 || y >= 0)&&(x <= q->n || y <= q->n))
		{
			if(queenPositionAvaliability(q,x-1,y-1))
			{
				staticQueenPositioning(q,x-1,y-1);
				printChessboard(*q);
				printf("\nStatic queens = %d\n",++qcount);
				puts("Add another static queen? (y/n)");
				fseek(stdin,0,SEEK_END);
				scanf("%c",&op);
				if(op != 'y')
					wait = 0;
			}
			else
				puts("Invalid coordinates");
			
		}
		else
			printf("Ingrese coordenadas validas");
	}
}

//int staticQueensProblem(queen *q, int lvl)

void queenMenu(queen *q)
{
	char x;

	puts("Select option");
	printf("1. Traditional queen's problem\n2. static queens\n");

	fseek(stdin,0,SEEK_END);
	x = getchar();

	switch(x)
	{
		case '1':
			printf("Total of combinatios of a %dx%d chessboard = %d\n",q->n,q->n,queensProblem(q,0));
			break;
		case '2':
				staticQueens(q);
			break;
		default:
			system("cls");
			printf("Unavailable option\n\n");
			queenMenu(q);
	}
}

void queenInic()
{
	queen q;
	char x;
	int n;

	system("cls");
	puts("Queen's problem");

	q.n = chessDimension();
	createChessboard(&q);
	fillZero(&q);
	
	queenMenu(&q);

	freeQueen(&q);
}
