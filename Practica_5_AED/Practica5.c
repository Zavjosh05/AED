#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *before;
    struct node *next;
    int element;
}*Node, Size_node;

typedef struct queue
{
    Node first;
    Node last;
    int lenght;
}*Queue, Size_Queue;

void presentacion(int);
int createNode(Node*);
int freeNode(Node*);
int createQueue(Queue*);
int freeQueue(Queue*);
int initializeNode(Node);
int initializeQueue(Queue);
int printInfoNode(Node);
int printDataNode(Node);
int printQueue(Queue);
int printDataQueue(Queue);
int printAllDataQueue(Queue);
int insertInfoNode(Node);
int circularQueueAddNode(Queue,Node);
int circularQueueDeleteNode(Queue,int);
int randomNodeGenerator(Node*,int);
int circularRandomQueueGenerator(Queue);
int circularQueueEraser(Queue,int);
void menu(Queue);
void mensaje(int);

int main(void)
{
    Queue x;
    Node y;

    presentacion(5);

    createQueue(&x);
    initializeQueue(x);
    menu(x);

    freeQueue(&x);

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

int createQueue(Queue *x)
{
    *x = (Queue)malloc(sizeof(Size_Queue));

    if(*x == NULL) 
    {
        mensaje(2);
        return 0;
    }

    mensaje(6);
    return 1;
}

int freeQueue(Queue *x)
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

int initializeQueue(Queue x)
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

int printQueue(Queue x)
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

int printDataQueue(Queue x)
{
    if(x == NULL)
    {
        mensaje(2);
        return 1;
    }

    printf("Queue: first: %X, last: %X, lenght: %d\n",x->first,x->last,x->lenght);
    return 1;
}

int printAllDataQueue(Queue x)
{
    if(!printDataQueue)
        return 0;
    
    int i;
    Node aux;

    aux = x->first;
    for(i = 0; i < x->lenght; i++)
    {
        printDataNode(aux);
        aux = aux->next;
    }

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

int circularQueueAddNode(Queue x,Node y)
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

    int ind;
    Node aux;

    if(x->lenght == 0)
    {
        y->before = y;
        y->next = y;
        x->first = y;
        x->last = y;
        x->lenght++;
        puts("1");
    }
    else
    {
        aux = x->first;
        ind = 1;
        while(ind)
        {
            if(aux->element <= y->element)
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
                    puts("2");
                    ind = 0;
                }
                else
                {
                    y->next = aux;
                    y->before = aux->before;
                    aux->before = y;
                    y->before->next = y;
                    x->lenght++;
                    puts("3");
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
                    puts("4");
                    ind = 0;
                }
                else
                    if(aux == x->last->before)
                    {
                        x->last->before = y;
                        y->next = aux->next;
                        aux->next = y;
                        y->before = aux;
                        x->lenght++;
                        puts("5");
                        ind = 0;
                    }
            /*if(ind == 0){
                printDataNode(y);
                printDataQueue(x);
                printDataNode(x->last->before);
            }*/
            aux = aux->next;
        }
    }

    return 1;
}

int circularQueueDeleteNode(Queue x, int x1)
{
    if(x == NULL)
    {
        mensaje(2);
        return 0;
    }
    if(x->lenght == 0)
    {
        mensaje(7);
        return 0;
    }
    if(x->lenght == 1)
    {
        puts("Queue vaciado");
        freeNode(&(x->first));
        x->first = NULL;
        x->last = NULL;
        x->lenght--;
        return 1;
    }

    int i;
    Node aux, aux2;

    aux = x->first;
    for(i = 0; i < x->lenght; i++)
    {
        if(aux->element == x1)
        {
            if(aux == x->first)
            {
                x->first = x->first->next;
                x->last = x->last->before;
                freeNode(&aux);
                x->lenght--;
                goto fin;
            }
            aux->before->next = aux->next;
            aux->next->before = aux->before;
            freeNode(&aux);
            x->lenght--;
            goto fin;
        }
        aux = aux->next;
    }
    if(i == x->lenght)
        puts("Elemento no encontrado");
    fin: return 1;
}

int randomNodeGenerator(Node *y,int n)
{
    #ifdef NDEBUG
        srand(time(NULL));
    #endif

    createNode(y);
    if(*y == NULL)
    {
        mensaje(2);
        return 0;
    }

    initializeNode(*y);
    (*y)->element = rand()%n;
    return 1;
}

int circularRandomQueueGenerator(Queue x)
{
    if(x == NULL)
    {
        mensaje(2);
        return 0;
    }

    int i,n;
    Node y;

    fseek(stdin,0,SEEK_END);
    puts("Ingrese el número de elementos a añadir");
    scanf("%d",&n);

    for(i = 0; i < n; i++)
    {
        randomNodeGenerator(&y,n);
        circularQueueAddNode(x,y);
        printQueue(x);
        
        y = NULL;
    }

    return 1;
}

//ind indica si se va a imprimir el proceso o no
int circularQueueEraser(Queue x, int ind)
{
    if(x == NULL)
    {
        mensaje(2);
        return 0;
    }

    int n = x->lenght, i;
    Node aux;

    for(i = 0; i < n; i++)
    {
        aux = x->first;
        if(ind)
            printQueue(x);
        circularQueueDeleteNode(x,aux->element);
        //aux = aux->next;
    }

    return 1;
}

void menu(Queue x)
{
    int sel, ind = 1, n, x1;

    printf("Cola: ");
    printQueue(x);
    printf("lenght: %d\n",x->lenght);
    puts("Desea:\n(1) Agregar un elemento\n(2) Eliminar un elemento\n(3) Generar elementos aleatorios\n(4) Consumir cola\n(5) Datos de Queue\n(6) Datos de los nodos del Queue\n(7) salir");
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
            circularQueueAddNode(x,y);
            //printDataNode(y);
            //printDataQueue(x);
            break;
        case 2:
            fseek(stdin,0,SEEK_END);
            printQueue(x);
            if(x->lenght == 1)
            {
                circularQueueDeleteNode(x,x1);
            }
            else
            {
                puts("Ingrese el elemento que desea eliminar");
                scanf("%d",&x1);
                circularQueueDeleteNode(x,x1);
            }
            break;
        case 3:
            circularRandomQueueGenerator(x);
            break;
        case 4:
            circularQueueEraser(x,1);
            break;
        case 5:
            printDataQueue(x);
            break;
        case 6:
            printAllDataQueue(x);
            break;
        case 7:
            circularQueueEraser(x,1);
            goto fin;
            break;
        default:
            mensaje(0);
            menu(x);
            goto fin;
    }
    menu(x);
    
    fin:;
}

void mensaje(int n)
{                   //           0                        1                 2                3                       4                5               6                        7                
    char *msj[] = {"\nIngrese una opcion valida\n","\nNodo nulo\n","\nQueue nulo\n","\nNodo liberado\n","\nQueue liberado\n","\nNodo creado\n","\nQueue creado\n","\nQueue sin elementos\n"};
    printf("%s\n",*(msj+n));
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}