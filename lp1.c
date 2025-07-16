
//Questão 26

/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pegarCarta() {
    return rand() % 13 + 1;
}

int valorCarta(int carta, int somaAtual) {
    if (carta >= 11) {
        return 10; // J, Q, K
    } else if (carta == 1) {
        if (somaAtual + 11 <= 21) {
            return 11; 
        } else {
            return 1; 
        }
    } else {
        return carta; 
    }
}

int main(void) {
    srand(time(NULL)); 

    int controlador = 0;
    int somaJogador = 0, somaBanca = 0;

    int num1 = pegarCarta();
    int valor1 = valorCarta(num1, somaJogador);
    somaJogador += valor1;

    int num2 = pegarCarta();
    int valor2 = valorCarta(num2, somaJogador);
    somaJogador += valor2;

    printf("Suas cartas: %d e %d\n", num1, num2);
    printf("Sua soma: %d\n", somaJogador);

    if (somaJogador > 21) {
        printf("Você perdeu! Estourou 21.\n");
        return 0;
    }

    printf("Digite 1 para continuar ou 0 para parar: ");
    scanf("%d", &controlador);

    while (somaJogador <= 21 && controlador == 1) {
        int novaCarta = pegarCarta();
        int valor = valorCarta(novaCarta, somaJogador);
        somaJogador += valor;

        printf("Você tirou: %d (vale %d)\n", novaCarta, valor);
        printf("Nova soma: %d\n", somaJogador);

        if (somaJogador > 21) {
            printf("Você perdeu! Estourou 21.\n");
            return 0;
        }

        printf("Digite 1 para continuar ou 0 para parar: ");
        scanf("%d", &controlador);
    }

    printf("\nVocê parou com a soma: %d\n", somaJogador);

    printf("\n--- Turno da Banca ---\n");

    while (somaBanca <= somaJogador && somaBanca < 21) {
        int cartaBanca = pegarCarta();
        int valorBanca = valorCarta(cartaBanca, somaBanca);
        somaBanca += valorBanca;
        printf("Banca tirou: %d (vale %d), soma: %d\n", cartaBanca, valorBanca, somaBanca);
    }

    printf("\nResultado final:\n");
    printf("Sua soma: %d\n", somaJogador);
    printf("Soma da banca: %d\n", somaBanca);

    if (somaBanca > 21) {
        printf("Banca estourou! Você venceu!\n");
    } else if (somaBanca > somaJogador) {
        printf("A banca venceu!\n");
    } else if (somaBanca < somaJogador) {
        printf("Você venceu!\n");
    } else {
        printf("Empate!\n");
    }

    return 0;
}

*/


//Questão 16
/*

#include <stdio.h>
#include <stdlib.h>

int comparar(int dado1, int dado2, int dado3, int dado4){
    if(dado1 == dado2 && dado3 != dado4){
        return 1;
    }

    if(dado3 == dado4 && dado1 != dado2){
        return 2;
    }

    if (dado1 == dado2 && dado3 == dado4){
        if (dado1 > dado3){
            return 1; 
        } else if (dado1 < dado3){
            return 2;
        } else {
            return 0;
        }
    }

    int soma_jogador1 = dado1 + dado2;
    int soma_jogador2 = dado3 + dado4;

    if (soma_jogador1 > soma_jogador2){
        return 1; 
    } else if (soma_jogador1 < soma_jogador2){
        return 2;
    } else {
        return 0;
    }
}


int main(void){
    
    int dado1 = rand() % 6 + 1; 
    int dado2 = rand() % 6 + 1;
    int dado3 = rand() % 6 + 1;
    int dado4 = rand() % 6 + 1;
    
    printf("Jogador 1 %d %d", dado1, dado2);
    printf("jogador 2 %d %d", dado3, dado4);

    int resultado = comparar(dado1, dado2, dado3, dado4);

    if(resultado == 1){
        printf("Jogador 1 ganhou");
    }
    if(resultado == 2){
        printf("Jogador 2 ganhou");
    }
    if(resultado == 0){
        printf("Empate");
    }
    
    return 0;
}

*/

//Questão 17
/*

#include <stdio.h>

int Bissexto(int ano){
    if(ano % 4 == 0){
        if(ano % 100 == 0){
            if(ano % 400 == 0){
                return 1;
            }else{
                return 0;
            }
        }
        return 1;
    }
    return 0;
}

int contagemdias(int dia, int mes, int ano){

    int dias = 0;
    int Diasmeses[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for(int i = 0; i < ano; i++){
        if(Bissexto(i) != 0){
            dias += 366;
        }else{
            dias += 365;
        }
    }

    for(int j = 0; j < mes - 1; j++){
        dias += Diasmeses[j];
        if(j == 1){
            if(Bissexto(ano) != 0){
                dias++;
            }
        }
    }
    dias += dia;

    return dias;
}


int main(void){
    int dia1 = 0;
    int mes1 = 0;
    int ano1 = 0;
    int dia2 = 0;
    int mes2 = 0;
    int ano2 = 0;

    scanf("%d %d %d", &dia1, &mes1, &ano1);
    scanf("%d %d %d", &dia2, &mes2, &ano2);

    int dias1 = contagemdias(dia1, mes1, ano1);
    int dias2 = contagemdias(dia2, mes2, ano2);

    int diferenca = dias2 - dias1;

    if(diferenca < 0){
        diferenca = -diferenca;
    }

    printf("Diferenca: %d", diferenca);
    
    return 0;
}

*/

//Questão 25
/*

#include <stdio.h>

int main(void){
    int num = 0;
    int duzentos = 100;
    int cem = 100;
    int cinquenta = 100;
    int vinte = 100;
    int dez = 100;
    int cinco = 100;
    int notas200 = 0, notas100 = 0, notas50 = 0, notas20 = 0, notas10 = 0, notas5 = 0;

    printf("Digite o quanto quer: \n");
    scanf("%d", &num);

    if(num > 0){
        if(num >= 200 && duzentos > 0){
            notas200 = num/200;
            if(notas200 > duzentos){
                notas200 = duzentos;
            }
            num -= notas200 * 200;
            duzentos -= notas200;
        }

        if(num >= 100 && cem > 0){
            notas100 = num/100;
            if(notas100 > cem){
                notas100 = cem;
            }
            num -= notas100 * 100;
            cem -= notas100;
        }

        if(num >= 50 && cinquenta > 0){
            notas50 = num/50;
            if(notas50 > cinquenta){
                notas50 = cinquenta;
            }
                num -= notas50 * 50;
                cinquenta -= notas50;
        }

        if(num >= 20 && vinte > 0){
            notas20 = num/20;
            if(notas20 > vinte){
                notas20 = vinte;
            }
                num -= notas20 * 20;
                vinte -= notas20;
        }

        if(num >= 10 && dez > 0){
            notas10 = num/10;
            if(notas10 > dez){
                notas10 = dez;
            }
                num -= notas10 * 10;
                dez -= notas10;
        }

        if(num >= 5 && cinco > 0){
            notas5 = num/5;
            if(notas5 > cinco){
                notas5 = cinco;
            }
                num -= notas5 * 5;
                cinco -= notas5;
        }

        if(num == 0){
            printf("saque realizado com sucesso");
            if (notas200 > 0) printf("Notas de 200: %d\n", notas200);
            if (notas100 > 0) printf("Notas de 100: %d\n", notas100);
            if (notas50 > 0) printf("Notas de 50: %d\n", notas50);
            if (notas20 > 0) printf("Notas de 20: %d\n", notas20);
            if (notas10 > 0) printf("Notas de 10: %d\n", notas10);
            if (notas5 > 0) printf("Notas de 5: %d\n", notas5);
        }else{
            printf("não é possivel realizar o saque com as notas disponiveis");
        }
    }else{
        printf("Digito invalido");
    }

    return 0;
}

/*


//Questão 1
/*
#include <stdio.h>

int main(void){
    int num = 0;
    
    while(!(num % 3 == 2 && num % 5 == 3 && num % 7 == 4)){
        num+= 1;
    }
    

    printf("%d", num);
    
    return 0;
}

*/
//Questão2

/*#include <math.h>

int primo(int n){
    if(n <2){
        return 0;
    }
    for(int i = 2; i <= sqrt(n);i++){
        if(n%i == 0){
            return 0;
        }
        return 1;
    }
}

int main(void){
    int n = 0;
    int aux = 0;

    scanf("%d", &n);

    int a = 0; 
    int b = 1;
    int temp;

    while(aux < n){
        if(primo(a)){
            printf("%d ", a);
            aux++;
        }
        temp = a + b;
        a = b;
        b = temp;
    }

    printf("\n");
    return 0;
}
*/
//#include <stdio.h>
//Questão4
/*
int main(void){
    int num = 0;
    int fatorial = 1;

    scanf("%d", &num);

    if(num == 0){
        printf("fatorial é 1");
    }
    if(num > 0){
        for(int i = 1;i<=num;i++){
            fatorial = fatorial * i;
        }
        printf("O fatorial é %d", fatorial);
    }
    
    return 0;
}*/


/*
int main(void){
//Questão 3
    int n = 0;
    int soma = 0;

    scanf("%d", &n);

    if (n < 1 || n > 32766)
    {
        printf("Erro, valor não aceito");
        return 0;
    }

    for(int i = 1; i < n; i++){
        if (n % i == 0)
        {
            soma += i;
            
        }
    }

    if (soma == n)
    {
        printf("perfeito");
    }
    else{
        printf("nao é perfeito");
    }
    
    return 0;
}*/


/*
int main(void){
//Questão 5
    int moedas[6] = {100, 50, 25, 10, 5, 1};
    int valor = 0;
    int qt = 0;

    scanf("%d", &valor);

    for(int i = 0; i<6;i++){
        qt = valor/moedas[i];
        valor = valor % moedas[i];
        if (qt > 0)
        {
            printf("A quantidade: %d e o valor: %d\n", qt, moedas[i]);
        }
        
    }
    
    return 0;
}
*/


/*
int main(void){
//Questão 6
    int total = 0, kmatual = 0, preco = 0, gasolina = 0, totalpreco = 0, totalgasolina = 0, kmantes = 0;
    int distancia = 0, totaldistancia = 0;
    float custoporkm = 0;

    printf("Quando reabastecimentos?");
    scanf("%d", &total);

    printf("km inicial, gasolina e preco");
    scanf("%d %d %d", &kmatual, &gasolina, &preco);
    
    kmantes = kmatual;
    totalgasolina += gasolina;
    totalpreco += preco;

    for(int i = 1; i< total; i++){
        printf("km, gasolina e preco");
        scanf("%d %d %d", &kmatual, &gasolina, &preco);

        distancia = kmatual - kmantes;
    
        float kmporlitro = (float)distancia / gasolina;

        kmantes += kmatual;
        totaldistancia += distancia;
        totalpreco += preco;
        totalgasolina += gasolina;
    }

    float kmtotalporlitro = (float)totaldistancia/totalgasolina;

    custoporkm = (float)totalpreco/ totaldistancia;

    printf("%.2f %.2f", kmtotalporlitro, custoporkm);

    return 0;
}
*/


/*
#include <string.h>
//Questão 7
int main(void){
    char nome[50][100];
    int notas[50];
    int notatotal = 0;
    int media = 0;
    int temp = 0;
    char tempnome[100];

    for(int i = 0; i< 50; i++){
        scanf("%d %s", &notas[i], nome[i]);
        notatotal += notas[i];
    }

    media = notatotal/50;

    for(int i = 0; i<49;i++){
        for(int j = i + 1; j < 50; j++){
            if(notas[i] < notas[j]){
                temp = notas[i];
                notas[i] = notas[j];
                notas[j] = temp;

                strcpy(tempnome, nome[i]);
                strcpy(nome[i], nome[j]);
                strcpy(nome[j], tempnome);
            
            }
        }
    }
    int aux = 0;
    for(int i = 0; i < 50 && aux < 5; i++){
        if(notas[i] > media){
            printf("%s %d\n", nome[i], notas[i]);
            aux += 1;
        }
    }

    return 0;
}
*/


/*
//Questão 8
int main(void){
    int vetor[50];
    int maior, segundo;

    for(int i = 0;i<50;i++){
        scanf("%d", &vetor[i]);
    }

    if(vetor[0] > vetor[1]){
        maior = vetor[0];
        segundo = vetor[1];
    }else{
        maior = vetor[1];
        segundo = vetor[0];
    }

    for(int i = 2; i < 50; i++){
        if(vetor[i] > maior){
            segundo = maior;
            maior = vetor[i];
        }else if(vetor[i] > segundo){
            segundo = vetor [i];
        }
    }

    printf("%d %d", maior, segundo);

    return 0;
}
*/


/*
int main(void){
//Questão 9
    char nome[80];
    int cadeia[256] = 0;
    int cont = 0; 

    for(int i = 0; i <80; i++){
        nome[i] = ' ';
    }
    
    scanf("%s", nome);

    for(int i = 0; nome[i] != '\0'; i++){
        unsigned c = nome[i];
        if (cadeia[c] == 0){
            cadeia[c] = 1;
            cont++; 
        }
    }

    printf("%d", cont);

    return 0;
}
*/

/*
int main(void){
//Questão 10
    char nome[80];
    char* token;
    int n = 0;

    printf("Digite:");
    fgets(nome, 80, stdin);

    token = strtok(nome, " .:;!?");
    
    
    while(token != NULL){
        printf("%s", token);
        token = strtok(NULL, " .:;!?");
            if(token != NULL){
                n += 1;
            }
    }

    printf("%d\n", n);

    return 0;
}

*/

/*

//Questão 11

    #include <stdio.h>
    #include <string.h>

    int vogais(char* palavra);

    int main(void){
        char nome[80];
        char* token;

        printf("Digite: ");
        fgets(nome, 80, stdin);

        token = strtok(nome, " ,.:;!");
        
        while(token != NULL){
            int aux = vogais(token);
            if ((aux) >= 3) {
                printf("%s\n", token);
            }
            token = strtok(NULL, " ,.:;!");
        }
        return 0;
    }

int vogais(char* palavra){

    int n = 0;
    int tamanho = strlen(palavra);

    for(int i = 0;i<tamanho; i++){
        if(palavra[i] == 'a' || palavra[i] == 'e' || palavra[i] == 'i' || 
        palavra[i] == 'o' || palavra[i] == 'u' || 
        palavra[i] == 'A' || palavra[i] == 'E' || palavra[i] == 'I' || 
        palavra[i] == 'O' || palavra[i] == 'U'){
    n += 1;
        }
    }
    return n;
}
*/

/*

int main(void){
//Questão 12
        int n = 0;
        int vet[999];

        scanf("%d", &n);
       
        int milhar = n / 1000;
        int centena = (n%1000)/100;
        int dezena = (n%100)/10;
        int unidade = n%10;

        char *unidades[] = {"", "um", "dois", "três", "quatro", "cinco", "seis", "sete", "oito", "nove"};
        char *dezenas[] = {"", "dez", "vinte", "trinta", "quarenta", "cinquenta", "sessenta", "setenta", "oitenta", "noventa"};
        char *especiais[] = {"dez", "onze", "doze", "treze", "quatorze", "quinze", "dezesseis", "dezessete", "dezoito", "dezenove"};
        char *centenas[] = {"", "cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};

        if(milhar > 0){
            if(milhar > 1){
                printf("mil");
            }
            else{
                printf("%s", unidades[milhar]);
            }
        }

        if(centena > 0){
            if(milhar > 0 ){
                printf(" e ");
                printf("%s", centena == 1 && dezena == 0 && unidade == 0 ? "cem" : centenas[centena]);
            }
        }
   
        if(dezena > 0){
            if(centena > 0 || milhar > 0){
                printf(" e ");
            }
            if(dezena == 1){
                printf("%s", especiais[unidade]);
                unidade = 0;
            }
            else{
                printf("%s", dezenas[dezena]);
            }
        }
       
        if(unidade > 0 ){
            if(dezena > 1 || centena > 0 || milhar > 0){
                printf(" e ");
                printf("%s", unidades[unidade]);
            }
        }
   
    return 0;
}


*/
/*
#include <stdio.h>
//Questão 13
void BubbleSort(int vetor[], int tamanho){
  for(int i = 0; i< tamanho - 1; i++){
    for(int j = 0; j < tamanho - i - 1; j++){
      if(vetor[j] > vetor[ j + 1]){
        int temp = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = temp;
      }
    }
  }
}


int main(void){
  int vet1[10];
  int vet2[10];
  int vet3[10];
  int vetfinal[30];
 
  for(int i = 0; i < 10; i++){
    scanf("%d %d %d", &vet1[i], &vet2[i], &vet3[i]);
  }
 
  BubbleSort(vet1, 10);
  BubbleSort(vet2, 10);
  BubbleSort(vet3, 10);
 
  for(int i = 0; i < 10; i++){
    vetfinal[i] = vet1[i];
    vetfinal[i + 10] = vet2[i];
    vetfinal[i + 20] = vet3[i];
  }
 
  BubbleSort(vetfinal, 30);
 
  for(int i = 0; i < 30; i++){
    printf("%d ", vetfinal[i]);
  }
  printf("\n");
 
  return 0;
}


*/
/*
//Questão 14
#include <stdio.h>
#include <unistd.h> // Para usar sleep()


int main(void){
  int horas = 0;
  int minutos = 0;
  int segundos = 0;
 
  while(1){
   
    printf("\r%02d:%02d:%02d", horas, minutos, segundos);
    fflush(stdout); // Força a atualização da saída no terminal

    sleep(1);

    segundos++;
    if(segundos == 60){
      segundos = 0;
      minutos++;
      if(minutos == 60){
        minutos = 0;
        horas++;
        if(horas == 24){
          horas = 0;
        }
      }
    }
  }
 
  return 0;
}
*/


/*
int main(void){
//questão15
    int ano = 0;
    char sexo;
    int local;
    int totalMenores21 = 0;
    int totalMotoristas = 0;
    int mulheresCapital = 0;
    int idososInterior = 0;
    int existeMulherIdosa = 0;

    for(int i = 0; i < 80; i++){
        scanf("%d %d %c", &ano, &local, &sexo);
    
        int idade = 2024 - ano;

        if(idade < 21){
            totalMenores21++;
        }
        if(sexo == 'F' && local ==0){
            mulheresCapital++;
        }
        if(local == 1 && idade > 60){
            idososInterior++;
        }
        if(sexo == 'F' && idade > 60){
            existeMulherIdosa++;
        }
    }
    float porcentagem = (totalMenores21*100)/totalMotoristas;

    printf("Porcentagem de motoristas com menos de 21 anos: %.2f\n", porcentagem);
    printf("Quantidade de mulheres da capital: %d\n", mulheresCapital);
    printf("Quantidade de motoristas do interior com mais de 60 anos: %d\n", idososInterior);
    printf("Existe mulher com mais de 60 anos %s\n", existeMulherIdosa);

    return 0;
}

*/

/*
int main(void){
//QUestão 20
    int colunas = 0;
    int linhas = 0;
    
    int matrizA[10][10];
    int matrizB[10][10];
    int matrizC[10][10];

    scanf("%d %d", &linhas, &colunas);
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j< colunas; j++){
            scanf("%d", &matrizA[i][j]);
        }
    }

    for(int i = 0; i< linhas;i++){
        for(int j = 0; j < colunas; j++){
            scanf("%d", &matrizB[i][j]);
        }
    }

    for(int i = 0; i < linhas; i++){
        for(int j = 0;j< colunas; j++){
            matrizC[i][j] = matrizA[i][j] + matrizB[i][j];
        }
    }
    
    for(int i = 0; i < linhas; i++){
        for(int j = 0;j< colunas; j++){
            printf("%d ", matrizC[i][j]);
        }
        printf("\n");
    }

    return 0;
}
*/

/*
int main(void){
//QUestão 19
    int matriz[5][5];
    int soma1 = 0;
    int soma2 = 0;
    int soma3 = 0;
    int soma4 = 0;
    int soma5 = 0;

    for(int i = 0; i<5; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &matriz[i][j]);
        }
    }

    for(int i = 0; i < 5; i++){
        soma1+= matriz[4][i];
    }
    
    for(int j = 0; j < 5; j++){
        soma2 += matriz[j][2];
    }

    for(int i = 0;i<5; i++){
        soma3 += matriz[i][i];
    }

    for(int i = 0; i< 5; i++){
        soma4 += matriz[i][4-i];
    }
    
    for(int i = 0; i< 5; i++){
        for(int j = 0; j<5;j++){
            soma5 += matriz[i][j];
        }
    }
    return 0;
}


/*

int main(void){
//Questão 21
    int n = 0;
    int valores[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *romanos[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    scanf("%d", &n);

    for(int i = 0; i<13; i++){
        while(n >= valores[i]){
            printf("%s", romanos[i]);
            n -= valores[i];
        }
    }
    printf("\n");
    return 0;
}

Questão 22:
#include <stdio.h> 
#include <string.h>

int vogal(char cadeia [80]);

int main(void){
    char cadeia[80];
    int numvogal;
    int total;

    fgets(cadeia, 80, stdin);
    
    numvogal = vogal(cadeia);

    total = strlen(cadeia);

    float porcento = (float)numvogal/total;

    printf("%.2f %d", porcento, numvogal);

    return 0;
}

int vogal (char cadeia[80]){
    int count = 0;
    for(int i = 0; cadeia[i] != '\0'; i++){
        char c = cadeia[i];
        if(c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || 
            c == 'o' || c == 'O' || c == 'u' || c == 'U'){
                count++;
            }
    }
    return count;
}

questão 23:

#include <stdio.h>
int main(void){
    int num = 0;
    int count = 0;
    scanf("%d", &num);

    for(int i = 1; i < num; i++){
        if(i * (i + 1) * (i + 2) == num){
            count++;
        }
    }  

    if(count == 0){
        printf("nao e");
    }

    if(count == 1){
        printf("triangular");
    }
    
    return 0;
}


questão 24: 
#include <stdio.h>
#include <string.h>


int main(void){

    int idade[80];
    int i = 0, count = 0, total = 0, adultos = 0;
    float media = 0, porcentagem = 0;

    while(1){
        scanf("%d", &idade[i]);

        if(idade[i] == -1){
            count++;
            break;
        }

        total += idade[i];
        count++;

        if(idade[i] >= 21 && idade[i] <= 65){
            adultos++;
        }

        i++;
    }
    
    media = (float)total/count;
    porcentagem = (float)adultos/count*100;

    printf("%.2f %.2f", media, porcentagem);
    
    return 0;
}

//Questão 18:
int Fibonacci(int n){
  if(n == 0){
    return 0;
  }
 
  if(n == 1){
    return 1;
  }
  return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(void){
    int num = 0;
    scanf("%d", &num);
    Fibonacci(num);
    return 0;
}