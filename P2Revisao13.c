#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct No
{
    char Nome[80];
    int idade;
    struct No *Proximo;
} No;

void Inserir(No **Lista, int idade, char *Nome)
{
    No *NovoNo = malloc(sizeof(No));
    if (NovoNo == NULL)
    {
        printf("Erro ao alocar a memoria");
        return;
    }
    strcpy(NovoNo->Nome, Nome);
    NovoNo->idade = idade;
    NovoNo->Proximo = NULL;

    if (*Lista == NULL)
    {
        *Lista = NovoNo;
        return;
    }

    No *Atual = *Lista;
    while (Atual->Proximo != NULL)
    {
        Atual = Atual->Proximo;
    }
    Atual->Proximo = NovoNo;
}

int main(void)
{
    No Registro;
    No *Cabeça = NULL;
    int Soma = 0, cont = 0;
    float Media = 0.00;

    FILE *Arq = fopen("Dados.dat", "wb");
    if (Arq == NULL)
    {
        printf("Erro ao abrir o Arquvo");
        return;
    }

    do
    {
        printf("Digite o nome e idade: \n");
        scanf("%s %d", Registro.Nome, &Registro.idade);
        if (Registro.idade == 0)
        {
            break;
        }
        Soma += Registro.idade;
        cont++;
        Inserir(&Cabeça, Registro.idade, Registro.Nome);
        fwrite(&Registro, sizeof(Registro), 1, Arq);
    } while (Registro.idade != 0);
    
    Media = (float)Soma / cont;

    No *Atual = Cabeça;
    if (Atual == NULL)
    {
        printf("Lista Vazia\n");
        return;
    }else{
        while (Atual != NULL){
            if(Atual->idade > Media){
                printf("Nome: %s idade: %d", Atual->Nome, Atual->idade);
            }
            Atual = Atual->Proximo;
        }
    }

    No *Temp;
    while (Cabeça != NULL)
    {
        Temp = Cabeça;
        Cabeça = Cabeça->Proximo;
        free(Temp);
    }

    fclose(Arq);
    return 0;
}