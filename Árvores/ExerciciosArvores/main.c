#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define  TAM 10;

typedef struct no{
    int dado;
    struct no *esq, *dir;
} Arvore;

//Declaração das funções
Arvore *inserir(int valor, Arvore *r);

void exibirERD(Arvore *r);

int nosMultiplos(Arvore *r, int valor);
int procurarNivel(Arvore *r, int valor);

int main(){
    setlocale(LC_ALL, "Portuguese");
    Arvore *raiz = NULL;
    int i, valor;
    srand(time(NULL));

    for(i = 0; i < 10; i++){
        raiz = inserir(rand()%100, raiz);
    }
    printf("Valores na árvore:\n");
    exibirERD(raiz);
    printf("\nDigite um valor para pesquisa: ");
    scanf("%d", &valor);
    printf("Valores multiplos de %d: %d", valor,nosMultiplos(raiz, valor));
    printf("\nDigite um valor para pesquisa: ");
    scanf("%d", &valor);
    printf("\nNível do valor %d: %d", valor, procurarNivel(raiz, valor));
    return 0;
}

//Funções

//Inserir
Arvore *inserir(int valor, Arvore *r){
    if(r){
        if(valor < r->dado){
            r->esq = inserir(valor, r->esq);
        }
        else{
            r->dir  = inserir(valor, r->dir);
        }
        return r;
    }
    else{
        Arvore *novo;
        novo = (Arvore *)malloc(sizeof(Arvore));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

//Exibir
void exibirERD(Arvore *r){
    if(r){
        exibirERD(r->esq);
        printf("%d\t", r->dado);
        exibirERD(r->dir);
    }
}

//Exercicios\\

//Exercicio 1
int nosMultiplos(Arvore *r, int valor){
    int cont = 0;
    if(r){
        if(r->dado%valor == 0){
            cont++;
        }
        return cont + nosMultiplos(r->esq, valor) + nosMultiplos(r->dir, valor);
    }
    return 0;
}
//Exercicio 2
int procurarNivel(Arvore *r, int valor){
    int nivel = 0;
    if(r){
        if(r->dado == valor){
            return 0;
        }
        if(valor < r->dado){
            nivel = procurarNivel(r->esq, valor);
            if(nivel == -1) return -1;
            return nivel + 1;
        }
        else{
            nivel = procurarNivel(r->dir, valor);
            if(nivel == -1) return -1;
            return nivel + 1;
        }
    }
    return -1;
}
