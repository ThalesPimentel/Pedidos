#include <stdio.h>
#include <stdlib.h>

typedef struct Pessoal2
{
    char Nome[80];
    int idade;
} Registro;

int main(void)
{
    FILE *Arq = fopen("Cadastro.dat", "wb");
    Registro *Vetor = NULL;
    int tamanho = 0;

    Registro Pessoa;
    do
    {
        printf("Digite seu nome: ");
        scanf("%s", Pessoa.Nome);
        printf("Digite a sua idade: ");
        scanf("%d", &Pessoa.idade);
        if (Pessoa.idade != 0)
        {
            Vetor = realloc(Vetor, (tamanho + 1) * sizeof(Registro));
            Vetor[tamanho] = Pessoa;
            tamanho++;
        }

    } while (Pessoa.idade != 0);

    fwrite(Vetor, sizeof(Registro), tamanho, Arq);

    free(Vetor);
    fclose(Arq);
    return 0;
}