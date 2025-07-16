#include <stdio.h>
#include <stdlib.h>

int main(void){
    int Idade = -2;
    int *Vetor = NULL;
    int tamanho = 0;

    FILE *Arq = fopen("valores.txt", "w");
    if(Arq == NULL){
        printf("Erro ao alocar o arquivo");
        return;
    }

    do{
        printf("Digite sua idade: \n");
        scanf("%d", &Idade);
    if (Idade != -1) {
        Vetor = realloc(Vetor, (tamanho + 1) * sizeof(int));
        Vetor[tamanho] = Idade;
        tamanho++;
    }

    } while(Idade != -1);

    for(int i = 0; i < tamanho; i++){
        fprintf(Arq, "%d\n", Vetor[i]);
    }
    
    free(Vetor);
    fclose(Arq);
    return 0;
}