#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct No
{
    int idade;
    struct No *Proximo;
    struct No* Anterior;
} No;

void InserirnoMeio(No** Lista, int idade, int posicao){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar o No");
        return;
    }
    NovoNo->idade = idade;
    
    if(posicao == 0 || *Lista == NULL){
        NovoNo->Proximo = *Lista;
        *Lista = NovoNo;
        return;
    }

    No* Atual = *Lista;
    int aux = 0;
    while(aux < posicao - 1 && Atual->Proximo != NULL){
        Atual = Atual->Proximo;
        aux++;
    }
    NovoNo->Proximo = Atual->Proximo;
    Atual->Proximo = NovoNo;
}

void InserirnoMeioDupla(No** Lista, int idade, int posicao){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar o no");
        return;
    }
    NovoNo->idade = NovoNo;
    NovoNo->Anterior = NULL;
    NovoNo->Proximo = NULL;

    if(posicao == 0 || *Lista == NULL){
        NovoNo->Proximo = *Lista;
        if(*Lista != NULL){
            (*Lista)->Anterior = NovoNo;
        }
    }
    *Lista = NovoNo;
    return;

    No* Atual = *Lista;
    int aux = 0;
    while (aux < posicao - 1 && Atual->Proximo != NULL)
    {
        Atual = Atual->Proximo;
        aux++;
    }
    
    NovoNo->Proximo = Atual->Proximo;
    NovoNo->Anterior = Atual;

    if(Atual->Proximo !=NULL){
        Atual->Proximo->Anterior = NovoNo;
    }
    Atual->Proximo = NovoNo;
}

void Delecao(No** Lista, int idadeRemover){
    No *Atual = *Lista;
    No* Anterio = NULL;
    
    while(Atual != NULL){
        if(Atual->idade == idadeRemover){
            No* temp = Atual;
            if(Anterio == NULL){
                *Lista = Atual->Proximo;
                Atual = *Lista;
            }
            else{
                Anterio->Proximo = Atual->Proximo;
                Atual = Atual->Proximo;
            }
            free(temp);
        }
        else{
            Anterio = Atual;
            Atual = Atual->Proximo;
        }
    }
}

int main(void){
    return 0;
}