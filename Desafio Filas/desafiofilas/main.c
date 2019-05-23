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
    Celula *novo;

    novo = (Celula *)malloc(sizeof(Celula));
	novo->dado = valor;
	novo->prox = NULL;

	//eh a primeira vez?
	if (!f->fim) {
		f->fim = novo;
		f->inicio = novo;
	} else {
		f->fim->prox = novo;
		f->fim = novo;
	}
    retornar();
}

//Remover da fila
void removerFila(Fila *f){
    Celula *lixo;

    //fila existe?
	if (f->inicio) {
		lixo = f->inicio;
		f->inicio = f->inicio->prox;
		free(lixo);

		//caso apague o ultimo elemento
		if (!f->inicio) {
			f->fim = NULL;
		}
	} else {
		printf("Fila vazia\n");
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
                menu();
                break;
            }
            case 3:{
                if(fila.fim!= NULL){
                    printf("\nFILA NORMAL: PRIMEIRO: %d | ULTIMO: %d", fila.inicio->dado, fila.fim->dado);
                    removerFila(&fila);
                    printf("\t\nFila atualizada!");
                    if(fila.fim!=NULL){
                        printf("\nFILA NORMAL: PRIMEIRO: %d | ULTIMO: %d", fila.inicio->dado, fila.fim->dado);
                    }
                    else{
                        printf("\nFILA NORMAL VAZIA!\n");
                        system("pause");
                        system("cls");
                    }
                    contador++;
                }
                else{
                    printf("\nFILA NORMAL VAZIA!\n");
                    contador = 4;
                }
                if(filaPrioritaria.fim != NULL){
                    printf("\nFILA PRIORITARIA: PRIMEIRO: %d | ULTIMO: %d\n\n", filaPrioritaria.inicio->dado, filaPrioritaria.fim->dado);
                    system("pause");
                    system("cls");
                }
                else{
                    printf("\nFILA PRIORITARIA VAZIA!\n");
                    system("pause");
                    system("cls");
                }

                if(contador == 4){
                    if(filaPrioritaria.fim!=NULL){
                        removerFila(&filaPrioritaria);
                        printf("\t\nFila atualizada!");
                        if(filaPrioritaria.fim!=NULL){
                            printf("\nFILA PRIORITARIA: PRIMEIRO: %d | ULTIMO: %d", fila.inicio->dado, fila.fim->dado);
                        }
                        else{
                            printf("\nFILA PRIORITARIA VAZIA!\n");
                            system("pause");
                            system("cls");
                        }
                    }
                }
                putchar('\n');
                break;
            }
            case 4:{
                break;
            }
            default :{
                printf("\nEscolha inválida!\n");
                system("pause");
                system("cls");
            }
        }
    }while(escolha != 4);
    printf("\n\tOBRIGADO POR USAR O SISTEMA!");
    system("exit");
}
