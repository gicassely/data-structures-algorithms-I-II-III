#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "rubronegra.h"

int main() {
char buffer_chave[CHAVE_TAM];
char buffer_conteudo[CONTEUDO_TAM];
char *chave, *conteudo;
char eof;
arv *t;
  
	t = rn_cria_arvore();
	eof = getc(stdin);
	while(eof != EOF) {
		ungetc(eof, stdin);
		fgets(buffer_chave, CHAVE_TAM, stdin);
		buffer_chave[strlen(buffer_chave) - 1] = '\0'; /* apaga o \n no final*/
		fgets(buffer_conteudo, CONTEUDO_TAM , stdin);
		buffer_conteudo[strlen(buffer_conteudo) - 1] = '\0';
		chave = strdup(buffer_chave);
		conteudo = strdup(buffer_conteudo);
		rn_insere(t, chave, conteudo);
		eof = getc(stdin);
	}
	printf("buscando o conteudo da chave teste: %s\n",rn_busca(t, "teste"));
	printf("removendo a chave teste e seu conteudo: %s\n",rn_remove(t, "teste"));
 	rn_lista_conteudo(t);
	rn_lista_estrutura(t);
}
