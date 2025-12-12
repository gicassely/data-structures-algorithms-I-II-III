#include<stdio.h>
int buscaBinRec(int vetor[],int ini,int fim,int pesq)
{
 while(ini<=fim)
 {
  int meio;
  meio=(ini+fim)/2;
  if(vetor[meio]==pesq)
  {
   return meio;
  }
  else if (vetor[meio]<pesq)
  {
   return buscaBinRec(vetor,meio+1,fim,pesq);
  }
  else
  {
   return buscaBinRec(vetor,ini,meio-1,pesq);
  }
 }
 return -1;

}
int main (void)
{
 int vetor_tst[4]={2,3,4,7},fun,x;
 printf("Informe o valor a ser encontrado: ");
 scanf("%d",&x);
 fun=buscaBinRec(vetor_tst,0,3,x);
 printf("%d",fun);
 printf("\n\n");
 return 0;
}
