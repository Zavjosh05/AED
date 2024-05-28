//Practica 1
//2BM2 Zavaleta Guerrero Joshua Ivan
//Compilarse junto a files.c
#include<stdio.h>
#include"files.h"

//Ingresar el nombre del archivo al ejecutar el programa en la terminal
int main(int argc, char *argv[])
{
	sortFile(++argv);	
	
	return 0;
}
