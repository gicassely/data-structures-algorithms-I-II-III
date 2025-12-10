#define PRETO 0
#define VERMELHO 1
#define CHAVE_TAM 257
#define CONTEUDO_TAM 4097


typedef struct no *apontador;

typedef struct no{
	char *conteudo;
	char *chave;
	int cor;
	apontador dir, esq, pai;
}no;

typedef struct arv{
	no *raiz;
}arv;	

no *nil;

char* rn_insere(arv* t, char* key, char* thing);
void rn_insere_fixup(arv *t, no *z);
char *busca(no *x, char *k);
char *rn_busca(arv *t, char *k);
no *minimo(no *x);
arv* rn_cria_arvore();
void rn_lista_conteudo(arv* t);
void lista_cont(no *x);
void rn_lista_estrutura(arv *t);
void lista_estr(no *x);
void rn_transplante(arv *t,no *v,no *u);
char* rn_remove(arv* t, char *chave);
void rn_remove_fixup(arv *t, no *x);
void rot_esq(arv *t, no *x);
void rot_dir(arv *t ,no *x);
