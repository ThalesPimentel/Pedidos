#include <stdio.h>
#include <stdlib.h>

typedef struct No
{
    int Valor;
    struct No *Proximo;
}Registro;

//Inserir no Inicio SIMPLESMENTE
void InserirInicio(Registro **lista, int num){
    Registro *NovoNo = malloc(sizeof(Registro));
    if(NovoNo == NULL){
        printf("erro ao alocar memoria");
    }else{
        NovoNo -> Valor = num;
        NovoNo -> Proximo = *lista;
        *lista = NovoNo;
    }
}

//Inserir no Final SIMPLESMENTE
void InserirFinal(Registro **lista, int num){
    Registro *aux, *NovoNo = malloc(sizeof(Registro));
    if(NovoNo == NULL){
        printf("Erro ao alocar memoria");
    }
    else{
        NovoNo -> Valor = num;
        NovoNo -> Proximo = NULL;
        if(*lista == NULL){
            *lista = NovoNo;
        }else{
            aux = *lista;
            while(aux -> Proximo != NULL){
                aux = aux-> Proximo;
            }
            aux -> Proximo = NovoNo;
        }
    }
}

//Inserir no Meio SIMPLESMENTE
void InserirMeio(Registro **lista, int num, int ant){
    Registro *aux, *NovoNo = malloc(sizeof(Registro));
    if(NovoNo == NULL){
        printf("Erro a alocar memoria");
    }else{
        NovoNo -> Valor = num;
        if(*lista == NULL){
            NovoNo -> Proximo = NULL;
            *lista = NovoNo;
        }
        else{
            aux = *lista;
            while(aux -> Valor != ant && aux -> Proximo != NULL){
                aux = aux -> Proximo; 
            NovoNo -> Proximo =  aux -> Proximo;
            aux -> Proximo = NovoNo;
            }
        }
    }
}

//Imprimir SIMPLESMENTE
void Imprimir(Registro *No){
    while(No != NULL){
        printf("%d ", No -> Valor);
        No = No -> Proximo;
    }
}

//REMOVER
Registro* Remover(Registro **lista, int num){
    Registro *aux, *Remover = NULL;
    
    if(*lista != NULL){
        if((*lista) -> Valor = num){
            Remover = *lista;
            *lista = Remover -> Proximo;
        }else{
            aux = *lista;
            while(aux -> Proximo != NULL && aux -> Proximo -> Valor != num){
                aux = aux -> Proximo;
                if(aux -> Proximo != NULL){
                    Remover = aux -> Proximo;
                    aux -> Proximo = Remover -> Proximo;
                }
            }
        }
    }
}
