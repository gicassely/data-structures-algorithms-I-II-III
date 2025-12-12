#include <stdio.h>
#include <stdlib.h>


int buscaseq(int x, int v[],int a,int b)
{

	if (a > b)
		return a - 1;
	if (x >= v[b])
		return b;
	return buscaseq(x,v,a,b - 1);
}



int main(void)
{
	int x;
	printf("Entre com o numero \n");
	scanf("%d", &x);
	int i;
	int v[10] = {5,9,7,3,2,6,8,10,14,30};
	i = buscaseq(x,v,0,9);
	printf("%d \n",i);
}

