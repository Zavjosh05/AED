#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *before;
    struct node *next;
    int element;
}*Node, Size_node;

typedef struct stack
{
    Node first;
    Node last;
    int lenght;
}*Stack, Size_stack;

int createNode(Node*);
int freeNode(Node*);
int createStack(Stack*);
int freeStack(Stack*);
int initializeNode(Node);
int initializeStack(Stack);
int printInfoNode(Node);
int printDataNode(Node);
int printStack(Stack);
int printDataStack(Stack);
int insertInfoNode(Node);
int circularStackAddNode(Stack,Node);
void menu(Stack);
void mensaje(int);

int main(void)
{
    Stack x;
    Node y,yy;

    createStack(&x);
    initializeStack(x);
    printf("lenght: %d\n",x->lenght);
    menu(x);

    freeStack(&x);

    return 0;
}

int createNode(Node *x)
{
    *x = (Node)malloc(sizeof(Size_node));
    
    if(*x == NULL)
    {
        mensaje(1); 
        return 0;
    }
    
    mensaje(5);
    return 1;
}

int freeNode(Node *x)
{
    if(*x == NULL)
    {
        mensaje(1);
        return 0;
    }

    free(*x);
    *x = NULL;
    mensaje(3);

    return 1;
}

int createStack(Stack *x)
{
    *x = (Stack)malloc(sizeof(Size_stack));

    if(*x == NULL) 
    {
        mensaje(2);
        return 0;
    }

    mensaje(6);
    return 1;
}

int freeStack(Stack *x)
{
    if(*x == NULL)
    {
        mensaje(2);
        return 0;
    }

    free(*x);
    *x = NULL;
    mensaje(4);

    return 1;
}

int initializeNode(Node x)
{
    if(x == NULL) 
    {
        mensaje(1);
        return 0;
    }
    x->before = NULL;
    x->next = NULL;
    x->element = 0;

    return 1;
}

int initializeStack(Stack x)
{
    if(x == NULL)
    {
        mensaje(2); 
        return 0;
    }

    x->first = NULL;
    x->last = NULL;
    x->lenght = 0;

    return 1;
}

int printInfoNode(Node y)
{
    if(y == NULL)
    {
        mensaje(1);
        return 0;
    }

    printf("Info nodo: %d\n",y->element);
    return 1;
}

int printDataNode(Node y)
{
    if(y == NULL)
    {
        mensaje(1);
        return 0;
    }

    printf("Nodo: %X, dato: %d, before: %X, next: %X\n",y,y->element,y->before,y->next);
    return 1;
}

int printStack(Stack x)
{
    if(x == NULL)
    {
        mensaje(2);
        return 1;
    }

    int i;
    Node aux;
    aux = x->first;

    if(x->lenght == 0)
        printf("<>\n");
    else
        for(i = 0; i < x->lenght; i++)
        {
            if(i == 0) printf("< ");
        
            if(i == x->lenght-1)
                printf("%d >\n",aux->element);
            else
                printf("%d, ",aux->element);
            
            aux = aux->next;
        }

    return 1;
}

int printDataStack(Stack x)
{
    if(x == NULL)
    {
        mensaje(2);
        return 1;
    }

    printf("Stack: first: %X, last: %X, lenght: %d\n",x->first,x->last,x->lenght);
    return 1;
}

int insertInfoNode(Node y)
{
    if(y == NULL)
    {
        mensaje(1);
        return 0;
    }

    int x;

    fseek(stdin,0,SEEK_END);
    puts("Ingrese el elemento a añadir:");
    scanf("%d",&x);
    y->element = x;

    return 1;
}

int circularStackAddNode(Stack x,Node y)
{
    if(x == NULL && y == NULL)
    {
        mensaje(1);
        mensaje(2);
        return 0;
    }
    else
        if(x == NULL)
        {
            mensaje(2);
            return 0;
        }
        else
            if(y == NULL)
            {
                mensaje(1);
                return 0;
            }

    int ind,i;
    Node aux,aux2;

    if(x->lenght == 0)
    {
        y->before = y;
        y->next = y;
        x->first = y;
        x->last = y;
        x->lenght++;
    }
    else
    {
        aux = x->first;
        ind = 1;
        while(ind)
        {
            if(aux->element < y->element)
            {
                if(aux == x->first)
                {
                    x->first = y;
                    x->last = y;
                    y->next = aux;
                    y->before = aux->before;
                    aux->before = y;
                    if(x->lenght == 1)
                        aux->next = y;
                    x->lenght++;
                    ind = 0;
                }
                else
                {
                    y->next = aux;
                    y->before = aux->before;
                    aux->before = y;
                    y->before->next = y;
                    x->lenght++;
                    ind = 0;
                }
            }
            else
                if(x->lenght == 1)
                {
                    y->next = x->last;
                    y->before = x->first;
                    x->first->next = y;
                    x->last->before = y;
                    x->lenght++;
                    ind = 0;
                }
                else
                    if(aux == x->last->before)
                    {
                        y->next = aux->next;
                        aux->next = y;
                        y->before = aux;
                        x->lenght++;
                        ind = 0;
                    }
            aux = aux->next;
        }
    }

    return 1;
}

void menu(Stack x)
{
    int sel, ind = 1;

    
    puts("Desea:\n(1) Agregar un elemento\n(2) Eliminar un elemento\n(3) consumir cola");
    fseek(stdin,0,SEEK_END);
    scanf("%d",&sel);

    switch(sel)
    {
        case 1:
            Node y;
            createNode(&y);
            initializeNode(y);
            insertInfoNode(y);
            printInfoNode(y);
            circularStackAddNode(x,y);
            printDataNode(y);
            printDataStack(x);
            printStack(x);
            break;
        case 2:
            break;
        case 3:
            break;
        default:
            mensaje(0);
            menu(x);
            goto fin;
    }

    puts("Desea hacer otra accion? (y/n)");
    fseek(stdin,0,SEEK_END);
    if(getchar() == 'y' || getchar() == 'Y')
        menu(x);
    
    fin:;
}

void mensaje(int n)
{
    char *msj[] = {"\nIngrese una opcion valida\n","\nNodo nulo\n","\nStack nulo\n","\nNodo liberado\n","\nStack liberado\n","\nNodo creado\n","\nStack creado"};
    printf("%s\n",*(msj+n));
}