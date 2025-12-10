#include <stdio.h>
#include <stdlib.h>

struct elementos {
	int *ele;
	struct elementos *prox;
};
	
struct  obj {
	int tam;
	struct elementos *conteudo;
	struct obj *prox;
};

typedef struct obj celula;
typedef struct elementos colecao; 
//------------------------------------------------------------------------
celula * Func_BuscaTam(int tam, celula *p){//busca o primeiro que encontrar pelo tamanho
	while((p->tam < tam) && (p->prox != NULL)){
		p = p->prox; 
	}	
		return p;

}
//------------------------------------------------------------------------
celula * Func_BuscaTamAnt(int tam, celula *p){//busca o primeiro que encontrar pelo tamanho
	while((p->prox->tam < tam))
		p = p->prox; 
		return p;

}
//------------------------------------------------------------------------

int Func_ComparaColecao(int *p, int *q, int tam){
		int i = 0;
		while((p[i] == q[i]) && ((i + 1) != tam )){
			i++;
		}	
		if(p[i] > q[i])
			return 1;
		else if (p[i] < q[i])
				return -1;
			 else 
					return 0;
		
}	

//------------------------------------------------------------------------
void Func_InsereCelula(int tam, celula *l){//Insere os valores na lista sem estar em ordem
	celula *temp;
	temp = (celula *) malloc (sizeof(celula));
	temp->conteudo = (colecao *) malloc (sizeof(colecao));
	temp->tam = tam;
	temp->prox = l->prox;
	l->prox = temp;

return;
}



//------------------------------------------------------------------------
void Func_InsereColecao(int *c, colecao *l){
	colecao *temp;
	temp = (colecao *) malloc (sizeof(colecao));
	temp->ele = c;
	temp->prox = l->prox;
	l->prox = temp;
}	




//------------------------------------------------------------------------		
	
void Func_ImprimeLista(celula *l, FILE *arq){
	int i;
	celula *lista;
	colecao *colection;
	int *conteudo;
	lista = l->prox; //pula a cabeça
	while (lista != NULL){
		colection = lista->conteudo->prox;//pula a cabeça
		while (colection != NULL){
			conteudo = colection->ele;
			fprintf(arq,"%d ",lista->tam);
			for (i = 0; i < lista->tam; i++)
				fprintf(arq,"%d ",conteudo[i]);
			fprintf(arq,"\n");	
			colection = colection->prox;
	    }
	    lista = lista->prox;	
	}
}			
//------------------------------------------------------------------------
void Func_Insere(int *conteudo, celula *lista, int tam, FILE *arq){
	celula *teste_celula;
	colecao *teste_colecao, *teste_colecao_anterior;
	int dif;
	teste_celula = Func_BuscaTam(tam, lista);
			if (teste_celula->tam > tam){
				teste_celula = Func_BuscaTamAnt(tam, lista);
				Func_InsereCelula(tam, teste_celula);
				Func_InsereColecao(conteudo, teste_celula->prox->conteudo);
			} else 
				if (teste_celula->tam < tam) {
					Func_InsereCelula(tam, teste_celula);
					Func_InsereColecao(conteudo, teste_celula->prox->conteudo);
				} else {
					teste_colecao_anterior = teste_celula->conteudo;
					teste_colecao = teste_celula->conteudo->prox;
					while (((dif = Func_ComparaColecao(conteudo, teste_colecao->ele, tam)) == 1) && (teste_colecao->prox != NULL)){
						teste_colecao_anterior = teste_colecao;
						teste_colecao = teste_colecao->prox;
					}	
					if (dif == 1)
						Func_InsereColecao(conteudo,teste_colecao);
						else
							if (dif == -1)
								Func_InsereColecao(conteudo,teste_colecao_anterior);
							else
								fprintf(arq,"E\n");
							
				}
}					
//------------------------------------------------------------------------
void Func_RemoveColecao(colecao *c){
	colecao *temp;
	temp = c->prox;
	c->prox = temp->prox;
	free(temp);
	temp = NULL;
}	
//------------------------------------------------------------------------
void Func_RemoveCelula(celula *c){
	celula *temp;
	temp = c->prox;
	c->prox = temp->prox;
	free(temp);
	temp = NULL;
}	

//------------------------------------------------------------------------
void Func_Remove(int *conteudo, celula *lista, int tam, FILE *arq){
	int dif = 0;
	celula *teste_celula;
	colecao *teste_colecao, *teste_colecao_anterior;
	teste_celula = Func_BuscaTam(tam, lista);
	if (teste_celula->tam != tam)
		fprintf(arq,"E\n"); //debug
	else {
		teste_colecao = teste_celula->conteudo->prox; //pula cabeça
		teste_colecao_anterior = teste_celula->conteudo; //recebe a cabeça
		while (((dif = Func_ComparaColecao(conteudo,teste_colecao->ele, tam)) == 1) && (teste_colecao->prox != NULL)){
			teste_colecao_anterior = teste_colecao;
			teste_colecao = teste_colecao->prox;
		}	
		if (dif != 0)
			fprintf(arq,"E\n"); //debug
		else {
			Func_RemoveColecao(teste_colecao_anterior);	
			if (teste_celula->conteudo->prox == NULL){
				teste_celula = Func_BuscaTamAnt(tam, lista);
				Func_RemoveCelula(teste_celula);
			}
		}
	}	
	
	
}
//------------------------------------------------------------------------	
int Func_ComparaSuperConjunto(int *c, int *l, int tamc, int taml){
		int  i = 0, j = 0;
		while (j < tamc ) {	
			while((c[j] > l[i]) && (tamc - j <= taml - i)){
				i++;
			}	
			if (tamc - j > taml - i)
				return 0;
			else 
				if (c[j] < l[i])
					return 0;
			j++;
			i++;	
		}	
		return 1;
		
}
//------------------------------------------------------------------------	
void Func_Procura(int *conteudo, celula *lista, int tam, FILE *arq){
	int dif = 0;
	celula *teste_celula;
	colecao *teste_colecao;
	teste_celula = Func_BuscaTam(tam, lista);
	if (teste_celula->tam != tam){
		fprintf(arq,"E\n"); //debug
		fprintf(arq,"0\n");
	}
	else {
		teste_colecao = teste_celula->conteudo->prox; //pula cabeça
		while (((dif = Func_ComparaColecao(conteudo,teste_colecao->ele, tam)) == 1) && (teste_colecao->prox != NULL)){
			teste_colecao = teste_colecao->prox;
		}	
		if (dif != 0){
			fprintf(arq,"E\n"); 
			fprintf(arq,"0\n");
		}
		else
			fprintf(arq,"0\n");
	}	
	
}	
//------------------------------------------------------------------------
void Func_RetiraSuperConj (int *conteudo, celula *lista, int tam){
	int compara = 0;
	celula *teste_celula, *teste_celula_remove;
	colecao *teste_colecao, *teste_colecao_anterior;
	teste_celula = Func_BuscaTam(tam, lista);
	if (teste_celula->tam < tam)
		printf("Deletou");
	else{
		if (teste_celula->tam == tam)	
			teste_celula = teste_celula->prox;
		while(teste_celula != NULL){	
			teste_colecao = teste_celula->conteudo->prox; //pular a cabeça
			teste_colecao_anterior = teste_celula->conteudo;
			while(teste_colecao != NULL){
				compara = Func_ComparaSuperConjunto(conteudo, teste_colecao->ele, tam, teste_celula->tam);
				if (compara == 1){
					Func_RemoveColecao(teste_colecao_anterior);	
					if (teste_celula->conteudo->prox == NULL){
						teste_celula_remove = Func_BuscaTamAnt(teste_celula->tam, lista);
						Func_RemoveCelula(teste_celula_remove);	
					}
				}
				teste_colecao_anterior = teste_colecao;
				teste_colecao = teste_colecao->prox;
			}
			teste_celula = teste_celula->prox;	
		}
	}	
}	

//------------------------------------------------------------------------
void Func_ImprimeSubConjuntos(int *conteudo, celula *lista, int tam, FILE *arq){
	int compara = 0, i;
	celula *teste_celula;
	colecao *teste_colecao;
	teste_celula = lista;
	if(teste_celula->prox != NULL) 
		if(teste_celula->prox->tam < tam)
			do{
				teste_celula = teste_celula->prox;
				if(teste_celula->tam < tam){
					teste_colecao = teste_celula->conteudo->prox; //pula cabeça
					while(teste_colecao != NULL){
						compara = Func_ComparaSuperConjunto(teste_colecao->ele, conteudo, teste_celula->tam, tam);
						if (compara == 1){
							fprintf(arq,"%d ",teste_celula->tam);
							for (i = 0; i < teste_celula->tam; i++)
								fprintf(arq,"%d ",teste_colecao->ele[i]);
							fprintf(arq,"\n");
						}	
						teste_colecao = teste_colecao->prox;
					}
				}
			}while((teste_celula->prox != NULL) && (teste_celula->tam < tam));
}	
//------------------------------------------------------------------------
void Func_ImprimeSuperConjuntos(int *conteudo, celula *lista, int tam, FILE *arq){
	int compara = 0, i;
	celula *teste_celula;
	colecao *teste_colecao;
	teste_celula = Func_BuscaTam(tam, lista);
	if (teste_celula->tam >= tam){
		if (teste_celula->tam == tam)	
			teste_celula = teste_celula->prox;
		while(teste_celula != NULL){	
			teste_colecao = teste_celula->conteudo->prox; //pular a cabeça
			while(teste_colecao != NULL){
				compara = Func_ComparaSuperConjunto(conteudo, teste_colecao->ele, tam, teste_celula->tam);
				if (compara == 1){
					fprintf(arq,"%d ",teste_celula->tam);
					for (i = 0; i < teste_celula->tam; i++)
						fprintf(arq,"%d ",teste_colecao->ele[i]);
					fprintf(arq,"\n");
				}
				teste_colecao = teste_colecao->prox;
			}
			teste_celula = teste_celula->prox;
		}
	}	
	
}

//------------------------------------------------------------------------



int main(int argc,char *argv[]){

	if (argc != 3){ //Verifica se os parametros estão corretos
		printf("Entrada incorreta. Por favor utilizar o formato: ./programa caminho_do_arquivo_entrada caminho_do_arquivo_saida\n");
		return 0;
	}
	
	FILE *arq_entrada, *arq_saida;
		
	if ((arq_entrada = fopen(argv[1],"r")) == NULL) {//Abre e verifica se ele conseguiu abrir corretamente o arquivo de entrada	
	   printf("Erro na abertura de %s\n", argv[1]);
	   return 0;
	}
	
	if ((arq_saida = fopen(argv[2],"w+")) == NULL) {//Abre e verifica se ele conseguiu abrir corretamente o arquivo de saida	
	   printf("Erro na abertura de %s\n", argv[2]);
	   return 0;
	}
	
	celula *lista;
	
	lista = (celula *) malloc (sizeof(celula)); //Aloca o primeiro elemento da celula (cabeça)
	
	int nummax;//Primeiro numero de todo arquivo
	
	fscanf(arq_entrada, "%d", &nummax);//Lendo esse primeiro numero

	int tam;
	char op;
	int *conteudo = NULL;
	
	while (((fscanf(arq_entrada," %c", &op)) != EOF) && (op != '0')){ //laço de leitura do arquivo
		if (op != '*'){
			fscanf(arq_entrada,"%d", &tam);				
			conteudo = (int *) malloc(sizeof(int)*tam);
			int i;
			for( i = 0; i < tam; i++){
				fscanf(arq_entrada,"%d",&conteudo[i]);
			}
		}
	switch (op){
			case '+':
				Func_Insere(conteudo, lista, tam, arq_saida);
				fprintf(arq_saida,"0\n");
				break;
			case '*':
				Func_ImprimeLista(lista, arq_saida);
				fprintf(arq_saida,"0\n");
				break; 
			case '-':
				Func_Remove(conteudo, lista, tam, arq_saida);
				fprintf(arq_saida,"0\n");
				break;	
			case '=':
				Func_Procura(conteudo, lista, tam, arq_saida);
				break;
			case '/':
				Func_RetiraSuperConj(conteudo, lista, tam);
				fprintf(arq_saida,"0\n");
				break;
			case '<':
				Func_ImprimeSubConjuntos(conteudo, lista, tam, arq_saida);
				fprintf(arq_saida,"0\n");
				break;
			case '>':
				Func_ImprimeSuperConjuntos(conteudo, lista, tam, arq_saida);				
				fprintf(arq_saida,"0\n");
				break;		
			default:
				break;
		}							
			

    }					
					
					
	conteudo = NULL;	
return 0;
}			


















