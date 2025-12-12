#include <stdio.h>

int buscabin(int x, int v[], int a, int b)
{
	int m;
	if (a > b)
		return a - 1;
	m = (a+b)/2;
	if (x < v[m])
		return buscabin(x,v,a,m-1);
	return buscabin(x,v,m+1,b);
}

int main(void)
{
	int x;
	printf("Entre com o numero \n");
	scanf ("%d", &x);
	int i;
	int v[10] = {5,9,7,3,2,6,8,10,14,30};
	i = buscabin(x,v,0,9);
	printf("%d \n", i);
}
