#include <stdio.h>

inline int bushca(int x,int v[],int a,int b)
{
	if(v[b] == x) return b;
	if(a==b) return -1;
	return bushca(x,v,a,b-1);
}

int main()
{
	int i,a[100];
	for(i = 0;i < 100;i++) a[i] = i*3;
	printf("%d\n",bushca(24,a,0, 99));
	printf("%d\n",bushca(24,a,25, 37));
	return 0;
}
