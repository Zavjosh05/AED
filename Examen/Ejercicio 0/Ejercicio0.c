#include<stdio.h>

void presentacion(int);

int main(void)
{
    int *x = NULL, *y = NULL, *z = NULL;
    int **u = NULL, **v = NULL, **w = NULL;
    int a, b = 1, c = 2, d = 3, e = 4, f = 5;
    int boleta = 2024630163;

    presentacion(0);

    printf("\na = %d %% 6\n",boleta);
    a = boleta % 6;
    printf("a = %d\n\n");

    x = &f; y = &e; z = &d;
    a *= *z; b += *y - 42; c -= 13 * (*x);
    u = &x; y = *u; *y = 3*f;
    v = &y; w = &z; u = w; w = v; v = &x;
    **u = a + 1; **v = b + 2;
    **w = c + 3;

    puts("Resultados:");
    puts("Enteros:");
    printf("a = %d\nb = %d\nc = %d\nd = %d\ne = %d\nf = %d\n",a,b,c,d,e,f);
    puts("\nApuntadores a enteros:");
    printf("x = %X\n*x = %d\n\ny = %X\n*y = %d\n\nz = %X\n*z = %d\n",x,*x,y,*y,z,*z);
    puts("\nApuntadores dobles a enteros:");
    printf("u = %X\n*u = %X\n**u = %d\n\nv = %X\n*v = %X\n**v = %d\n\nw = %X\n*w = %X\n**w = %d",u,*u,**u,v,*v,**v,w,*w,**w);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Primer examen de estructura de datos");
    printf("Ejercicio No. %d\n\n", n);
}