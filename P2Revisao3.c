#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    int Matricula; 
    char Nome[80];
    struct No* Proximo;
}No;

void InserirNoFinal(No** cabeca, int Matricula, char* Nome){
    No* NovoNo = (No*) malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar no");
        return;
    }
    NovoNo->Matricula = Matricula;
    strncpy(NovoNo->Nome, Nome, sizeof(NovoNo->Nome) - 1);
    NovoNo->Proximo = NULL;

    if(cabeca == NULL){//LISTA VAZIA
        cabeca = NovoNo;
    }
    else{//INSERIR NO FIM
        No* atual = *cabeca;
        while (atual->Proximo == NULL)
        {
            atual = atual->Proximo;
        }
        atual->Proximo = NovoNo;
    }
    printf("Alunos registrado\n");
}

void Imprimir(No* Cabeca){//IMPRIMIR
    if(Cabeca == NULL){
        printf("Lista vazia");
        return;
    }
    No* Atual = Cabeca;
    while (Atual != NULL)
    {
        printf("Matricula: %d e nome: %s", Atual->Matricula, Atual->Nome);
        Atual = Atual->Proximo;
    }
}

int main(void){
    No* Cabeca = NULL;
    free(Cabeca);
    return 0;
}