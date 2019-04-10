/*Escreva uma função que receba como parâmetro um ponteiro para o primeiro
elemento de uma lista encadeada simples e retorne a soma dos valores de todos os elementos*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
int somar(Celula *l);
void exibir(Celula *l);

int main(){
	Celula *lista = NULL;

	srand(time(NULL));

	for(int i = 0; i < 20; i++){
		lista = inserir(rand()%100, lista);
	}

	exibir(lista);
    printf("\nSoma dos elementos: %d", somar(lista));

	return 1;
}

//Inserir na lista
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

//Somar elementos
int somar(Celula *l){
    Celula *p;
    int soma = 0;

    for(p = l; p; p = p->prox){
		soma = soma+p->dado;
	}

    return soma;
}

//Exibir lista
void exibir(Celula *l){
	Celula *p;
	int i = 0;

	for(p = l; p; p = p->prox, i++){
		printf("%d -> %d\n", i, p->dado);
	}
}


