/*Escreva uma função que receba uma lista encadeada simples e retorne quantos elementos há.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
void exibir(Celula *l);
int contar(Celula *l);

int main(){
	Celula *lista = NULL;
	int contador;

	srand(time(NULL));

	for(int i = 0;i < 20; i++){
		lista = inserir(rand()%100, lista);
	}
	exibir(lista);
	contador = contar(lista);
	printf("\nNumero de elementos na lista: %d", contador);

	return 1;
}

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

void exibir(Celula *l){
	Celula *p;
	int i = 0;

	for(p = l; p; p = p->prox, i++){
		printf("%d -> %d\n", i, p->dado);
	}

}
int contar(Celula *l){
	Celula *p;
	int cont = 0;

	for(p = l; p; p = p->prox, cont++){

	}
	return cont;
}
