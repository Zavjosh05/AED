#include<stdio.h>
#include"lista.h"
#include"nodo.h"
#include"elemento.h"

void presentacion(int);
void mSortProcess_Lista(Lista,int,int);
void mergeSortStr_R_Listas(Lista,int,int);
void menu(Lista);

int main(void)
{
    Lista list;

    presentacion(7);

    crearLista(&list);
    menu(list);
    destruirLista(&list);

    return 0;
}

void presentacion(int n)
{
    system("cls");
    puts("Zavaleta Guerrero Joshua Ivan\nBoleta = 2024630163\nGrupo: 2BM2");
    printf("Practica No. %d\n\n", n);
}

void mSortProcess_Lista(Lista arr, int posInf, int posSup)
{
    int i,j,k,l = posSup-posInf, middle;
    Lista aux;
    Elemento elem1,elem2;

    crearLista(&aux);

    i = posInf;
    if(l == 1)
        j = posInf + 1;
    else
        j = posInf + l/2;
    middle = j;
    k = 0;

    //printf("posInf: %d, posSup: %d, middle: %d\n",posInf,posSup,middle);
    //puts("arr:");
    //imprimirLista(arr);
    while(k <= l)
    {
        //puts("aux:");
        //imprimirLista(aux);
        crearElemento(&elem1);
        crearElemento(&elem2);
        consultarElementoPosicion(arr,&elem1,i);
        consultarElementoPosicion(arr,&elem2,j);
        //printf("elem1: %c elem2: %c,i = %d, j = %d, k = %d, l = %d\n",elem1->dato,elem2->dato,i,j,k,l);
        if(i < middle && j <= posSup)
        {
            if(elem1->dato >= elem2->dato)
            {
                insertarElementoPosicionVariante(aux,elem2,k);
                k++;
                j++;
            }
            else
            {
                insertarElementoPosicionVariante(aux,elem1,k);
                k++;
                i++;
            }
        }
        else
            if(i < middle)
            {
                insertarElementoPosicionVariante(aux,elem1,k);
                i++;
                k++;
            }
            else
                if(j <= posSup)
                {
                    insertarElementoPosicionVariante(aux,elem2,k);
                    j++;
                    k++;
                }
    }

    //puts("aux final");
    //imprimirLista(aux);
    for(i = posInf, k = 0; k <= l; k++, i++)
    {
        consultarElementoPosicion(aux,&elem1,k);
        cambiarElementoPosicion(arr,elem1,i);
    }
    //puts("arr final:");
    //imprimirLista(arr);

    elem1 = NULL; elem2 = NULL;
    destruirLista(&aux);
}

void mergeSortStr_R_Listas(Lista arr, int posInf, int posSup)
{
    int x; 

    if(posSup-posInf >= 1)
    {
        x = (posSup - posInf)/2;

        if(posSup-posInf >= 2)
        {
            mergeSortStr_R_Listas(arr,posInf,posInf+x-1);
            mergeSortStr_R_Listas(arr,posInf+x,posSup);
        }
        mSortProcess_Lista(arr,posInf,posSup);
    }  
}

void menu(Lista list)
{
    int sel, n;
    char i1,i2;

    printf("Lista: ");
    imprimirLista(list);
    puts("Seleccione una opcion\n(1) Generar lista aleatoria\n(2) Vaciar lista\n(3) Merge\n(4) salir\n");
    fseek(stdin,0,SEEK_END);
    scanf("%d",&sel);
    
    system("cls");
    switch(sel)
    {
        case 1:
            redo:;
            puts("Seleccione el numero de elementos a insertar");
            fseek(stdin,0,SEEK_END);
            scanf("%d",&n);
            if(n <= 0)
            {
                puts("Ingrese un numero valido");
                goto redo;
            }
            redo2:;
            puts("Ingrese los limites de los elementos (los elementos son chars) y i1<i2");
            fseek(stdin,0,SEEK_END);
            printf("i1: ");
            scanf("%c",&i1);
            fseek(stdin,0,SEEK_END);
            printf("i2: ");
            scanf("%c",&i2);
            printf("%d %d\n",i1,i2);
            if(i1 > i2)
            {
                puts("Ingrese un intervalo valido");
                goto redo2;
            }
            generarListaAleatoria(list,n,i1,i2);
            putchar('\n');
            break;
        case 2:
            puts("Vaciando lista");
            vaciarLista(list);
            break;
       
        case 3:
            system("cls");
            puts("Original: ");
            imprimirLista(list);
            puts("Sorteo por MergeSort:");
            mergeSortStr_R_Listas(list,0,list->longitud-1);
            imprimirLista(list);
            putchar('\n');
            break;
        case 4:
            goto fin;
        default:
            puts("Ingrese una opcion valida");
            menu(list);
            goto fin;
    }
    menu(list);

    fin:;
}