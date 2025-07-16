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

void Remover (No** Lista, int Excluir){
    No* Anterior = NULL;
    No* Atual = *Lista;

    if(Atual == NULL){
        return;
    }
    while(Atual != NULL && Atual->num != Excluir){
        Anterior = Atual;
        Atual = Atual->Prox;
    }
    if(Atual == NULL){
        printf("Valor não encontrado");
    }else{
        if(Anterior == NULL){
            *Lista = Atual->Prox;
        }
        else{
            Anterior->Prox = Atual->Prox;
        }
        free(Atual);
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

    char opcao;
    printf("Deseja remover algum item? S ou N");
    scanf(" %c", &opcao);
    if(opcao == 'N'){
        free(cabeca);
        return 0;
    }
    int excluir = 0;

    if(opcao == 'S'){
        printf("Digte o valor que quer que seja retirado: \n");
        scanf("%d", &excluir);
        Remover(&cabeca, excluir);
        Imprimir(cabeca);
    }

    No* aux;
    while (cabeca != NULL) {
        aux = cabeca;
        cabeca = cabeca->Prox;
        free(aux);
    }
    
    return 0;
}