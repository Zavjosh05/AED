#include<stdio.h>
#include<stdlib.h>
#include"files.h"

void presentacion(int);

int main(int argc, char **argv)
{
    presentacion(3);
    sortFile(++argv);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}