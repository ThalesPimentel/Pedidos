#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct No
{
    char Nome[80];
    int Idade;
    struct No* Proximo;
}No;


int main(void){
    No Registro;
    int soma = 0;
    int aux = 0;
    float MediaIdade = 0.00;

    FILE* Arq = fopen("Pessoas.dat", "wb");
    if(Arq == NULL){
        printf("Erro ao salvar o arquivo");
        return;
    }

    for(int i = 0; i < 100; i++){
        printf("Digite o nome e idade: \n");
        scanf("%s %d", &Registro.Nome, &Registro.Idade);
        if(Registro.Idade == 0){
            break;
        }
        fwrite(&Registro, sizeof(Registro), 1, Arq);
    }
    fclose(Arq);

    Arq = fopen("Pessoas.dat", "rb");
    if(Arq == NULL){
        printf("Erro ao abrir o arquvio");
        return;
    }

    No* cabeca = NULL;
    No* fim = NULL;

    while (fread(&Registro, sizeof(Registro), 1, Arq) == 1)
    {
        No* NovoNo = malloc(sizeof(No));
        if(NovoNo == NULL){
            printf("Erro ao alocar o no");
            return 0;
        }
        *NovoNo = Registro;
        NovoNo->Proximo = NULL;
        
        if(cabeca == NULL){
            cabeca = NovoNo;
            fim = NovoNo;
        }
        else{
            fim->Proximo = NovoNo;
            fim = NovoNo;
        }
    }

    char NomeRemover[80];
    printf("Digite o Nome de deseja remover: \n");
    scanf("%s", &NomeRemover);
    No* Atual = cabeca;
    No* Anterior = NULL;
    while (Atual != NULL)
    {
        if(strcmp(Atual->Nome, NomeRemover) == 0){
            No* Temp = Atual;
            if(Anterior == NULL){
                cabeca = Atual->Proximo;
                Atual = cabeca;
            }
            else{
                Anterior->Proximo = Atual->Proximo;
                Atual = Atual->Proximo;
            }
            free(Temp);
        }

        else{
            Anterior = Atual;
            Atual = Atual->Proximo;
        }
    }

    Atual = cabeca;
    if(Atual == NULL){
        printf("Vazio\n");
    }
    while(Atual != NULL){
        printf("Nomes: %s Idade: %d \n", Atual->Nome, Atual->Idade);
        Atual = Atual->Proximo;
    }

    No* Temp;
    while(cabeca != NULL){
        Temp = cabeca;
        cabeca = cabeca->Proximo;
        free(Temp);
    }
    fclose(Arq);
    return 0;
}