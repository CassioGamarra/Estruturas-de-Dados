/*Escreva um programa que leia um arquivo texto (com números inteiros um abaixo do outro)
e salve os números em uma lista encadeada simples.
Ao final, o programa deverá exibir os números armazenados na lista e mostrar o maior deles.*/

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
Celula *popular(Celula *l);
int maiorNumero(Celula *l);
void exibir(Celula *l);

int main(){
	Celula *lista = NULL;
	Celula *p;

	lista = popular(lista);
	if(!lista){
		printf("Erro na abertura do arquivo ou na alocação de memória!");
		exit(0);
	}

	printf("Valores no arquivo:\n");
	exibir(lista);

    printf("\nMaior numero: %d", maiorNumero(lista));

	return 1;
}

//Inserir de forma ordenada na lista
Celula *inserir(int valor, Celula *l){
	Celula *p, *pR, *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	if(!l) return novo;

	for(pR = NULL, p = l; p; pR = p, p = p->prox){
		if(valor < p->dado) break;
	}

	//Inserir no início
	if(p == l){
		novo->prox = l;
		return novo;
	}
	//Inserir no fim
	pR->prox = novo;
	//Inserir no meio
	if(p){
		novo->prox = p;
	}
	return l;
}

Celula *popular(Celula *l){
	FILE *entrada;
	char nomeArquivo[100];
	int dado;

    printf("Informe o nome do arquivo: ");
    scanf("%s", nomeArquivo);

	entrada = fopen(nomeArquivo,"r");

	if(!entrada) return l;

	//Pega os valores do arquivo e insere de forma ordenada
	do{
		fscanf(entrada, "%d", &dado);
		l = inserir(dado, l);
	}while(!feof(entrada));

	fclose(entrada);

	return l;
}

//Encontra o maior numero
int maiorNumero(Celula *l){
    Celula *p;
    int valor;

    for(p = l; p; p = p->prox){
        if(!p->prox){
            valor = p->dado;
        }
    }
    return valor;
}

//Exibir celula
void exibir(Celula *l){
	Celula *p;
	int i = 0;

	for(p = l; p; p = p->prox, i++){
		printf("%d\n", p->dado);
	}
}
