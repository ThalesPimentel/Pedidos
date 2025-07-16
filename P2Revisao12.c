#include <stdlib.h>
#include <stdio.h>

typedef struct No{
    int idade;
    struct No* Proximo;
    struct No* Anterior;
}No;

void InserirnoFim(No** Lista, int idade){// SIMPLESMENTE
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro alocar a memoria");
        return;
    }
    NovoNo->idade = idade;
    NovoNo->Proximo = NULL;
    if(*Lista == NULL){
        *Lista = NovoNo;
        return;
    }
    No* Atual = *Lista;
    while(Atual->Proximo != NULL){
        Atual = Atual->Proximo;
    }
    Atual->Proximo = NovoNo;
}

void InserirNoFim(No** Lista, int Idade){//DUPLAMENTE
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar memoria");
        return;
    }
    NovoNo = *Lista;
    NovoNo->Proximo = NULL;
    if(*Lista == NULL){
        *Lista = NovoNo;
        return;
    }
    No* Atual = *Lista;
    while(Atual->Proximo != NULL){
        Atual = Atual->Proximo;
    }
    Atual->Proximo = NovoNo;
    NovoNo->Anterior = Atual;
}

void Imprimir(No* Lista){//IMPRIMIR
    No* Atual = Lista;
    if(Atual == NULL){
        printf("Lista Vazia");
        return;
    }

    while(Atual != NULL){
        printf("%d", Atual->idade);
        Atual = Atual->Proximo;
    }
}

void Free(No* Lista){//LIBERAR MEMORIA
    No* Temp;
    while(Lista != NULL){
        Temp = Lista;
        Lista = Lista->Proximo;
        free(Temp);
    }
}

void Delecao(No** Lista, int idadeRemover){//SIMPLESMTE
    No* Atual = *Lista;
    No* Anterior = NULL;

    while(Atual != NULL){
        if(Atual->idade == idadeRemover){
            No* temp = Atual;
            
            if(Anterior = NULL){
                *Lista = Atual->Proximo;
                Atual = *Lista;
            }
            else{
                Anterior->Proximo = Atual->Proximo;
                Atual = Atual->Proximo;
            }
            free(temp);
        }

        else{
            Anterior = Atual;
            Atual = Atual->Proximo;
        }
    }
}