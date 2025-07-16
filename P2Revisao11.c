#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int Idade;
    struct No* Proximo;
}No;

void InserirnoFim(No** Lista, int Idade){
    No* NovoNo = malloc(sizeof(No));
    if(NovoNo == NULL){
        printf("Erro ao alocar o Nó");
        return;
    }
    
    NovoNo->Idade = Idade;
    NovoNo->Proximo = NULL;
    if(*Lista == NULL){
        *Lista = NovoNo;
        return;
    }
    No* Atual = *Lista;
    while (Atual->Proximo != NULL)
    {
        Atual = Atual->Proximo;
    }
    Atual->Proximo = NovoNo;
}

int main(void){
    No Registro;

    
    return 0;
}