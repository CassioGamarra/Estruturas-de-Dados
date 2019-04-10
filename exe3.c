/*Escreva uma função que receba uma lista encadeada simples e
devolva o endereço de um nó que esteja o mais próximo possível do meio da lista.*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
Celula *meioLista(Celula *l);
void exibir(Celula *l);
int contar(Celula *l);


int main(){
	Celula *lista = NULL;
	Celula *p;
	int contador;

	srand(time(NULL));

	for(int i = 0;i < 20; i++){
		lista = inserir(rand()%100, lista);
	}
	exibir(lista);
    p = meioLista(lista);
    printf("\n\nElemento no meio da lista %d\nPossui o endereco: %p", p->dado, p);

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

Celula *meioLista(Celula *l){
	Celula *p;

	int contador;
	int aux = contar(l); //Conta a lista

	for(p = l, contador = 1; contador < (aux/2); p = p->prox, contador++);

	return p;
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



