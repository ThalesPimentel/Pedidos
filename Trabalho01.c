#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Dados
{
        char CNPJ[20];
        char Nome[100];
        char Rsocial[100];
        char Endereco[150]; //Rua, cidade, CEP...
        char Inscricao[20];
        char Telefone[20];
        char Email[100];
        char Contato[100];
}Clientes;

typedef struct Produto
{
    int NumeroPedido;
    char CNPJ[20];
    char DataPedido[20];
    char DataEntrega[20];
    int Dias;
    char Descricao[6][21];
    int Quantidade[6];
    double total;
    char Pagamento[20];
}Pedidos;

void inserirCliente(Clientes clientes[], int *n) {
    if (*n >= 10) {
        printf("Limite de clientes atingido.\n");
        return;
    }

    printf("Informe os dados do cliente:\n");
    scanf(" %19[^\n]", clientes[*n].CNPJ);//*n passado por referencia, acessa a posição atual
    scanf(" %99[^\n]", clientes[*n].Nome);
    scanf(" %99[^\n]", clientes[*n].Rsocial);
    scanf(" %149[^\n]", clientes[*n].Endereco);
    scanf(" %19[^\n]", clientes[*n].Inscricao);
    scanf(" %19[^\n]", clientes[*n].Telefone);
    scanf(" %99[^\n]", clientes[*n].Email);
    scanf(" %99[^\n]", clientes[*n].Contato);

    FILE* Arq1 = fopen("Cliente.dat", "ab");
    if (Arq1 == NULL) {
        printf("Erro ao gravar os dados\n");
        return;
    }

    fwrite(&clientes[*n], sizeof(Clientes), 1, Arq1);
    fclose(Arq1);
    *n = *n + 1; //Depois de gravar o cliente, incrementa o contador

    printf("Dados gravados com sucesso.\n");
}

void alterarCliente(Clientes clientes[], int n) {
    char cnpj[20];
    int i, achou = 0;

    printf("Digite o CNPJ do cliente que deseja alterar:\n");
    scanf(" %19[^\n]", cnpj);

    for (i = 0; i < n; i++) {
        if (strcmp(clientes[i].CNPJ, cnpj) == 0) {
            achou = 1;
            printf("Cliente encontrado. Digite os novos dados:\n");

            printf("Nome: ");
            scanf(" %99[^\n]", clientes[i].Nome);

            printf("Razao Social: ");
            scanf(" %99[^\n]", clientes[i].Rsocial);

            printf("Endereco: ");
            scanf(" %149[^\n]", clientes[i].Endereco);

            printf("Inscricao Estadual: ");
            scanf(" %19[^\n]", clientes[i].Inscricao);

            printf("Telefone: ");
            scanf(" %19[^\n]", clientes[i].Telefone);

            printf("Email: ");
            scanf(" %99[^\n]", clientes[i].Email);

            printf("Contato: ");
            scanf(" %99[^\n]", clientes[i].Contato);

            // Atualizar o arquivo
            FILE* Arq1 = fopen("Cliente.dat", "wb");
            if (Arq1 == NULL) {
                printf("Erro ao reabrir o arquivo para escrita.\n");
                return;
            }

            fwrite(clientes, sizeof(Clientes), n, Arq1);
            fclose(Arq1);

            printf("Cliente alterado com sucesso.\n");
            break;
        }
    }

    if (!achou) {
        printf("Cliente com CNPJ %s nao encontrado.\n", cnpj);
    }
}

void excluirCliente(Clientes clientes[], int *n) {
    char cnpj[20];
    int i, j, achou = 0;

    printf("Digite o CNPJ do cliente que deseja excluir:\n");
    scanf(" %19[^\n]", cnpj);

    for (i = 0; i < *n; i++) {
        if (strcmp(clientes[i].CNPJ, cnpj) == 0) {
            achou = 1;

            for (j = i; j < *n - 1; j++) {
                clientes[j] = clientes[j + 1];
            }

            (*n)--; // Decrementa o contador de clientes

            // Atualiza o arquivo
            FILE* Arq1 = fopen("Cliente.dat", "wb");
            if (Arq1 == NULL) {
                printf("Erro ao reabrir o arquivo para atualizar.\n");
                return;
            }

            fwrite(clientes, sizeof(Clientes), *n, Arq1);
            fclose(Arq1);

            printf("Cliente removido com sucesso.\n");
            break;
        }
    }

    if (!achou) {
        printf("Cliente com CNPJ %s nao encontrado.\n", cnpj);
    }
}

void consultarCliente(Clientes clientes[], int n) {
    char cnpj[20];
    int i, achou = 0;

    printf("Digite o CNPJ do cliente que deseja consultar:\n");
    scanf(" %19[^\n]", cnpj);

    for (i = 0; i < n; i++) {
        if (strcmp(clientes[i].CNPJ, cnpj) == 0) {
            achou = 1;
            printf("\n--- Dados do Cliente ---\n");
            printf("CNPJ: %s\n", clientes[i].CNPJ);
            printf("Nome: %s\n", clientes[i].Nome);
            printf("Razao Social: %s\n", clientes[i].Rsocial);
            printf("Endereco: %s\n", clientes[i].Endereco);
            printf("Inscricao Estadual: %s\n", clientes[i].Inscricao);
            printf("Telefone: %s\n", clientes[i].Telefone);
            printf("Email: %s\n", clientes[i].Email);
            printf("Contato: %s\n", clientes[i].Contato);
            break;
        }
    }

    if (!achou) {
        printf("Cliente com CNPJ %s nao encontrado.\n", cnpj);
    }
}


void InserirPedido(Pedidos pedidos[], int *n) {
    if (*n >= 10) {
        printf("Limite de pedidos atingido.\n");
        return;
    }

    printf("Informe os dados do pedido:\n");
    scanf("%d", &pedidos[*n].NumeroPedido);
    scanf(" %19[^\n]", pedidos[*n].CNPJ);
    scanf(" %19[^\n]", pedidos[*n].DataPedido);
    scanf(" %19[^\n]", pedidos[*n].DataEntrega);
    scanf("%d", &pedidos[*n].Dias);

    for (int i = 0; i < 6; i++) {
        printf("Descricao do produto %d: ", i + 1);
        scanf(" %20[^\n]", pedidos[*n].Descricao[i]);
        printf("Quantidade do produto %d: ", i + 1);
        scanf("%d", &pedidos[*n].Quantidade[i]);
    }

    printf("Total: ");
    scanf("%lf", &pedidos[*n].total);
    printf("Forma de pagamento: ");
    scanf(" %19[^\n]", pedidos[*n].Pagamento);

    FILE* Arq1 = fopen("Pedido.dat", "ab");
    if (Arq1 == NULL) {
        printf("Erro ao gravar os dados\n");
        return;
    }

    fwrite(&pedidos[*n], sizeof(Pedidos), 1, Arq1);
    fclose(Arq1);
    *n = *n + 1;

    printf("Dados gravados com sucesso.\n");
}

void AlterarPedido(Pedidos pedidos[], int n) {
    int numeroPedido;
    int i, achou = 0;

    printf("Digite o numero do pedido que deseja alterar:\n");
    scanf("%d", &numeroPedido);

    for (i = 0; i < n; i++) {
        if (pedidos[i].NumeroPedido == numeroPedido) {
            achou = 1;
            printf("Pedido encontrado. Digite os novos dados:\n");

            printf("CNPJ: ");
            scanf(" %19[^\n]", pedidos[i].CNPJ);

            printf("Data do pedido: ");
            scanf(" %19[^\n]", pedidos[i].DataPedido);

            printf("Data de entrega: ");
            scanf(" %19[^\n]", pedidos[i].DataEntrega);

            printf("Dias: ");
            scanf("%d", &pedidos[i].Dias);

            for (int j = 0; j < 6; j++) {
                printf("Descricao do produto %d: ", j + 1);
                scanf(" %20[^\n]", pedidos[i].Descricao[j]);
                printf("Quantidade do produto %d: ", j + 1);
                scanf("%d", &pedidos[i].Quantidade[j]);
            }

            printf("Total: ");
            scanf("%lf", &pedidos[i].total);
            printf("Forma de pagamento: ");
            scanf(" %19[^\n]", pedidos[i].Pagamento);

            // Atualizar o arquivo
            FILE* Arq1 = fopen("Pedido.dat", "wb");
            if (Arq1 == NULL) {
                printf("Erro ao reabrir o arquivo para escrita.\n");
                return;
            }

            fwrite(pedidos, sizeof(Pedidos), n, Arq1);
            fclose(Arq1);

            printf("Pedido alterado com sucesso.\n");
            break;
        }
    }

    if (!achou) {
        printf("Pedido com numero %d nao encontrado.\n", numeroPedido);
    }
}

void ExcluirPedido(Pedidos pedidos[], int *n) {
    int numeroPedido;
    int i, j, achou = 0;

    printf("Digite o numero do pedido que deseja excluir:\n");
    scanf("%d", &numeroPedido);

    for (i = 0; i < *n; i++) {
        if (pedidos[i].NumeroPedido == numeroPedido) {
            achou = 1;

            for (j = i; j < *n - 1; j++) {
                pedidos[j] = pedidos[j + 1];
            }

            (*n)--;

            // Atualiza o arquivo
            FILE* Arq1 = fopen("Pedido.dat", "wb");
            if (Arq1 == NULL) {
                printf("Erro ao reabrir o arquivo para atualizar.\n");
                return;
            }

            fwrite(pedidos, sizeof(Pedidos), *n, Arq1);
            fclose(Arq1);

            printf("Pedido removido com sucesso.\n");
            break;
        }
    }

    if (!achou) {
        printf("Pedido com numero %d nao encontrado.\n", numeroPedido);
    }
}


int compararDatas(const char *data1, const char *data2) {
    int dia1, mes1, ano1;
    int dia2, mes2, ano2;
    
    sscanf(data1, "%d/%d/%d", &dia1, &mes1, &ano1);
    sscanf(data2, "%d/%d/%d", &dia2, &mes2, &ano2);
    
    if (ano1 != ano2) return ano1 - ano2;
    if (mes1 != mes2) return mes1 - mes2;
    return dia1 - dia2;
}

void consultarPedidosPorCliente(Pedidos pedidos[], int m, Clientes clientes[], int n) {
    char cnpj[20];
    int achouCliente = 0;
    int achouPedido = 0;
    
    printf("Digite o CNPJ do cliente: ");
    scanf(" %19[^\n]", cnpj);
    
    for (int i = 0; i < n; i++) {
        if (strcmp(clientes[i].CNPJ, cnpj) == 0) {
            achouCliente = 1;
            break;
        }
    }
    
    if (!achouCliente) {
        printf("Cliente não encontrado.\n");
        return;
    }
    
    printf("\nPedidos do cliente %s:\n", cnpj);
    for (int i = 0; i < m; i++) {
        if (strcmp(pedidos[i].CNPJ, cnpj) == 0) {
            achouPedido = 1;
            printf("Pedido %d - Data: %s - Total: R$ %.2f\n", 
                   pedidos[i].NumeroPedido, pedidos[i].DataPedido, pedidos[i].total);
        }
    }
    
    if (!achouPedido) {
        printf("Nenhum pedido encontrado para este cliente.\n");
    }
}

void consultarPedidosPorIntervalo(Pedidos pedidos[], int m) {
    char dataInicio[20], dataFim[20];
    
    printf("Digite a data inicial (DD/MM/AAAA): ");
    scanf(" %19[^\n]", dataInicio);
    printf("Digite a data final (DD/MM/AAAA): ");
    scanf(" %19[^\n]", dataFim);
    
    printf("\nPedidos entre %s e %s:\n", dataInicio, dataFim);
    int achou = 0;
    
    for (int i = 0; i < m; i++) {
        if (compararDatas(pedidos[i].DataPedido, dataInicio) >= 0 && 
            compararDatas(pedidos[i].DataPedido, dataFim) <= 0) {
            achou = 1;
            printf("Pedido %d - Cliente: %s - Data: %s - Total: R$ %.2f\n", 
                   pedidos[i].NumeroPedido, pedidos[i].CNPJ, 
                   pedidos[i].DataPedido, pedidos[i].total);
        }
    }
    
    if (!achou) {
        printf("Nenhum pedido encontrado neste intervalo.\n");
    }
}

void consultarPedidosEntregues(Pedidos pedidos[], int m) {
    char dataMinima[20];
    
    printf("Digite a data mínima de entrega (DD/MM/AAAA): ");
    scanf(" %19[^\n]", dataMinima);
    
    printf("\nPedidos entregues a partir de %s:\n", dataMinima);
    int achou = 0;
    
    for (int i = 0; i < m; i++) {
        if (strlen(pedidos[i].DataEntrega) > 1 && 
            compararDatas(pedidos[i].DataEntrega, dataMinima) >= 0) {
            achou = 1;
            printf("Pedido %d - Cliente: %s - Entrega: %s - Total: R$ %.2f\n", 
                   pedidos[i].NumeroPedido, pedidos[i].CNPJ, 
                   pedidos[i].DataEntrega, pedidos[i].total);
        }
    }
    
    if (!achou) {
        printf("Nenhum pedido encontrado.\n");
    }
}

int compararDataAtualComPrazo(const char *dataPedido, int diasPrazo) {
    struct tm tmPedido = {0};
    int dia, mes, ano;

    if (sscanf(dataPedido, "%d/%d/%d", &dia, &mes, &ano) != 3) {
        fprintf(stderr, "Erro: formato de data inválido: %s\n", dataPedido);
        return -1;
    }

    tmPedido.tm_mday = dia;
    tmPedido.tm_mon = mes - 1;
    tmPedido.tm_year = ano - 1900;

    time_t tPedido = mktime(&tmPedido);
    if (tPedido == -1) {
        fprintf(stderr, "Erro ao converter data para time_t\n");
        return -1;
    }

    tPedido += diasPrazo * 24 * 60 * 60;
    time_t agora = time(NULL);

    return agora <= tPedido;
}

void consultarPedidosEmAberto(Pedidos pedidos[], int m) {
    printf("\nPedidos em Aberto:\n");
    int achou = 0;
    
    for (int i = 0; i < m; i++) {
        if (strlen(pedidos[i].DataEntrega) <= 1) {
            achou = 1;
            printf("Pedido %d - Cliente: %s - Data: %s - ", 
                   pedidos[i].NumeroPedido, pedidos[i].CNPJ, pedidos[i].DataPedido);
            
            if (compararDataAtualComPrazo(pedidos[i].DataPedido, pedidos[i].Dias)) {
                printf("DENTRO DO PRAZO\n");
            } else {
                printf("FORA DO PRAZO\n");
            }
        }
    }
    
    if (!achou) {
        printf("Nenhum pedido em aberto encontrado.\n");
    }
}

void consultarMediaMensal(Pedidos pedidos[], int m, Clientes clientes[], int n) {
    char cnpj[20];
    int achou = 0;
    double total = 0;
    int meses[12] = {0};
    double valores[12] = {0};
    
    printf("Digite o CNPJ do cliente: ");
    scanf(" %19[^\n]", cnpj);
    
    // Verifica se o cliente existe
    for (int i = 0; i < n; i++) {
        if (strcmp(clientes[i].CNPJ, cnpj) == 0) {
            achou = 1;
            break;
        }
    }
    
    if (!achou) {
        printf("Cliente não encontrado.\n");
        return;
    }
    
    // Calcula totais por mês
    for (int i = 0; i < m; i++) {
        if (strcmp(pedidos[i].CNPJ, cnpj) == 0) {
            int mes;
            sscanf(pedidos[i].DataPedido, "%*d/%d/%*d", &mes);
            valores[mes-1] += pedidos[i].total;
            meses[mes-1]++;
        }
    }
    
    printf("\nMédia mensal para o cliente %s:\n", cnpj);
    for (int i = 0; i < 12; i++) {
        if (meses[i] > 0) {
            printf("Mês %d: R$ %.2f (baseado em %d pedidos)\n", 
                   i+1, valores[i]/meses[i], meses[i]);
        }
    }
}


void ConsultarPedido(Pedidos pedidos[], int m) {
    int numero;
    printf("Digite o numero do pedido: ");
    scanf("%d", &numero);

    for (int i = 0; i < m; i++) {
        if (pedidos[i].NumeroPedido == numero) {
            printf("\n--- Detalhes do Pedido ---\n");
            printf("Numero: %d\n", pedidos[i].NumeroPedido);
            printf("CNPJ: %s\n", pedidos[i].CNPJ);
            printf("Data do Pedido: %s\n", pedidos[i].DataPedido);
            printf("Data de Entrega: %s\n", pedidos[i].DataEntrega);
            printf("Dias para entrega: %d\n", pedidos[i].Dias);
            printf("Produtos:\n");
            for (int j = 0; j < 6; j++) {
                printf("  - %s x%d\n", pedidos[i].Descricao[j], pedidos[i].Quantidade[j]);
            }
            printf("Total: R$ %.2f\n", pedidos[i].total);
            printf("Pagamento: %s\n", pedidos[i].Pagamento);
            return;
        }
    }

    printf("Pedido nao encontrado.\n");
}

void ConsultarPedidos(Pedidos pedidos[], int m, Clientes clientes[], int n) {
    int opcao;
    
    printf("\nTipo de consulta:\n");
    printf("1 - Por número de pedido\n");
    printf("2 - Todos os pedidos de um cliente\n");
    printf("3 - Pedidos em um intervalo de datas\n");
    printf("4 - Pedidos entregues a partir de uma data\n");
    printf("5 - Pedidos em aberto\n");
    printf("6 - Média mensal por cliente\n");
    printf("Opção: ");
    scanf("%d", &opcao);
    
    switch(opcao) {
        case 1:
            ConsultarPedido(pedidos, m);
            break;
        case 2:
            consultarPedidosPorCliente(pedidos, m, clientes, n);
            break;
        case 3:
            consultarPedidosPorIntervalo(pedidos, m);
            break;
        case 4:
            consultarPedidosEntregues(pedidos, m);
            break;
        case 5:
            consultarPedidosEmAberto(pedidos, m);
            break;
        case 6:
            consultarMediaMensal(pedidos, m, clientes, n);
            break;
        default:
            printf("Opção inválida.\n");
    }
}

int main(void){

    Clientes clientes[10];
    int n = 0;
    int opcao;

    FILE *Arq1 = fopen("Cliente.dat", "rb");

    if (Arq1 != NULL) {
        while (fread(&clientes[n], sizeof(Clientes), 1, Arq1) == 1 && n < 10) {
            n++;
        }
        fclose(Arq1);
    }

    Pedidos pedidos[20];
    int m = 0;
    FILE *Arq2 = fopen("Pedido.dat", "rb");
    if (Arq2 != NULL) {
        while (fread(&pedidos[m], sizeof(Pedidos), 1, Arq2) == 1 && m < 20) {
            m++;
        }
        fclose(Arq2);
    }

    do {
        printf("\n==== MENU PRINCIPAL ====\n");
        printf("1 - Inserir Cliente\n");
        printf("2 - Alterar Cliente\n");
        printf("3 - Excluir Cliente\n");
        printf("4 - Consultar Cliente\n");
        printf("5 - Inserir Pedido\n");
        printf("6 - Alterar Pedido\n");
        printf("7 - Excluir Pedido\n");
        printf("8 - Consultar Pedido\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                inserirCliente(clientes, &n);
                break;
            case 2:
                alterarCliente(clientes, n);
                break;
            case 3:
                excluirCliente(clientes, &n);
                break;
            case 4:
                consultarCliente(clientes, n);
                break;
            case 5:
                InserirPedido(pedidos, &m);
                break;
            case 6:
                AlterarPedido(pedidos, m);
                break;
            case 7:
                ExcluirPedido(pedidos, &m);
                break;
            case 8:
                ConsultarPedidos(pedidos, m, clientes, n);
                break;
            case 0:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }

    } while (opcao != 0);

    return 0;
}