#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct no{
    int dado;
    struct no *esq, *dir;
} Arvore;

Arvore *inserir(int valor, Arvore *r);
void exibirRED(Arvore *r);
void exibirERD(Arvore *r);
void exibirEDR(Arvore *r);
int main(){
    Arvore *raiz = NULL;

    raiz = inserir(15, raiz);
    raiz = inserir(5, raiz);
    raiz = inserir(2, raiz);
    raiz = inserir(10, raiz);
    raiz = inserir(20, raiz);
    printf("Exibir RED:\n");
    exibirRED(raiz);
    printf("\nExibir ERD:\n");
    exibirERD(raiz);
    printf("\nExibir EDR:\n");
    exibirEDR(raiz);
    return 0;
}

//Inserir
Arvore *inserir(int valor, Arvore *r){
    if(r){
        if(valor < r->dado){
            r->esq = inserir(valor, r->esq);
        }
        else{
            r->dir = inserir(valor, r->dir);
        }
        return r;
    }
    else{
        Arvore *novo = (Arvore *)malloc(sizeof(Arvore));
        novo->dado = valor;
        novo->esq = NULL;
        novo->dir = NULL;
        return novo;
    }
}

//Exibir com RED
void exibirRED(Arvore *r){
    if(r){
        printf("%d \t", r->dado);
        exibirRED(r->esq);
        exibirRED(r->dir);
    }
}

//Exibir com ERD
void exibirERD(Arvore *r){
    if(r){
        exibirERD(r->esq);
        printf("%d \t", r->dado);
        exibirERD(r->dir);
    }
}

//Exibir com EDR
void exibirEDR(Arvore *r){
    if(r){
        exibirEDR(r->esq);
        exibirEDR(r->dir);
        printf("%d \t", r->dado);
    }
}
