#include<stdio.h>
#include<stdlib.h>
#include"Node.h"

//stack:   NULL//<-before-base-next->...<-before-top-next->//NULL
typedef struct stack
{
    Node base;
    Node top;
    int lenght;
}*Stack, Size_stack;

int createStack(Stack*);
int freeStack(Stack*);
int initializeStack(Stack);
int printStack(Stack);
void mensajeStack(int);
void menu(Stack);
void presentacion(int);

int main(void)
{

    presentacion(6);

    Stack x;

    createStack(&x);
    initializeStack(x);
    menu(x);

    freeStack(&x);

    return 0;
}

int createStack(Stack *x)
{
    *x = (Stack) malloc(sizeof(Size_stack));
    if(*x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    return 1;
}

int freeStack(Stack *x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    free(x);
    x = NULL;

    return 1;
}

int initializeStack(Stack x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    x->base = NULL;
    x->top = NULL;
    x->lenght = 0;

    return 1;
}

int printStack(Stack x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    int i;
    Node aux;
    aux = x->base;

    if(x->lenght == 0)
        printf("<>\n");
    else
        for(i = 0; i < x->lenght; i++)
        {
            if(i == 0) printf("< ");

            if(i == x->lenght-1)
                printf("%c >\n",aux->element);
            else
                printf("%c, ",aux->element);
            aux = aux->next;
        }

    return 1;
}

int printDataStack(Stack x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    printf("Stack: Top: %X, Base: %X, lenght: %d\n",x->top,x->base,x->lenght);
    return 1;
}

int printAllDataStack(Stack x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }

    int i;
    Node aux;

    aux = x->base;
    for(i = 0; i < x->lenght; i++)
    {
        printDataNode(aux);
        aux = aux->next;
    }

    return 1;
}

int stackAddNode(Stack x,Node y)
{
    if(x == NULL && y == NULL)
    {
        mensajeStack(0);
        mensajeNodo(0);
        return 0;
    }
    else
        if(x == NULL)
        {
            mensajeStack(0);
            return 0;
        }
        else
            if(y == NULL)
            {
                mensajeNodo(0);
                return 0;
            }

    Node aux;
    int ind;
    if(x->lenght == 0)
    {
        x->base = y;
        x->top = y;
        y->before = NULL;
        y->next = NULL;
        x->lenght++;
    }
    else
        if(x->lenght == 1)
        {
            x->base->next = y;
            y->before = x->base;
            y->next = NULL;
            x->top = y;
            x->lenght++;
        }
        else
            {
                aux = x->base->next;
                ind = 1;
                while(ind)
                {
                    if(aux == x->top)
                    {
                        aux->next = y;
                        y->before = aux;
                        y->next = NULL;
                        x->top = y;
                        x->lenght++;
                        ind = 0;
                    }
                    aux = aux->next;
                }
                
            }

    return 1;
}

int stackDelNode(Stack x)
{
    if(x == NULL)
    {
        mensajeStack(0);
        return 0;
    }
        
    Node aux;

    aux = x->top;
    x->top = x->top->before;
    x->top->before->next = NULL;
    x->top = 
    x->lenght--;
    freeNode(&aux);

    if(aux != NULL)
    {
        puts("Elminiacion fallida");
        return 0;
    }

    return 1;
}

void mensajeStack(int n)
{                   //   0                  1                 2                
    char *msj[] = {"\nStack nulo\n","\nStack liberado\n","\nStack creado\n"};
    printf("%s\n",*(msj+n));
}

void menu(Stack x)
{
    int sel;

    printf("Stack: ");
    printStack(x);
    printf("lenght: %d\n",x->lenght);
    puts("Desea:\n(1) Agregar un elemento\n(2) Eliminar tope\n(3) Generar elementos aleatorios\n(4) Consumir Stack\n(5) Datos de Stack\n(6) Datos de los nodos del Stack\n(7) salir");
    fseek(stdin,0,SEEK_END);
    scanf("%d",&sel);
    fseek(stdin,0,SEEK_END);

    system("cls");
    switch(sel)
    {
        case 1:
            Node y;
            createNode(&y);
            initializeNode(y);
            insertInfoNode(y);
            printInfoNode(y);
            stackAddNode(x,y);
            printAllDataStack(x);
            break;
        case 2:
            puts("Eliminando el tope");
            stackDelNode(x);
            break;
        case 7:
            goto fin;
            break;
        default:
            puts("Select an existing option");
            menu(x);
            break;
    }
    menu(x);

    fin:;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}