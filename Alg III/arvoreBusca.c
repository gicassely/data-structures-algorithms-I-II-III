// Arvore de Busca 
#include <stdio.h>
#include <stdlib.h>

typedef struct nodo * Apontador;
typedef struct nodo {
	long chave;
	Apontador esq, dir;
	int contaNodo;
} No;

static Apontador nodoNULL;

Apontador criaNodo(long chave, Apontador esq, Apontador dir, int n){
    Apontador p;
    p = malloc (sizeof *p);
    p->chave = chave; p->esq = esq; p->dir = dir; p->contaNodo = n;
    return p;
}

Apontador inicializaDic(){
    nodoNULL = criaNodo(0,0,0,0);
    return nodoNULL;
}

Apontador insereArv(Apontador p, long k){
    // inserindo na raiz
    if (p == nodoNULL)
        criaNodo(k, nodoNULL, nodoNULL, 1);
    // se for p inserir na direita
    if (p->chave > k)
        insereArv(p->esq, k); 
    // se for p inserir na esqerda
    if (p->chave < k)
        insereArv(p->dir, k);
    // fazer o int que vai somando 1 pra ver qtde de nodos abaixo do nodo atual
    p->contaNodo++;
    return p;
}

void imprimeArvore(Apontador p){
    if (p == NULL)
        return;
    printf("%ld\n", p-> chave);
    imprimeArvore (p-> esq);
    imprimeArvore (p-> dir);
}

void ordena(long v[], int tamV){

//custo depois vai ser tamanho do vetor (N) x qtas vezes insere
// ou seja, n * log (n)
}


int main(){
// Custo da insercao (qtas comparacoes faco p inserir) = altura da arvore
// Altura da arvore = log (n)
// 
    Apontador raiz = inicializaDic(); 
    raiz = insereArv(raiz, 10); 
    raiz = insereArv(raiz, 80); 
    raiz = insereArv(raiz, 5); 
    raiz = insereArv(raiz, 70); 
    raiz = insereArv(raiz, 90); 

    imprimeArvore(raiz);
}
