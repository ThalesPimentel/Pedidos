#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No {
    char Nome[80];
    struct No* Proximo;
} No;

void Imprimir(No* Lista) {
    if (Lista == NULL) {
        printf("Lista vazia\n");
        return;
    }

    No* Atual = Lista;
    while (Atual != NULL) {
        printf("Nome: %s\n", Atual->Nome);
        Atual = Atual->Proximo;
    }
}

void Free(No* Lista) {
    No* temp;
    while (Lista != NULL) {
        temp = Lista;
        Lista = Lista->Proximo;
        free(temp);
    }
}

void InserirOrdenado(No** Lista, char* Nome) {
    // Verifica se o nome já existe
    No* Verifica = *Lista;
    while (Verifica != NULL) {
        if (strcmp(Verifica->Nome, Nome) == 0)
            return;
        Verifica = Verifica->Proximo;
    }

    // Aloca novo nó
    No* NovoNo = malloc(sizeof(No));
    if (NovoNo == NULL) {
        printf("Erro ao alocar o nó\n");
        return;
    }

    strcpy(NovoNo->Nome, Nome);
    NovoNo->Proximo = NULL;

    // Inserção no início
    if (*Lista == NULL || strcmp(Nome, (*Lista)->Nome) < 0) {
        NovoNo->Proximo = *Lista;
        *Lista = NovoNo;
        return;
    }

    // Inserção no meio/fim
    No* Atual = *Lista;
    while (Atual->Proximo != NULL && strcmp(Nome, Atual->Proximo->Nome) < 0) {
        Atual = Atual->Proximo;
    }

    NovoNo->Proximo = Atual->Proximo;
    Atual->Proximo = NovoNo;
}

int main(void) {
    No* Lista = NULL;
    FILE* Arq1 = fopen("Texto1.txt", "r");
    FILE* Arq2 = fopen("Texto2.txt", "r");

    if (Arq1 == NULL || Arq2 == NULL) {
        printf("Erro ao abrir um dos arquivos\n");
        if (Arq1) fclose(Arq1);
        if (Arq2) fclose(Arq2);
        return 1;
    }

    char Nome[80];

    // Lê nomes do primeiro arquivo
    while (fscanf(Arq1, "%s", Nome) == 1) {
        InserirOrdenado(&Lista, Nome);
    }
    fclose(Arq1);

    // Lê nomes do segundo arquivo
    while (fscanf(Arq2, "%s", Nome) == 1) {
        InserirOrdenado(&Lista, Nome);
    }
    fclose(Arq2);

    // Imprime lista final
    printf("\nLista final em ordem alfabética (sem repetições):\n");
    Imprimir(Lista);

    Free(Lista);
    return 0;
}