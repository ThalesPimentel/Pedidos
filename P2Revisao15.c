#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No{
    int idade;
    char Nome[80];
    struct No* Proximo;
    struct No* Anterior;
}No;

void Inserir(No** Lista, int idade){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar memoria");
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
    NovoNo->Proximo = Atual;
}

void Free(No* Lista){
    No* temp;
    while(Lista != NULL){
        temp = Lista;
        Lista = Lista->Proximo;
        free(temp);
    }
}

void Imprimir(No* Lista){
    if(Lista == NULL){
        printf("Lista vazia");
        return;
    }

    No* Atual = Lista;
    while(Atual != NULL){
        printf("idade: %d", Atual->idade);
        Atual = Atual->Proximo;
    }
}

void Pesquisar(No** Lista, int Localizado){
    No* Atual = *Lista;
    if(Atual == NULL){
        printf("Lista vazia");
        return;
    }

    while (Atual != NULL){
        if(Atual->idade == Localizado){
            printf("Idade localizada pela: %s", Atual->Nome);
            return;
        }
        Atual = Atual->Proximo;
    }
    
    printf("Idade não está na lista");
}

void InserirnoMeio(No** Lista, int idade, int posicao){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar memoria");
        return;
    }

    NovoNo->idade = idade;
    if(*Lista == NULL || posicao == 0){
        NovoNo->Proximo = *Lista;
        *Lista = NovoNo;
        return;
    }

    No* Atual = *Lista;
    int aux = 0;
    while(Atual != NULL && aux != posicao){
        Atual = Atual->Proximo;
        aux++;
    }

    NovoNo->Proximo = Atual->Proximo;
    Atual->Proximo = NovoNo;
}

void Delecao(No** Lista, int idade, int idadeRemover){
    No* Atual = *Lista;
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

void Delecao2(No** Lista, int idade, int remover){
    No* Atual = *Lista;
    No* Anterior = NULL;

    while(Atual != NULL){
        if(Atual->idade == remover){
            No* temp;
            if(Anterior == NULL){
                *Lista = Atual->Proximo;
                Atual = *Lista;
            }
            else{
                Anterior->Proximo = Atual->Proximo;
                Atual = Atual->Proximo;
            }
        }
        else{
            Anterior = Atual;
            Atual = Atual->Proximo;
        }
    }
}

int main(void) {
    No* Lista = NULL;
    FILE* Arq = fopen("Cadastro.txt", "w");
    if(Arq == NULL){
        printf("Erro ao abrir o arquivo1");
        return;
    }

    FILE* Arq1 = fopen("Dados.dat", "wb");
    if(Arq1 == NULL){
        printf("Erro ao abrir o arquvio2");
        return;
    }

    Inserir(&Lista, 25);
    Inserir(&Lista, 30);
    Inserir(&Lista, 40);

    printf("\nImprimindo a lista:\n");
    Imprimir(Lista);

    printf("\nPesquisando idade 30:\n");
    Pesquisar(&Lista, 30);

    printf("\nPesquisando idade 50:\n");
    Pesquisar(&Lista, 50);

    printf("\nInserindo idade 35 no meio (posicao 1):\n");
    InserirnoMeio(&Lista, 35, 1);

    printf("\nImprimindo apos insercao no meio:\n");
    Imprimir(Lista);

    printf("\nRemovendo idade 25:\n");
    Delecao(&Lista, 0, 25);

    printf("\nImprimindo apos delecao:\n");
    Imprimir(Lista);

    Free(Lista);

    return 0;
}