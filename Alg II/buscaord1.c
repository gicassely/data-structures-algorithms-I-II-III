#include <stdio.h>
#include <stdlib.h>

int busca(int x,int v[],int a,int b)
{
        if (v[a] = x)
                return a;
        if (a=b)
                return -1;
        return busca(x,v,a+1,b);
}
int main()
{
        int v[30];
        int i;
        int a;
        int b;
        int x;
        a=0;
        i=0;
        printf("Entre com o tamanho do vetor:");
        scanf("%d",&b);
        for (a=0;i<b;i++)
                scanf("%d",&v[i]);
        printf("Escolha um numero:");
        scanf("%d",&x);
        busca(x,v,a,b);
        printf("%d\n",a);
        return 1;

}

