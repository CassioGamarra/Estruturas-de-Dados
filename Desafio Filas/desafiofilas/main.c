#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct no{
    int dado;
    struct no *prox;
} Celula;

//Struct da fila
typedef struct {
    Celula *inicio; //Para remover
    Celula *fim; //Para inserir
} Fila;


void inicializar(Fila *f);
void inserirFila(int valor, Fila *f);
void removerFila(Fila *f);
void retornar();
void menu();

//Declaração das filas como globais, para utilização no menu
Fila fila, filaPrioritaria;
int contador = 1; //Contador para prioridade de atendimento

int main(){
    inicializar(&fila);
    inicializar(&filaPrioritaria);
    menu();
    return 0;
}

//Inicializa a fila
void inicializar(Fila *f){
    f->inicio = NULL;
    f->fim = NULL;
}

//Inserir na fila
void inserirFila(int valor, Fila *f){
    Celula *novo = (Celula *)malloc(sizeof(Celula));
    novo->dado = valor;
    novo->prox = NULL;

    if(!f->fim){
        f->inicio = novo;
        f->fim = novo;
    }
    else{
        f->fim->prox = novo;
        f->fim = novo;
    }
    retornar();
}

//Remover da fila
void removerFila(Fila *f){
    Celula *lixo;

    if(f->inicio){
        lixo = f->inicio;
        f->inicio = f->inicio->prox;
        free(lixo);

        if(!f->inicio){
            f->fim = NULL;
        }
        retornar();
    }
    else{
        printf("\nA FILA ESTA VAZIA!");
    }
}

//Função de retorno
void retornar(){
    printf("\t\nFila atualizada!");
    system("pause");
    system("cls");
    menu();
}

//Menu principal
void menu(){
    setlocale(LC_ALL, "Portuguese");
    int escolha, codigo;

    do{
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
                if(fila.fim != NULL){
                    printf("\nFILA NORMAL: INICIO: %d | FIM: %d", fila.inicio->dado, fila.fim->dado);
                }
                removerFila(&fila);
                contador++;
                if(filaPrioritaria.fim != NULL){
                    printf("\nFILA PRIORITARIA: INICIO: %d | FIM: %d", filaPrioritaria.inicio->dado, filaPrioritaria.fim->dado);
                }
                if(contador == 4){
                    removerFila(&filaPrioritaria);
                    contador = 0;
                }
                if(fila.fim == NULL){
                    printf("\n\tFILA NORMAL VAZIA\n");
                    system("pause");
                    system("cls");
                }
                if(filaPrioritaria.fim == NULL){
                    printf("\n\tFILA PRIORITARIA VAZIA\n");
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 4:{
                escolha = 0;
                break;
            }
            default:{
                printf("\nEscolha inválida!\n");
                system("pause");
                system("cls");
            }
        }
    }while(escolha != 0);
    printf("\n\tOBRIGADO POR USAR O SISTEMA!");
}
