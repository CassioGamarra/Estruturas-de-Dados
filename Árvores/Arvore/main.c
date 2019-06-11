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
void exibirArvore(Arvore *r, int l);
void mostrarFolhas(Arvore *r);
Arvore *pesquisar(Arvore *r, int valor);

int contarNos(Arvore* r);

int main(){
    Arvore *raiz = NULL;
    int valor;
    srand(time(NULL));
    for(int i = 0; i < 10; i++){
        raiz = inserir(rand()%100, raiz);
    }

    printf("Exibir RED:\n");
    exibirRED(raiz);
    printf("\nExibir ERD:\n");
    exibirERD(raiz);
    printf("\nExibir EDR:\n");
    exibirEDR(raiz);
    printf("\nExibir Arvore:\n");
    exibirArvore(raiz, 0);
    printf("\nNumero de nos: %d\n", contarNos(raiz));
    printf("\nExibir folhas:\n");
    mostrarFolhas(raiz);
    printf("\n\nDigite um valor para pesquisar: ");
    scanf("%d", &valor);
    pesquisar(raiz, valor);
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

//Exibir com EDR
void exibirArvore(Arvore *r, int nivel){
    int i;
    if(r){
        exibirArvore(r->dir, nivel+1);
        for(i = 0; i < nivel; i++){
            printf("   ");
        }
        printf("%d\n", r->dado);
        exibirArvore(r->esq, nivel+1);
    }
}

//Contar os nós
int contarNos(Arvore *r){
    int cont;
    if(r){
        return 1 + contarNos(r->dir)+contarNos(r->esq);
    }
}

//Mostrar Folhas
void mostrarFolhas(Arvore *r){
    if(r){
        if(!r->dir && !r->esq){
            printf("%d ", r->dado);
        }
        if(r->esq){
            mostrarFolhas(r->esq);
        }
        if(r->dir){
            mostrarFolhas(r->dir);
        }
    }
}

//Pesquisar
Arvore *pesquisar(Arvore *r, int valor){
    if(r){
        if(r->dado == valor){
            return r;
        }
        if(r->esq){
            pesquisar(r->esq, valor);
        }
        if(r->dir){
            pesquisar(r->dir, valor);
        }
    }
    return NULL;
}
