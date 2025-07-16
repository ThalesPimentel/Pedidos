#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int num;
    struct No* Prox;
}No;

void InserirnoFim(No** Lista, int valor){
    No *NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar o No");
        return;
    }
    NovoNo->num = valor;
    NovoNo->Prox = NULL;

    if(*Lista == NULL){
        *Lista = NovoNo;
    }
    else{
        No* Atual = *Lista;
        while(Atual->Prox != NULL){
            Atual = Atual->Prox;
        }
        Atual->Prox = NovoNo;
    }
}

void Imprimir (No* Lista){
    if(Lista == NULL){
        printf("Vazio\n");
    }
    while(Lista != NULL){
        printf("Lista: %d\n", Lista->num);
        Lista = Lista->Prox;
    }
}

int main(void){
    No *cabeca = NULL;
    int valor = -1;

    do {
        printf("Digite o numero que quer inserir (0 para sair): \n");
        scanf("%d", &valor);

        if (valor != 0) {
            InserirnoFim(&cabeca, valor);
            Imprimir(cabeca);
        }

    } while (valor != 0);
    return 0;
}