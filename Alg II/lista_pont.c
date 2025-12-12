#include <stdio.h>
#include <stdlib.h>

typedef void * objeto;
	
typedef struct{
	objeto  j;
	struct no * sucessor;
} no;

typedef struct{
	no * primeiro;
	int tam;
} lista;

objeto objeto_no(no *p){
	return p -> j;
}

no * sucessor_no(no *p){
	return p -> sucessor;
}

lista * constroi_lista(void){
	lista *l= malloc(sizeof(lista));
	if (!l)
		return NULL;
	l -> tam = 0;
	l -> primeiro = NULL;
	return l;
}

no * primeiro_no(lista *l){
	return l -> primeiro;
}

no * insere_lista(objeto j, lista *l){
	no * novo = malloc(sizeof(no));
	if (!novo)
		return NULL;
	novo -> j=j;
	novo -> sucessor = primeiro_no(l);
	l -> primeiro = novo;
	l -> tam++;
	return novo;
}
objeto *  remove_lista(lista *l){
	no *aux = primeiro(l);
	aux = primeiro -> j;
	l->primeiro = aux->primeiro;
	free(aux);
}


main(){
	int i;
	lista *l = constroi_lista();
	char *frase = "hoje";
	for (i=0;i < strlen(frase);i++){
		insere_lista(&frase[i],l);
	}
	for (i=0;i < strlen(frase); i++){
		char *letra = remove_lista(l);
		printf("%c", *letra);
}
}

