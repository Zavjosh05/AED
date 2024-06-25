#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct complex
{
    float real;
    float complejo;
    //forma polar
    float r;
    float angulo;
} *Complex, Size_complex;

void presentacion(int n);
void crearComplejo(Complex*);
void crearArregloComplejos(Complex*,int n);
void crearTablaComplejos(Complex**,int);
void imprimirDatosComplejo(Complex);
void imprimirComplejoCartesiano(Complex);
void imprimirComplejoPolar(Complex);
void imprimirComplejoPolarTabla(Complex);
void imprimirArregloComplejos(Complex,int);
void imprimirTablaComplejos(Complex*,int);
void complejoCartesianoAPolar(Complex);
void complejoPolarACartesiano(Complex);
void ingresarComplejoCartesiano(Complex);
void ingresarComplejoPolar(Complex);
void menu(Complex);
void numeroDeRaices(Complex,Complex**,int);

int main(void)
{
    Complex x = NULL;
    Complex *raices;
    int n;

    presentacion(4);

    crearComplejo(&x);
    menu(x);
    imprimirDatosComplejo(x);
    fseek(stdin,0,SEEK_END);
    puts("Ingresar el numero de raices");
    scanf("%d",&n);

    numeroDeRaices(x,&raices,n);

    return 0;
}

void crearComplejo(Complex *a)
{
    *a = (Complex)malloc(sizeof(Size_complex));
    (*a)->real = 0;
    (*a)->complejo = 0;
    (*a)->r = 0;
    (*a)->angulo = 0;
}

void crearArregloComplejos(Complex *a, int n)
{
    *a = (Complex)malloc(n*sizeof(Size_complex));
}

void crearTablaComplejos(Complex **a,int n)
{
    int i;

    *a = (Complex*)malloc(n*sizeof(Complex));

    for(i = 0; i < n; i++)
        *(*a + i) = (Complex)malloc(n*sizeof(Size_complex));
}

void imprimirDatosComplejo(Complex x)
{
    printf("Forma cartesiana: %.2f + i%.2f\n",x->real,x->complejo);
    printf("Forma polar: %.2fe^i%.2f\n",x->r,x->angulo);
    putchar('\n');
}

void imprimirComplejoCartesiano(Complex x)
{
    printf("%.2f + i%.2f\n",x->real,x->complejo);
}

void imprimirComplejoPolar(Complex x)
{
    printf("%.2fe^i%.2f\n",x->r,x->angulo);
}

void imprimirComplejoPolarTabla(Complex x)
{
    printf("%.2fe^i%.2f ",x->r,x->angulo);
}

void imprimirArregloComplejos(Complex x, int n)
{
    int i;

    puts("\nArreglo de raices");

    for(i = 0; i < n; i++)
        printf("z%d = %.2fe^i%.2f ",i,(x+i)->r,(x+i)->angulo);
    putchar('\n');
}

void imprimirTablaComplejos(Complex *x, int n)
{
    int i,j;

    puts("Tabla de Complejos");

    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            for(j = 0; j < n; j++)
                if(j==0)
                    printf("\tz%d",j);
                else
                    printf("          z%d",j);
            putchar('\n');
        }
        for(j = 0; j < n; j++)
        {
            if(j == 0)
                printf("z%d ",i);
            imprimirComplejoPolarTabla((*(x+i)+j));
        }
        putchar('\n');
    }
}

void complejoCartesianoAPolar(Complex a)
{
    a->r = (float)sqrt((a->real*a->real)+(a->complejo*a->complejo));
    a->angulo = (float)atan(a->complejo/a->real);
}

void complejoPolarACartesiano(Complex a)
{
    a->real = (float)a->r*cos(a->angulo);
    a->complejo = (float)a->r*cos(a->angulo);
}

void ingresarComplejoCartesiano(Complex a)
{
    float i,r;

    fseek(stdin,0,SEEK_END);
    puts("Ingresa la parte real del complejo");
    scanf("%f",&r);
    a->real = r;
    puts("Ingresa la parte imaginaria del complejo");
    scanf("%f",&i);
    a->complejo = i;
    complejoCartesianoAPolar(a);
    imprimirComplejoCartesiano(a);
    putchar('\n');
}

void ingresarComplejoPolar(Complex a)
{
    float r,angulo;

    fseek(stdin,0,SEEK_END);
    puts("Ingresa el coeficiente");
    scanf("%f",&r);
    a->r = r;
    puts("Ingresa el angulo (en radianes)");
    scanf("%f",&angulo);
    a->angulo = angulo;
    complejoPolarACartesiano(a);
    imprimirComplejoPolar(a);
    putchar('\n');
}

void menu(Complex x)
{
    int d;

    fseek(stdin,0,SEEK_END);
    puts("Elegir el tipo de complejo a insertar\nForma cartesiana(0)\nForma polar(1)\n");
    scanf("%d",&d);
    switch(d)
    {
        case 0:
            ingresarComplejoCartesiano(x);
            break;
        case 1:
            ingresarComplejoPolar(x);
            break;
        default:
            printf("Ingrese una opcion valida\n");
            system("cls");
            menu(x);
    }
    putchar('\n');
}

void numeroDeRaices(Complex x,Complex **tab, int n)
{
    Complex raices;
    int i,j,d;
    float m, pi = 3.1415927;

    crearArregloComplejos(&raices,n);
    crearTablaComplejos(tab,n);

    m = pi/n;//Calculo de suma de angulos

    for(i = 0; i < n; i++)
    {
        if(i == 0)
        {
            raices->r = x->r;
            raices->angulo = x->angulo;
            complejoPolarACartesiano(raices);
        }
        else
        {
            (raices + i)->r = raices->r;
            (raices+i)->angulo = (raices+i-1)->angulo+m;
            complejoPolarACartesiano(raices+i);
        }
    }

    imprimirArregloComplejos(raices,n);
    putchar('\n');

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            d = (i+j)%n;
            (*(*tab+i)+j)->r = (raices+d)->r;
            (*(*tab+i)+j)->angulo = (raices+d)->angulo;
            complejoPolarACartesiano(*(*tab+i)+j);
        }
    }

    imprimirTablaComplejos(*tab,n);
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    puts("Practica");
    printf("Practica No. %d\n\n", n);
}