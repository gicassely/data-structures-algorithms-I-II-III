#include <stdio.h>

int bushcao(int x, int v[],int a,int b)
{
	if(v[b] <= x || a>b) return b;
	if(v[b] > x) return bushcao(x,v,a,b-1);
 	return -1;
}

int main()
{
	int i,v[100];
	for(i = 0;i < 100;i++) v[i] = i;
	printf("%d\n",bushcao(9,v,1,10));
	printf("%d\n",bushcao(25,v,75,99));
	printf("%d\n",bushcao(100,v,0,99));
	return 0;
}
