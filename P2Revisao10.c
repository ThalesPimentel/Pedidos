#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char Nome[80];
    int Idade;
    struct No* Proximo;
}No;

void Free(No* Lista){
    No* Temp;
    while(Lista != NULL){
        Temp = Lista;
        Lista = Lista->Proximo;
        free(Temp);
    }
}

void Imprimir(No* Lista){
    No *Atual = Lista;
    if(Atual == NULL){
        printf("Vazio\n");
        return;
    }
    while(Atual != NULL){
        printf("Nomes: %s Idade: %d \n", Atual->Nome, Atual->Idade);
        Atual = Atual->Proximo;
    }
}

void Inserir(FILE* Arq, No** Lista, No** fim){
    No Registro;
    while (fread(&Registro, sizeof(Registro), 1, Arq) == 1){
        No* NovoNo = malloc(sizeof(No));
        if(NovoNo == NULL){
            printf("Erro ao alocar o no\n");
            return;
        }
        *NovoNo = Registro;
        NovoNo->Proximo = NULL;

        if(*Lista == NULL){
            *Lista = NovoNo;
            *fim = NovoNo;
        }
        else{
            (*fim)->Proximo = NovoNo;
            *fim = NovoNo;
        }
    }
}

int main(void){
    No Pessoa;

    FILE* Arq = fopen("Pessoas.dat", "wb");
    if(Arq == NULL){
        printf("Erro ao salvar o arquivo");
        return;
    }

    for(int i = 0; i < 100; i++){
        printf("Digite o nome e idade: \n");
        scanf("%s %d", &Pessoa.Nome, &Pessoa.Idade);
        if(Pessoa.Idade == 0){
            break;
        }
        fwrite(&Pessoa, sizeof(Pessoa), 1, Arq);
    }
    fclose(Arq);

    Arq = fopen("Pessoas.dat", "rb");
    if(Arq == NULL){
        printf("Erro ao abrir o arquvio");
        return;
    }

    No* cabeca = NULL;
    No* fim = NULL;

    Inserir(Arq, &cabeca, &fim);
    Imprimir(cabeca);
    Free(cabeca);
    fclose(Arq);
    return 0;
}