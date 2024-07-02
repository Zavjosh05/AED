#include<stdio.h>
#include"elemento.h"
#include"nodo.h"
#include"pila.h"

void presentacion(int);
void menu(char*);
void fillZeroArrChar(char*, int);
int contadorDeCaracteresNoAgrupadores(char*);
int contadorDeCaracteres(char*);
int esOperadorOAgrupador(char);
int hayAgrupadoresCerrados(Pila);
char* invertirString(char*);
char* infijaToPrefija(char*);
char* infijaToPostfija(char*);

int main(void)
{
    char expresion[] = {"<<x+<y*<l/t>>>+<y-z>>"};

    presentacion(6);

    menu(expresion);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}

void menu(char *expresion)
{
    int sel;

    printf("%s\n",expresion);
    puts("Elija una opcion\n(1) Prefija\n(2) Postfija\n");
    fseek(stdin,0,SEEK_END);
    scanf("%d",&sel);

    switch(sel)
    {
        case 1:
            expresion = infijaToPrefija(expresion);
            printf("%s\n",expresion);
            break;
        case 2:
            expresion = infijaToPostfija(expresion);
            printf("%s\n",expresion);
            break;
        case 3:
            goto fin;
        default:
            puts("Ingrese una opcion valida");
            menu(expresion);
    }
    fin:;
}

void fillZeroArrChar(char *arr, int n)
{
    int i;

    for(i = 0; i < n; i++)
        *(arr+i) = 0;
}


int contadorDeCaracteresNoAgrupadores(char *arr)
{
    int i = 0, j = 0;

    while(*(arr+i) != '\0')
    {
        if(*(arr+i) != '(' && *(arr+i) != ')')
            if(*(arr+i) != '<' && *(arr+i) != '>')
                if(*(arr+i) != '{' && *(arr+i) != '}')
                    if(*(arr+i) != '[' && *(arr+i) != ']')
                        j++;
        i++;
    }

    return j;
}

int contadorDeCaracteres(char *arr)
{
    int i = 0;

    while(*(arr+i) != '\0')
        i++;

    return i;
}

int esOperadorOAgrupador(char chr)
{
    if(chr == '(' || chr == ')' || chr == '<' || chr == '>' || chr == '{' || chr == '}' || chr == '[' || chr == ']')
        return 1;
    else
        if(chr == '+' || chr == '-' || chr == '*' || chr == '/' || chr == '^')
            return 1;
        else
            return 0;
}

int hayAgrupadoresCerrados(Pila p)
{
    if(p->longitud <= 2) return 0;

    int i = p->longitud, ind = 1;
    Nodo aux;
    Elemento elem;

    aux = p->tope;
    elem = aux->elem;
    while(ind)
    {
        if(elem->dato == '<' || elem->dato == '>')
        {
            if(elem->dato == '<')
            {
                iniciodenuevo:;
                aux = aux->enlaceA;
                elem = aux->elem;
                if(elem->dato == '>') return 1;
                if(aux == p->base) goto fin;
                else goto iniciodenuevo;
            }
            if(elem->dato == '>')
            {
                iniciodenuevo2:;
                aux = aux->enlaceA;
                elem = aux->elem;
                if(elem->dato == '<') return 1;
                if(aux == p->base) goto fin;
                else goto iniciodenuevo2;
            }
        }
        if(aux == p->base)
            ind = 0;
        else
        {
            aux = aux->enlaceA;
            elem = aux->elem;
        }
    }
    fin: return 0;
}

char* invertirString(char *arr)
{
    int i,j, k;
    char *aux, *aux1;

    i = contadorDeCaracteres(arr);
    aux = (char*)malloc((i+1)*sizeof(char));
    fillZeroArrChar(aux,i);
    *(aux + i) = '\0';

    for(j = 0, k = i-1; j < i, k >=0; j++, k--)
        *(aux+j) = *(arr+k);

    free(arr);
    
    return aux;
}

char* infijaToPrefija(char *expresion)
{
    int i, j, k, i1, i2, ind = 1;
    char *expresionFinal;
    Pila stack;
    Nodo aux;
    Elemento elem;
    puts("hola");

    k = 0;
    j = contadorDeCaracteres(expresion);
    j--;
    i = contadorDeCaracteresNoAgrupadores(expresion);
    printf("i: %d, j: %d, k: %d\n",i,j,k);
    expresionFinal = (char*) malloc((i+1)*sizeof(char));
    *(expresionFinal + i) = '\0';
    fillZeroArrChar(expresionFinal, i);
    crearPila(&stack);
    crearElemento(&elem);

    while(ind)
    {
        if(j >= 0 && k < i)
            if(esOperadorOAgrupador(*(expresion+j)))
            {
                escribirDato(elem,*(expresion+j));
                insertarElemento(stack,elem);
                imprimirPila(stack);
                if(hayAgrupadoresCerrados(stack))
                {
                    quitarTope(stack);
                    *(expresionFinal+k) = stack->tope->elem->dato;
                    k++;
                    quitarTope(stack);
                    quitarTope(stack);
                    imprimirPila(stack);
                }
                j--;
                elem = NULL;
                crearElemento(&elem);
            }
            else
            {
                *(expresionFinal+k) = *(expresion+j);
                k++;
                j--;
            }
        else ind = 0;
    }

    expresionFinal = invertirString(expresionFinal);

    return expresionFinal;

    destruirPila(&stack);
}

char* infijaToPostfija(char *expresion)
{
    int i, j,jj, k, i1, i2, ind = 1;
    char *expresionFinal;
    Pila stack;
    Nodo aux;
    Elemento elem;
    puts("hola");

    k = 0;
    j = contadorDeCaracteres(expresion);
    //j--;
    jj = 0;
    i = contadorDeCaracteresNoAgrupadores(expresion);
    printf("i: %d, j: %d, k: %d\n",i,j,k);
    expresionFinal = (char*) malloc((i+1)*sizeof(char));
    *(expresionFinal + i) = '\0';
    fillZeroArrChar(expresionFinal, i);
    crearPila(&stack);
    crearElemento(&elem);

    while(ind)
    {
        if(jj < j && k < i)
            if(esOperadorOAgrupador(*(expresion+jj)))
            {
                escribirDato(elem,*(expresion+jj));
                insertarElemento(stack,elem);
                imprimirPila(stack);
                if(hayAgrupadoresCerrados(stack))
                {
                    quitarTope(stack);
                    *(expresionFinal+k) = stack->tope->elem->dato;
                    k++;
                    quitarTope(stack);
                    quitarTope(stack);
                    imprimirPila(stack);
                }
                jj++;
                elem = NULL;
                crearElemento(&elem);
            }
            else
            {
                *(expresionFinal+k) = *(expresion+jj);
                k++;
                jj++;
            }
        else ind = 0;
    }

    return expresionFinal;

    destruirPila(&stack);
}