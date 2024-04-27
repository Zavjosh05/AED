#include<stdio.h>
#include<stdlib.h>
#include"HyperInt.h"

int main()
{

	int ******arr, n;

	n = 2;

	Hyp6d(&arr,n,n,n,n,n,n);
	printf("Hyper %dD creado\n",n);
	InicH6(arr,n,n,n,n,n,n);
	printf("Hyper %dD iniciado\n",n);
	PrH6(arr,n,n,n,n,n,n);
	FillH6(arr,n,n,n,n,n,n);
	PrH6(arr,n,n,n,n,n,n);
	FreeH6(&arr,n,n,n,n,n);
	PrH6(arr,n,n,n,n,n,n);

	return 0;
}
