#include <stdio.h>
#include <stdlib.h>

int a,b;

int main (void)
{
int aux;
scanf("%d %d", &a,&b);
aux=a;
a=b;
b=aux;
printf("%d \n %d\n",a,b);
}


