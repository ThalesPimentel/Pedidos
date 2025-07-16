#include <stdio.h>

typedef struct Pessoas
{
    char Nome[80];
    int idade;
}Registro;

int main(void){
    float Idadetotal = 0.0;
    FILE* Arq = fopen("Pessoas.dat", "wb");
    Registro Pessoas;
    float Media = 0.0;
    int count = 0;
    
    for(int i = 0; i < 100; i++){
        printf("Digite o nome: \n");
        scanf("%s", Pessoas.Nome);
        printf("Digite a idade: \n");
        scanf("%d", &Pessoas.idade);

        if(Pessoas.idade == 0){
            break;;
        }

        Idadetotal += Pessoas.idade;
        fwrite(&Pessoas, sizeof(Registro), 1, Arq);
        count++;
    }
    fclose(Arq);

    Media = Idadetotal/count;
    Arq = fopen("Pessoas.dat", "rb");
    while (fread(&Pessoas, sizeof(Registro), 1, Arq))
    {
        if(Pessoas.idade > Media){
            printf("Pessoa: %s, Idade: %d\n", Pessoas.Nome, Pessoas.idade);
        }
    }

    fclose(Arq);
    return 0;
}