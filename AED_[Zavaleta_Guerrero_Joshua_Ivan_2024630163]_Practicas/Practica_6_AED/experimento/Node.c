#ifndef NODE_C
#define NODE_C
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *before;
    struct node *next;
    char element;
}*Node, Size_node;

void mensajeNodo(int n)
{                   //   0                  1                 2                
    char *msj[] = {"\nNodo nulo\n","\nNodo liberado\n","\nNodo creado\n"};
    printf("%s\n",*(msj+n));
}

int createNode(Node *x)
{
    *x = (Node)malloc(sizeof(Size_node));
    
    if(*x == NULL)
    {
        mensajeNodo(0); 
        return 0;
    }
    
    mensajeNodo(5);
    return 1;
}

int freeNode(Node *x)
{
    if(*x == NULL)
    {
        mensajeNodo(0);
        return 0;
    }

    free(*x);
    *x = NULL;
    mensajeNodo(1);

    return 1;
}

int initializeNode(Node x)
{
    if(x == NULL) 
    {
        mensajeNodo(0);
        return 0;
    }
    x->before = NULL;
    x->next = NULL;
    x->element = 0;

    return 1;
}

int printInfoNode(Node y)
{
    if(y == NULL)
    {
        mensajeNodo(0);
        return 0;
    }

    printf("%c ",y->element);
    return 1;
}

int printDataNode(Node y)
{
    if(y == NULL)
    {
        mensajeNodo(0);
        return 0;
    }

    printf("Nodo: %X, dato: %d, before: %X, next: %X\n",y,y->element,y->before,y->next);
    return 1;
}

int insertInfoNode(Node y)
{
    if(y == NULL)
    {
        mensajeNodo(0);
        return 0;
    }

    char x;

    fseek(stdin,0,SEEK_END);
    puts("Ingrese el elemento a añadir:");
    scanf("%c",&x);
    y->element = x;

    return 1;
}

int randomNodeGenerator(Node *y,int n)
{
    #ifdef NDEBUG
        srand(time(NULL));
    #endif

    createNode(y);
    if(*y == NULL)
    {
        mensajeNodo(0);
        return 0;
    }

    initializeNode(*y);
    (*y)->element = rand()%n;
    return 1;
}

#endif