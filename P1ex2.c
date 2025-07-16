#include <stdio.h>

int main(void){
    
    int num = -1;
    FILE* Arq = fopen("Numero.txt", "r");
    if(Arq == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }
    int par = 0;
    int impar = 0;

    while (fscanf(Arq, "%d", &num) == 1)
    {
        if(num % 2 == 0){
            par++;
        }else{
            impar++;
        }
    }

    printf("Quantidade de Pares: %d, Quantidade de impares: %d", par, impar);
    fclose(Arq);

    return 0;
}