/*Construa uma função que receba como parâmetro um ponteiro que
aponta para o primeiro elemento de uma lista encadeada simples e elimine
o primeiro e o último elementos da lista. Se a lista for composta por
apenas um elemento, este deve ser apagado*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
	int dado;
	struct no *prox;
} Celula;


Celula *inserir(int valor, Celula *l);
Celula *excluir(Celula *l);
Celula *destruir(Celula *l) ;
int contar(Celula *l);
void exibir(Celula *l);

int main(){
	Celula *lista = NULL;
    int tam;
	srand(time(NULL));

    do{
        system("cls");
        printf("\nQual o tamanho da lista?");
        scanf("%d", &tam);
    }while(tam <= 0);

	for(int i = 0; i < tam; i++){
		lista=(inserir(rand()%100, lista));
	}

	printf("\nLista original:\n");
	exibir(lista);
    lista = excluir(lista);

    if(contar(lista) == 0){
        printf("\n\nA lista ficou vazia!");
    }
    else{
        printf("\n\nNova lista:\n");
        exibir(lista);
    }

	return 1;
}

//Inserir os elementos na lista
Celula *inserir(int valor, Celula *l){
	Celula *p, *pR, *novo;

	novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	if(!l) return novo;

	for(pR = NULL, p = l; p; pR = p, p = p->prox){
		if(valor < p->dado) break;
	}

	//Inserir no inicio
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

//Excluir os elementos da lista
Celula *excluir(Celula *l){
	Celula *p, *pR;
	if(!l) return l;

    if(contar(l) < 3){
        l = destruir(l);
    }

    else{
        p = l;
        l = l->prox;
        free(p);

        for(pR = NULL, p = l; p; pR = p, p = p->prox){
            if(!p->prox){
                free(p);
                pR->prox = NULL;
                break;
            }
        }
    }

    return l;
}

//Destruir a lista
Celula *destruir(Celula *l){
	Celula *p, *pR;
	if (!l) return l;

	for (pR = l, p = l->prox; p; pR = p, p = p->prox) {
		free(pR);
	}
	free(pR);
	return NULL;
}

//Conta os números da lista
int contar(Celula *l){
	Celula *p;
	int cont = 0;

	for(p = l; p; p = p->prox, cont++){

	}
	return cont;
}

//Exibir os elementos da lista
void exibir(Celula *l){
	Celula *p;
    int i = 0;
	for(p = l; p; p = p->prox, i++){
		printf("%d elemento: %d\n", i+1, p->dado);
	}
}
