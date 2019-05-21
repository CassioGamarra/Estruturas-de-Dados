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
void inserirFila(int valor, Fila *f);
void removerFila(Fila *f);
void retornar();
void menu();

Fila fila, filaPrioritaria;
int contador = 1;

int main(){
    inicializarFila(&fila);
    inicializarFila(&filaPrioritaria);
    menu();
    return 0;
}
void inicializarFila(Fila *f){
    f->cabeca = NULL;
    f->cauda = NULL;
}

void inserirFila(int valor, Fila *f){
    Celula *novo;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
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
                inserirFila(codigo, &fila);
                break;
            }
            case 2:{
                printf("\nDigite o código de chamada: ");
                scanf("%d", &codigo);
                inserirFila(codigo, &filaPrioritaria);
                break;
            }
            case 3:{
                printf("FILA NORMAL: %d\n", fila.cabeca->dado);
                if(filaPrioritaria.cauda == NULL){
                    printf("FILA NORMAL: %d\n", fila.cauda->dado);
                }
                else{
                    printf("FILA PREFERENCIAL: %d\n", filaPrioritaria.cabeca->dado);
                }

                removerFila(&fila);
                contador++;
                printf("\nContador = %d\n", contador);
                if(contador == 4){
                    if(filaPrioritaria.cauda == NULL){
                        removerFila(&fila);
                    }
                    else{
                        printf("\nValor removido: %d",filaPrioritaria.cauda->dado);
                        removerFila(&filaPrioritaria);
                    }
                    contador = 0;
                }
                if(fila.cauda == NULL){
                    printf("\n\nA fila ficou vazia!!!");
                    break;
                }

                printf("\n\nSituacao da fila apos remocoes!\n");
                printf("FILA NORMAL: %d\n", fila.cabeca->dado);
                if(filaPrioritaria.cauda == NULL){
                    printf("FILA NORMAL: %d\n", fila.cauda->dado);
                }else{
                    printf("FILA PREFERENCIAL: %d\n", filaPrioritaria.cabeca->dado);
                }

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


