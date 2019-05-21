#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    int prioritario;
    struct no *prox;
} Celula;

typedef struct{
    Celula *cabeca; //Remover
    Celula *cauda; //Inserir
} Fila;

void inicializarFila(Fila *f);
void inserirFila(int valor, Fila *f, int prioritario);
void removerFila(Fila *f);
void removerPrioritario(Fila *f);
void retornar();
void menu();

Fila fila;
int contador = 1;

int main(){
    inicializarFila(&fila);
    menu();
    return 0;
}
void inicializarFila(Fila *f){
    f->cabeca = NULL;
    f->cauda = NULL;
}

void inserirFila(int valor, Fila *f, int prioritario){
    Celula *novo;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prioritario = prioritario;
    novo->prox = NULL;

    if(!f->cauda){
        f->cauda = novo;
        f->cabeca = novo;
    }
    else{
        f->cauda->prox = novo;
        f->cauda = novo;
    }
    retornar();
}

void removerFila(Fila *f){
    Celula *lixo;

    if(f->cabeca){
        lixo = f->cabeca;
        f->cabeca = f->cabeca->prox;
        free(lixo);

        if(!f->cabeca){
            f->cauda = NULL;
        }
    }
    else{
        printf("\n\nFILA VAZIA!");
    }
}
void removerPrioritario(Fila *f){
    Celula *p, *pR, *lixo;

    p = f->cabeca;
    for(pR = NULL; p; pR = p, p = p->prox){
        if(p->prioritario == 1){
            if(p->prox == NULL){
                free(p);
                f->cauda = pR;
            }
        }
    }
}


void retornar(){
    printf("\t\nFila atualizada!");
    system("pause");
    system("cls");
    menu();
}

void menu(){
    setlocale(LC_ALL, "Portuguese");
    int escolha = 0, codigo;
    while(escolha == 0){
        printf("\t\tATENDIMENTO\n");
        printf("\n\t1 - GERAR FICHA NORMAL");
        printf("\n\t2 - GERAR FICHA PRIORITÁRIA");
        printf("\n\t3 - ATENDER");
        printf("\n\t4 - SAIR\n\n");
        printf("\tESCOLHA: ");
        scanf("%d", &escolha);
        switch(escolha){
            case 1:{
                printf("\nDigite o código de chamada: ");
                scanf("%d", &codigo);
                inserirFila(codigo, &fila, 0);
                break;
            }
            case 2:{
                printf("\nDigite o código de chamada: ");
                scanf("%d", &codigo);
                inserirFila(codigo, &fila, 1);
                break;
            }
            case 3:{
                printf("Na cabeca: %d\nNa cauda: %d\n", fila.cabeca->dado, fila.cauda->dado);
                removerFila(&fila);
                contador++;
                printf("\nContador = %d\n", contador);
                if(contador == 4){
                    removerPrioritario(&fila);
                    contador = 0;
                }
                if(fila.cauda == NULL){
                    printf("\n\nA fila ficou vazia!!!");
                    break;
                }

                printf("Situacao da fila apos remocoes!\n");
                printf("Na cabeca: %d\nNa cauda: %d\n", fila.cabeca->dado, fila.cauda->dado);
                retornar();
                break;
            }
            case 4:{
                system("exit");
                break;
            }
            default:{
                printf("\nEscolha inválida!\n");
                system("pause");
                system("cls");
                escolha = 0;
            }
        }
    }
}


