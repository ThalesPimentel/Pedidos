#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No
{
    int Idade;
    char Nome[80];
    struct No* Proximo;

}No;

void InserirnoFim (No** Lista, char *Nome){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar memoria");
        return;
    }

    strcpy(NovoNo->Nome, Nome);
    NovoNo->Proximo = NULL;
    if(*Lista == NULL){
        *Lista = NovoNo;
    }
    else{
        No* Atual = *Lista;
        while (Atual->Proximo != NULL)
        {
            Atual = Atual->Proximo;
        }
        Atual->Proximo = NovoNo;
    }
    printf("Salvo");
}

void Remover(No** Lista, char* Pessoa){
    No* Anterior = malloc(sizeof(No));
    No* Atual = *Lista;

    while (Atual != NULL && strcmp(Atual->Nome, Pessoa) != 0){
    {
        Anterior = Atual;
        Atual = Atual->Proximo;
    }
    if(Atual == NULL){
        printf("O nome não está na lista");
    }
    else{
        if(Anterior == NULL){
            *Lista = Atual->Proximo;
        }else{
            Anterior->Proximo = Atual->Proximo;
        }
    }
    }
    free(Atual);
    printf("Removido");
}

void Imprimir(No* Lista){
    if(Lista == NULL){
        printf("Lista Vazia");
    }

    while (Lista != NULL)
    {
        printf("Nome: %s", Lista->Nome);
        printf("Idade: %d", Lista->Idade);
        Lista = Lista->Proximo;
    }
}

int main(void){
    No* Lista = NULL;

    InserirnoFim(&Lista, "Ana");
        printf("\n");

    InserirnoFim(&Lista, "Carlos");
        printf("\n");

    InserirnoFim(&Lista, "Bruna");
        printf("\n");


    printf("Antes da remoção:\n");
    Imprimir(Lista);
    printf("\n");

    Remover(&Lista, "Carlos");

    printf("\nDepois da remoção:\n");
    Imprimir(Lista);

    printf("\n");

    // Liberar memória
    No* temp;
    while (Lista != NULL){
        temp = Lista;
        Lista = Lista->Proximo;
        free(temp);
    }

    return 0;
}
