#include <stdio.h>

typedef struct No
{
    int idade;
    char Nome[80];
    struct No* Proximo;
}No;

int main(void){
    No *Atual = NULL;
    No* Anterior = NULL;
    No* Inicio = NULL;

    FILE* Arq = fopen("Cadastro.dat", "wb");
    if(Arq == NULL){
        printf("Erro ao abrir o arquivo: ");
        return;
    }

    do
    {
        Atual = malloc(sizeof(No));
        printf("Digite o nome: \n");
        scanf("%s", Atual->Nome);
        printf("DIgite sua idade: \n");
        scanf("%d", &Atual->idade);
        if(Atual->idade == 0){
            free(Atual);
            break;
        }
        fwrite(Atual, sizeof(No), 1, Arq);
        if(Inicio == NULL){
            Inicio = Atual;
        }
        else{
            Anterior->Proximo = Atual;
        }
        Anterior = Atual;

    } while (Atual->idade != 0);

    Atual = Inicio;
    while(Atual != NULL){
        No* temp = Atual;
        Atual = Atual->Proximo;
        free(temp);
    }
    fclose(Arq);
    return 0;
}