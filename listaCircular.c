/*Listas circulares*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;

Celula *inserir(int valor, Celula *l);
int verificaLista(Celula *l);
void exibir(Celula *l);

int main(){
    setlocale(LC_ALL, "portuguese");
	Celula *listaC = NULL;

	srand(time(NULL));

	for(int i = 0; i < 20; i++){
		listaC = (inserir(rand()%100, listaC));
	}

	int verificador = verificaLista(listaC);
	if(verificador == 1){
		printf("A lista é circular!");
	}
	else{
		printf("A lista não existe ou não é circular");
	}

    printf("\nLista:\n");
	exibir(listaC);
	return 0;
}

//Inserir os elementos na lista
Celula *inserir(int valor, Celula *l){
	Celula *p, *pR, *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = novo;

	if(!l) return novo;

	//Percorre toda a lista para inserção dos valores
	for(pR = NULL, p = l; p->prox; pR = p, p = p->prox){
		if((valor < p->dado)||(p->prox == l))break;
	}

	//Insere no "fim"
	if(valor > p->dado){
		p->prox = novo;
		novo->prox = l;
	}

	//Insere no inicio
	else if(!pR){
		novo->prox = l;
		for(;p->prox; p = p->prox){
			if(p->prox == l) break;
		};
		p->prox = novo;
		return novo;
	}
	//Insere no meio
	else if(p->prox != l || valor < p-> dado){
		pR->prox = novo;
		novo->prox = p;
	}

	return l;
}

//Verifica se a lista é circular ou não
int verificaLista(Celula *l){
	Celula *p;
	if (!l) return -1;

	for(p = l; p; p =  p->prox){
		if(p->prox == l) return 1;
	}
	return 0;
}

//Exibir os elementos da lista
void exibir(Celula *l){
	Celula *p;
    int i = 0;
	for(p = l; p->prox; p = p->prox, i++){
		printf("%d elemento: %d\n", i+1, p->dado);
		if(p->prox == l) break;
	}
}

