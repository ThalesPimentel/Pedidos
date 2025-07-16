#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    char Nome[80];
    float Nota;
    No* Proximo;
}No;

void InserirFim(No** Lista, char* Nome, float Nota){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar o No");
        return;
    }

    strcpy(NovoNo->Nome, Nome);
    NovoNo->Nota = Nota;
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

void Free(No* Lista){
    No* temp;
    while(Lista != NULL){
        temp = Lista;
        Lista = Lista->Proximo;
        free(temp);
    }
}

/*void Imprimir(No* Lista){
    if(Lista == NULL){
        printf("Lista Vazia");
        return;
    }

    No* Atual = Lista;
    while(Atual != NULL){
        printf("Nome: %s Nota: %.2f\n", Atual->Nome, Atual->Nota);
        Atual = Atual->Proximo;
    }
}

void Delecao(No** Lista, char* NomeRemover){
    No* Atual = *Lista;
    No* Anterior = NULL;
    while(Atual != NULL){
        if(strcmp(Atual->Nome, NomeRemover) == 0){
            No* temp = Atual;
            if(Anterior == NULL){
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
}*/

int BuscarImprimirEDeletar(No** Lista, char* NomeRemover){
    No* Atual = *Lista;
    No* Anterior = NULL;
    while (Atual != NULL) {
        if (strcmp(Atual->Nome, NomeRemover) == 0) {
            printf("Nota de %s: %.2f\n", Atual->Nome, Atual->Nota);
            if (Anterior == NULL)
                *Lista = Atual->Proximo;
            else
                Anterior->Proximo = Atual->Proximo;
            free(Atual);
            return 1;
        }
        Anterior = Atual;
        Atual = Atual->Proximo;
    }
    printf("Nome não encontrado.\n");
    return 0;
}

int main(void){
    No *Registro = NULL;
    char NomeRemover[80];

    FILE* Arq = fopen("Cadastro.dat", "rb");
    if(Arq == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    char Nome[80];
    float Nota = 0.00;

    while(fread(Nome, sizeof(char), 80, Arq) == 80 && fread(&Nota, sizeof(float), 1, Arq) == 1){
        InserirFim(&Registro, Nome, Nota);
    }
    fclose(Arq);

    int opcao = 0;
    printf("Você quer Excluir?");
    scanf(" %c", &opcao);

    do
    {
        printf("Digite o Nome que deseja excluir");
        scanf("%s", NomeRemover);

        printf("\nLista antes da exclusão:\n");
        Imprimir(Registro);

        BuscarImprimirEDeletar(&Registro, NomeRemover);

        printf("\nLista após a exclusão:\n");
        Imprimir(Registro);

        printf("Você quer Excluir?");
        scanf(" %c", &opcao);
    } while (opcao != 'n' && opcao != 'N');

    printf("Fechando...");

    Free(Registro);
    return 0;
}