/* Escreva um procedimento que receba como parâmetros dois ponteiros, cada um apontando para o primeiro elemento de uma lista encadeada.
O procedimento deve trocar a segunda metade de cada lista, ou seja, a segunda metade da primeira lista deve ser colocada na segunda lista,
e a segunda metade da segunda lista deve ser colocada na primeira lista. No caso de lista(s) com número impar de elementos, o elemento central
pode ou não ser trocado. As listas em questão podem ter tamanhos diferentes. Não devem ser alocados novos elementos,
já que as listas resultantes são criadas com os elementos das listas recebidas como parâmetros.
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

typedef struct no{
    int dado;
    struct no *prox;
}Celula;

Celula *inserir(int valor, Celula *l);
Celula *excluirInicio(Celula *l);
Celula *excluirFaixa(int ini, int fim, Celula *l);
Celula *destruir(Celula *l);
Celula *transferir(Celula *lA, Celula *lB);
Celula *dividir(Celula *l);
Celula *unirListas(Celula *lA, Celula *lB);
int contar(Celula *l);
void exibir(Celula *l);


int main(){
    setlocale(LC_ALL, "Portuguese");
    Celula *listaA = NULL, *listaB = NULL;
    int ini, fim;

    srand(time(NULL));

    for(int i = 0; i < 10; i++){
        listaA = inserir(rand()%1000, listaA);
    }
    for(int i = 0; i < 20; i++){
        listaB = inserir(rand()%1000, listaB);
    }
    printf("Lista A:\n");
    exibir(listaA);
    printf("\nLista B:\n");
    exibir(listaB);
    putchar('\n');
    transferir(listaA, listaB);

    return 0;
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

//Exclui o numero do inicio
Celula *excluirInicio(Celula *l){
    Celula *p;
    if(!l) return l;

    p = l;
    l = l->prox;
    free(p);
    return l;
}

//Excluir faixa
Celula *excluirFaixa(int ini, int fim, Celula *l) {
	Celula *p, *pR, *lixo;
	int i;

	if (!l) return l;

	for (i = 0, pR = l, p = l; p && i < fim; i++,p = p->prox) {
		if (i >= ini) {

		}
		else {
			pR = p;
		}
	}

	lixo = pR->prox;
	pR->prox = p->prox;
	p->prox = NULL;

	lixo = destruir(lixo);

    if(ini == 0){
        l = excluirInicio(l);
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

//Divide a celula
Celula *transferir(Celula *lA, Celula *lB){
    Celula *auxA = NULL, *auxB = NULL, *p, *pR;
    int i, contA, contB;

    auxA = dividir(lA);
    auxB = dividir(lB);

    contA = contar(lA);
    contB = contar(lB);

    lA = excluirFaixa(contA/2, contA-1, lA);
    lB = excluirFaixa(contB/2, contB-1, lB);

    lA = unirListas(lA, auxB);
    lB = unirListas(lB, auxA);

    printf("\nNova A:\n");
    exibir(lA);
    printf("\nNova B:\n");
    exibir(lB);
}

//Dividir a celula
Celula *dividir(Celula *l){
    Celula *p, *novaLista = NULL;
    int i, cont;

    cont = contar(l);

    for(p = l, i = 0; p; p = p->prox, i++){
        if(i >= cont/2){
            novaLista = inserir(p->dado, novaLista);
        }
    }

    return novaLista;
}

//Unir as listas
Celula *unirListas(Celula *lA, Celula *lB){
    Celula *p;
    Celula *novaLista = NULL;

    for(p = lA; p; p = p->prox){
        novaLista = inserir(p->dado, novaLista);
    }
    for(p = lB; p; p = p->prox){
        novaLista = inserir(p->dado, novaLista);
    }

    return novaLista;
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
