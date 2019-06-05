#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//Inserir, Exibir, Contar, Contar Pares, Exibir Repetidos, pesquisar
typedef struct no{
    int dado;
    struct no *prox;
} Celula;

Celula *inserirR(int valor, Celula *l);
void exibirR(Celula *l);

int main(){
    Celula *lista = NULL;
	int i;
	int valor;
	srand(time(NULL));
	printf("Valores gerados aleatoriamente:\n");
	for (i = 0; i < 10; i++) {
		valor = rand() % 100;
		printf("Valor sorteado: %d\n", valor);
		lista = inserirR(valor, lista);
	}

	printf("Valores da lista jah ordenados:\n");
    exibirR(lista);
    return 0;
}

//Inserir
Celula *inserirR(int valor, Celula *l) {
	if (l && valor > l->dado) {
		//percorria - empilhar
		l->prox = inserirR(valor, l->prox);
		return l;
	} else { //sai da lista
		//aloca
		Celula *novo = (Celula *)malloc(sizeof(Celula));
		//deposita
		novo->dado = valor;
		novo->prox = l;

		//retorna
		return novo;
	}
}

//Exibir
void exibirR(Celula *l) { //inicializou a variavel de controle
	if (l) { //teste de parada
		printf("%d\t", l->dado);
		exibirR(l->prox); //PONTO DE RECURSAO: transformacao variavel de controle
	}
}

