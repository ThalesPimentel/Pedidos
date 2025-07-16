#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No
{
    int idade;
    char nome[80];
    struct No *Proximo;
    struct No *Anterior;
} No;

void InserirNoInicio(No **cabeca, int idade, char *Nome)
{
    No *NovoNo = malloc(sizeof(No));
    NovoNo->idade = idade;
    strcpy(NovoNo->nome, Nome);

    NovoNo->Proximo = *cabeca;
    NovoNo->Anterior = NULL;
    if (*cabeca != NULL)
    {
        (*cabeca)->Anterior = NovoNo;
    }
    *cabeca = NovoNo;
}

void AlterarLista(No *cabeca, char *nome)
{
    No *atual = cabeca;
    int novaidade = 0;
    int achou = 0;
    while (atual != NULL)
    {
        if (strcmp(atual->nome, nome) == 0)
        {
            printf("Digite a nova idade\n");
            scanf("%d", &novaidade);
            atual->idade = novaidade;
            achou = 1;
            break;  
        }
        atual = atual->Proximo;
    }
    if (!achou)
    {
        printf("Nome não está na lista");
    }
}

void Imprimir(No *cabeca)
{
    if (cabeca == NULL)
    {
        printf("Lista vazia");
        return;
    }

    while (cabeca != NULL)
    {
        printf("Idade: %d\n", cabeca->idade);
        printf("Nome: %s\n", cabeca->nome);
        cabeca = cabeca->Proximo;
    }
}

int main(void)
{
    No *Inicio = NULL;
    char nome[80];
    int idade = 0;
    char alterado[80];

    printf("DIgite o nome e idade");
    scanf("%s %d", nome, &idade);
    InserirNoInicio(&Inicio, idade, nome);
    printf("Digite o nome que vai ser alterado: ");
    scanf("%s", alterado);
    AlterarLista(Inicio, alterado);
    Imprimir(Inicio);
    free(Inicio);
    return 0;
}