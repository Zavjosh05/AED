//Practica 1
//2BM2 Zavaleta Guerrero Joshua Ivan
//Compilarse junto a files.c
#include<stdio.h>
#include<stdlib.h>
#include"files.h"

void presentacion(int);

//Ingresar el nombre del archivo al ejecutar el programa en la terminal
int main(int argc, char *argv[])
{
	presentacion(1);

	sortFile(++argv);	
	
	return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}
