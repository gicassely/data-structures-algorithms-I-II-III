#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#include"rubronegra.h"

//funcão cria arvore e inicializa o ponteiro nil e a raiz
arv* rn_cria_arvore(){
arv *t;
	if (!(t=malloc(sizeof(arv)))){
		puts("Erro");
		exit(0);
	}
	if (!(nil=malloc(sizeof(no)))){
		puts("erro");
		exit(0);
	}
	nil->cor=PRETO;
	nil->pai=nil->dir=nil->esq=nil;
	t->raiz=nil;		
	return(t);
}

//funçao busca elemento na arvore, e retorna ponteiro para ele
no* busca_no(no *x, char *k){
	if (x==nil)
		return NULL;
	if (strcasecmp(x->chave,k)==0)
		return x;
	if (strcasecmp(k,x->chave)<0)
		return busca_no(x->esq,k);
	else
		return busca_no(x->dir,k);
}
	
//funcao para buscar uma chave na arvore e retornar seu conteudo;
char *rn_busca(arv *t, char *k){
	return busca(t->raiz,k);
}

char *busca(no *x, char *k){
	if (x==nil)
		return NULL;
	if (strcmp(x->chave,k)==0)
		return x->conteudo;
	if (strcmp(k,x->chave)<0)
		return busca(x->esq,k);
	else
		return busca(x->dir,k);
}

//funcao busca menor elemento da arvore
no *minimo(no *x){
	puts("minimo");
	if (x->esq==nil)
		return x;
	return minimo(x->esq);
}

//funao para inserir na arvore
char* rn_insere(arv* t, char* chave, char* conteudo){
no *x, *y=nil, *z;
	if(!(z=malloc(sizeof(no)))){
		puts("Erro");
		exit(0);
	}
	z->chave=chave;
	z->conteudo=conteudo;
	x=t->raiz;
	while (x!=nil){
		y=x;
		if (strcasecmp(z->chave,x->chave)<0)
			x=x->esq;
		else
			x=x->dir;
	}
	z->pai=y;
	if (y==nil)
		t->raiz=z;
	else
		if (strcasecmp(z->chave,y->chave)<0)
			y->esq=z;
		else
			y->dir=z;
	z->esq=z->dir=nil;
	z->cor=VERMELHO;
	rn_insere_fixup(t,z);
	return z->conteudo;
}

//função para recolorir a arvore arrumando a arvore apos a inserçao
//de um novo no
void rn_insere_fixup (arv *t, no *z){
no *y;

		while (z!=t->raiz && z->pai->cor==VERMELHO)
			if (z->pai==z->pai->pai->esq){
				y=z->pai->pai->dir;
				if (y->cor==VERMELHO){
					z->pai->cor=PRETO;
					y->cor=PRETO;
					z->pai->pai->cor=VERMELHO;
					z=z->pai->pai;
				}
				else{
					if (z==z->pai->dir){
						z=z->pai;
						rot_esq(t,z);
					}
					z->pai->cor=PRETO;
					z->pai->pai->cor=VERMELHO;
					rot_dir(t,(z->pai->pai));		
				}
			}
			else{
				y=z->pai->pai->esq;
                                if (y->cor==VERMELHO){
                                        z->pai->cor=PRETO;
                                        y->cor=PRETO;
                                        z->pai->pai->cor=VERMELHO;
                                        z=z->pai->pai;
                                }
                                else{
                                        if (z==z->pai->esq){
                                                z=z->pai;
                                                rot_dir(t,z);
                                        }
                                        z->pai->cor=PRETO;
                                        z->pai->pai->cor=VERMELHO;
                                        rot_esq(t,(z->pai->pai));

                                }
                        }
	t->raiz->cor=PRETO;
}


//rotação para a esquerda
void rot_esq(arv *t, no *x){
no *y;
	y=x->dir;
	x->dir=y->esq;
	if (y->esq!=nil)
		y->esq->pai=x;
	y->pai=x->pai;
	if (x->pai==nil)
		t->raiz=y;
	else 
		if (x==x->pai->esq)
			x->pai->esq=y;
		else
			x->pai->dir=y; 
	y->esq=x;
	x->pai=y;
}

//rotação para a direita
void rot_dir(arv *t, no *x){
no *y;
	y=x->esq;
	x->esq=y->dir;
	if (y->dir!=nil)
		y->dir->pai=x;
	y->pai=x->pai;
	if (x->pai==nil)
		t->raiz=y;
	else 
		if (x==x->pai->dir)
			x->pai->dir=y;
		else
			x->pai->esq=y; 
	y->dir=x;
	x->pai=y;
}

//função transplanta subarvores do no que sera removido
void rn_transplante(arv *t, no *u, no *v){	
	if (u->pai==nil)
		t->raiz=v;
	else
		if (u==u->pai->esq)
			u->pai->esq=v;
		else
			u->pai->dir=v;
		v->pai=u->pai;
}

//imprime as chaves e conteudos dos nos da
//arvore em ordem crescente
void rn_lista_conteudo(arv* t){
	lista_cont(t->raiz);
}

void lista_cont(no *x){
	if(x!=nil){
           lista_cont(x->esq);
           puts(x->chave);
           puts(x->conteudo);
           if (x->cor==PRETO)puts("Cor: PRETO");
	   else puts("Cor: VERMELHO");
           puts("");
           lista_cont(x->dir);
     }
}

//lista os nos da arvore em pos ordem
void rn_lista_estrutura(arv *t){
	lista_estr(t->raiz);
}

void lista_estr(no *x){
	if(x!=nil){
		printf("Chave: %s\n",x->chave);
		if (x->cor==PRETO)puts("Cor: PRETO");
		else puts("Cor: VERMELHO");
		if (x->pai!=nil)printf("Pai: %s\n",x->pai->chave);
		else puts("Pai: NULL");
		if (x->esq!=nil)printf("Esq: %s\n",x->esq->chave);
		else puts("Esq: NULL");
		if (x->dir!=nil)printf("Dir: %s\n",x->dir->chave);
                else puts("Dir: NULL");
		puts("");
		lista_estr(x->esq);
                lista_estr(x->dir);
     }
}

//função remove no da arvore retorna seu conteudo
char* rn_remove(arv* t, char* chave){
no *x, *y, *z;
char retorna[CONTEUDO_TAM];
int cor_y;
	z=busca_no(t->raiz, chave);
	strcpy(retorna,z->conteudo);
	y=z;
	cor_y=y->cor;
	if (z->esq==nil){
		x=z->dir;
		rn_transplante(t,z,z->dir);
	}
	else
		if(z->dir==nil){
			x=z->esq;
			rn_transplante(t,z,z->esq);
		}
		else{
			y=minimo(z->dir);
			cor_y=y->cor;
			x=y->dir;
			x->cor=y->cor;
			if (y->pai==z)
				x->pai=y;
			else{
				rn_transplante(t,y,y->dir);
				y->dir=z->dir;
				y->dir->pai=y;
			}
			rn_transplante(t,z,y);
			y->esq=z->esq;
			y->esq->pai=y;
			y->cor=z->cor;
		}
	if (cor_y==PRETO)
		rn_remove_fixup(t,x);
	free(z);
	return(retorna);	
}

//recolori a arvore e rotaciona dependendo do caso
void rn_remove_fixup(arv *t, no *x){
no *y;
	while (x!=t->raiz && x->cor==PRETO){
		if (x==x->pai->esq){
			y=x->pai->dir;
			if (y->cor==VERMELHO){
				y->cor=PRETO;
				x->pai->cor=VERMELHO;
				rot_esq(t,x->pai);
				y=x->pai->dir;
			}
			if (y->esq->cor==PRETO && y->dir->cor==PRETO){
				y->cor=VERMELHO;
				x=x->pai;
			}
			else{
				if (y->dir->cor==PRETO){
					y->esq->cor=PRETO;
					y->cor=VERMELHO;
					rot_dir(t,y);
					y=x->pai->dir;
				}
				y->cor=x->pai->cor;
				x->pai->cor=PRETO;
				y->dir->cor=PRETO;
				rot_esq(t,x->pai);
				x=t->raiz;
			}
		}
		else{
			y=x->pai->esq;
                        if (y->cor==VERMELHO){
                                y->cor=PRETO;
                                x->pai->cor=VERMELHO;
                                rot_dir(t,x->pai);
                                y=x->pai->esq;
                        }
                        if (y->dir->cor==PRETO && y->esq->cor==PRETO){
                                y->cor=VERMELHO;
                                x=x->pai;
                        }
                        else{
                                if (y->esq->cor==PRETO){
                                        y->dir->cor=PRETO;
                                        y->cor=VERMELHO;
                                        rot_esq(t,y);
                                        y=x->pai->esq;
                                }
                                y->cor=x->pai->cor;
                                x->pai->cor=PRETO;
                                y->esq->cor=PRETO;
                                rot_dir(t,x->pai);
                                x=t->raiz;
			}
		}
	}
	x->cor=PRETO;
}

/*função remove sem transplante
char* rn_remove(arv* t, char* chave){
no *x, *y, *z;
	z=busca_no(t->raiz, chave);
	if (!z->esq || !z->dir)
		y=z;
	else
		y=minino(z->dir);
	if (y && y->esq)
		x=y->esq;
	else
		x=y->dir;
	x->pai=y->pai;
	if (!y->pai)
		t->raiz=x;
	else
		if (y==y->pai->esq)
			y->pai->esq=x;
		else
			y->pai->dir=x;
	if (y!=z)
		z->chave=y->chave;
	if (y && y->cor==PRETO)
		rn_remove_fixup(t,x);
	return y->conteudo;
}
*/
//void rn_remove_fixup(t,x);
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
