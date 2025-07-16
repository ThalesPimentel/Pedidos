#include <stdio.h>
#include <stdlib.h>

int main(void){
    int num = -1;
    FILE* Aqr = fopen("Numeros.txt", "w");

    if(Aqr == NULL){
        printf("Erro ao abrir o arquvio\n");
        return;
    }

    do
    {
        printf("Digite um numero: ");
        scanf("%d", &num);
        if(num != 0){
            fprintf(Aqr, "%d\n", num);
        }
    } while (num != 0);
    

    fclose(Aqr);
    return 0;
}