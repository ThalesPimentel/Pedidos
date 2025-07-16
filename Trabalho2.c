#include <stdio.h>
#include <stdlib.h>

typedef struct Pedidos
{
    int Codigo;
    int Quantidade;
    struct Pedidos *ProximoPedido;
} Pedido;

typedef struct Mesa
{
    int Numero;
    int CodigoGarcom;
    float TotalPedidos;
    Pedido *listaPedidos;
    struct Mesa *ProximaMesa;
    struct Mesa *MesaAnterior;

} Mesa;
typedef struct Cardapio
{
    int CodigoCardapio;
    float PrecoCardapio;
    char Objeto[80];
    char Tipo;
} Cardapio;

typedef struct Garcom
{
    char NomeGarcom[80];
    int CodigoGarcom;
} Garcom;

void FecharMesa(Mesa **InicioMesas, FILE *Arquivo1, FILE *Arquivo2)
{
    int NumeroFechada = 0;
    printf("Digite o numero da mesa a ser fechada: \n");
    scanf("%d", &NumeroFechada);

    Mesa *MesaAtual = *InicioMesas;
    while (MesaAtual != NULL && MesaAtual->Numero != NumeroFechada)
    {
        MesaAtual = MesaAtual->ProximaMesa;
    }
    if (MesaAtual == NULL)
    {
        printf("Erro ao Fechar a mesa");
        return;
    }
    
    rewind(Arquivo2);
    Garcom Guerreio;
    int encontrado = 0;

    while (fread(&Guerreio, sizeof(Garcom), 1, Arquivo2))
    {
        if (Guerreio.CodigoGarcom == MesaAtual->CodigoGarcom)
        {
            printf("Garcom responsavel: %s", Guerreio.NomeGarcom);
            encontrado = 1;
            break;
        }
    }
    if (encontrado == 0)
    {
        printf("Garçom não encontrado.\n");
    }

    rewind(Arquivo1);
    Cardapio Item;
    float total = 0;
    Pedido *PedidoAtual = MesaAtual->listaPedidos;

    printf("Itens Consumidos: \n");
    while (PedidoAtual != NULL)
    {
        rewind(Arquivo1);
        int aux = 0;
        while (fread(&Item, sizeof(Cardapio), 1, Arquivo1))
        {
            if (Item.CodigoCardapio == PedidoAtual->Codigo)
            {
                float subtotal = Item.PrecoCardapio * PedidoAtual->Quantidade;
                printf("Itens: %s, Quantidade: %d, Subtotal: %f\n", Item.Objeto, PedidoAtual->Quantidade, subtotal);
                total += subtotal;
                aux = 1;
                break;
            }
        }
        if(aux == 0){
            printf("Item não encontrado no cardapio");
        }
        PedidoAtual = PedidoAtual->ProximoPedido;
    }
    printf("Total: %f", total);


    PedidoAtual = MesaAtual->listaPedidos;
    while (PedidoAtual != NULL) {
        Pedido *PedidoRemovido = PedidoAtual;
        PedidoAtual = PedidoAtual->ProximoPedido;
        free(PedidoRemovido);
    }

    if (MesaAtual->MesaAnterior != NULL){
        MesaAtual->MesaAnterior->ProximaMesa = MesaAtual->ProximaMesa;
    }
    else{
        *InicioMesas = MesaAtual->ProximaMesa;
    }

    if (MesaAtual->ProximaMesa != NULL){
        MesaAtual->ProximaMesa->MesaAnterior = MesaAtual->MesaAnterior;
    }

    free(MesaAtual);
    printf("Mesa fechada com sucesso!\n");
}

void RemoverPedido(Mesa **InicioMesas)
{
    int aux = 0;
    printf("Digite o codigo da mesa que deseja excluir: ");
    scanf("%d", &aux);
    Mesa *AtualMesa = *InicioMesas;

    while (AtualMesa != NULL && AtualMesa->Numero != aux)
    {
        AtualMesa = AtualMesa->ProximaMesa;
    }

    if (AtualMesa == NULL)
    {
        printf("Mesa não encontrada\n");
        return;
    }

    if (AtualMesa->listaPedidos == NULL)
    {
        printf("Não há pedidos nesta mesa.\n");
        return;
    }
    int CodigoRemover = 0;
    printf("Digite o código do pedido que deseja remover: ");
    scanf("%d", &CodigoRemover);

    Pedido *PedidoAtual = AtualMesa->listaPedidos;
    Pedido *PedidoAnterior = NULL;
    while (PedidoAtual != NULL && PedidoAtual->Codigo != CodigoRemover)
    {
        PedidoAnterior = PedidoAtual;
        PedidoAtual = PedidoAtual->ProximoPedido;
    }
    if (PedidoAtual == NULL)
    {
        printf("Pedido não encontrado\n");
        return;
    }

    FILE *Arquivo = fopen("Cardapio.dat", "rb");
    if (Arquivo == NULL)
    {
        printf("Erro ao Abrir o aquivo no remover\n");
        return;
    }
    int encontrado = 0;
    Cardapio Item;
    while (fread(&Item, sizeof(Cardapio), 1, Arquivo))
    {
        if (Item.CodigoCardapio == PedidoAtual->Codigo)
        {
            encontrado = 1;
            AtualMesa->TotalPedidos -= (Item.PrecoCardapio) * (PedidoAtual->Quantidade); // Multiplicação, não é ponteiro
            if (AtualMesa->TotalPedidos < 0)
            {
                AtualMesa->TotalPedidos = 0;
            }
            break;
        }
    }
    if (!encontrado)
    {
        printf("Item do cardápio não encontrado no arquivo.\n");
    }

    fclose(Arquivo);

    if (PedidoAnterior == NULL)
    {
        AtualMesa->listaPedidos = PedidoAtual->ProximoPedido;
    }
    else
    {
        PedidoAnterior->ProximoPedido = PedidoAtual->ProximoPedido;
    }

    free(PedidoAtual);
    printf("Pedido removido com sucesso!\n");
}

void ConsultarMesas(Mesa *InicioMesa)
{
    while (InicioMesa != NULL)
    {
        printf("Número da Mesa: %d\n", InicioMesa->Numero);
        printf("Código do Garçom: %d\n", InicioMesa->CodigoGarcom);
        printf("Total do Pedido: %f\n", InicioMesa->TotalPedidos);

        Pedido *pedidoAtual = InicioMesa->listaPedidos;
        if (pedidoAtual == NULL)
        {
            printf("Nenhum pedido nesta mesa\n");
        }
        else
        {
            printf("Pedidos:\n");
            while (pedidoAtual != NULL)
            {
                printf("Código do Pedido: %d, Quantidade: %d\n", pedidoAtual->Codigo, pedidoAtual->Quantidade);
                pedidoAtual = pedidoAtual->ProximoPedido;
            }
        }

        InicioMesa = InicioMesa->ProximaMesa;
    }
}

void InserirPedido(Mesa **InicioMesa, FILE *Arquivo1)
{
    int NumeroMesa = 0;
    printf("Digite o numero da mesa: \n");
    scanf("%d", &NumeroMesa);

    Mesa *MesaAtual = *InicioMesa;

    while (MesaAtual != NULL && MesaAtual->Numero != NumeroMesa)
    {
        MesaAtual = MesaAtual->ProximaMesa;
    }
    if (MesaAtual == NULL)
    {
        printf("Mesa não encontrada\n");
        return;
    }

    int codigoPedido, quantidade;
    float preco = 0;

    printf("Digite o código do pedido: ");
    scanf("%d", &codigoPedido);
    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    Cardapio itemCardapio;
    int achou = 0;

    rewind(Arquivo1);
    while (fread(&itemCardapio, sizeof(Cardapio), 1, Arquivo1) == 1)
    {
        if (itemCardapio.CodigoCardapio == codigoPedido)
        {
            preco = itemCardapio.PrecoCardapio;
            achou = 1;
            break;
        }
    }

    if (!achou)
    {
        printf("Item do cardápio não encontrado.\n");
        return;
    }

    Pedido *novoPedido = malloc(sizeof(Pedido));
    if (novoPedido == NULL)
    {
        printf("Erro ao alocar memória para o pedido.\n");
        return;
    }

    novoPedido->Codigo = codigoPedido;
    novoPedido->Quantidade = quantidade;

    novoPedido->ProximoPedido = MesaAtual->listaPedidos;
    MesaAtual->listaPedidos = novoPedido;

    MesaAtual->TotalPedidos += quantidade * preco;

    printf("Pedido inserido, total atualizado: %f\n", MesaAtual->TotalPedidos);
}

void InserirMesa(Mesa **InicioMesas)
{
    Mesa *NovaMesa = malloc(sizeof(Mesa));
    if (NovaMesa == NULL)
    {
        printf("Erro ao alocar a Mesa.\n");
        return;
    }

    printf("Digite o Numero da mesa: ");
    scanf("%d", &NovaMesa->Numero);
    printf("Digite o Codigo do garcom: ");
    scanf("%d", &NovaMesa->CodigoGarcom);

    NovaMesa->TotalPedidos = 0;
    NovaMesa->listaPedidos = NULL;

    NovaMesa->ProximaMesa = *InicioMesas;
    NovaMesa->MesaAnterior = NULL;

    Mesa *AntigaMesa = *InicioMesas;

    if (AntigaMesa != NULL)
    {
        AntigaMesa->MesaAnterior = NovaMesa;
    }
    *InicioMesas = NovaMesa;

    printf("Mesa Inserida com sucesso\n");
}

void CadastrarItemCardapio(FILE *arquivo1)
{
    Cardapio Item;

    printf("Digite o Codigo do ITEM: \n");
    scanf("%d", &Item.CodigoCardapio);
    getchar();

    printf("Digite o nome do ITEM: \n");
    fgets(Item.Objeto, sizeof(Item.Objeto), stdin);

    printf("Digite o tipo: P para prato ou B para Bebida: \n");
    scanf("%c", &Item.Tipo);

    printf("Digte o preco do ITEM: \n");
    scanf("%f", &Item.PrecoCardapio);

    fwrite(&Item, sizeof(Cardapio), 1, arquivo1);
    printf("Dados salvos com sucesso! \n");
}

void CadastrarGarcom(FILE *arquivo2)
{
    Garcom Guerreiro;

    printf("DIgite o codigo para o Garcom: \n");
    scanf("%d", &Guerreiro.CodigoGarcom);
    getchar();

    printf("Digite o nome do Garcom: \n");
    fgets(Guerreiro.NomeGarcom, sizeof(Guerreiro.NomeGarcom), stdin);

    fwrite(&Guerreiro, sizeof(Garcom), 1, arquivo2);
    printf("Garcom salvo com sucesso! \n");
}

void ConsultarCardapio(FILE *arquivo1)
{
    Cardapio Item;
    while (fread(&Item, sizeof(Cardapio), 1, arquivo1) == 1)
    {
        printf("Codigo:: %d\n", Item.CodigoCardapio);
        printf("Preco: %f\n", Item.PrecoCardapio);
        printf("Item: %s", Item.Objeto);
        printf("Tipo: %c\n", Item.Tipo);
    }
}

void ConsultarGarcom(FILE *arquivo2)
{
    Garcom Guerreiro;
    while (fread(&Guerreiro, sizeof(Garcom), 1, arquivo2) == 1)
    {
        printf("Nome: %s", Guerreiro.NomeGarcom);
        printf("Codigo: %d\n", Guerreiro.CodigoGarcom);
    }
}

void ExcluirItemCardapio(FILE *arquivo1)
{
    FILE *temp = fopen("Temp.dat", "wb");
    if (temp == NULL)
    {
        printf("Erro ao excluir o Item");
        return;
    }

    Cardapio Item;
    int CodigoExcluir = 0;
    printf("Digite o codigo do item a ser excluido: \n");
    scanf("%d", &CodigoExcluir);
    int aux = 0;

    while (fread(&Item, sizeof(Cardapio), 1, arquivo1) == 1)
    {
        if (Item.CodigoCardapio != CodigoExcluir)
        {
            fwrite(&Item, sizeof(Cardapio), 1, temp);
        }
        else
        {
            aux = 1;
        }
    }

    fclose(temp);
    if (aux == 1)
    {
        remove("Cardapio.dat");
        rename("Temp.dat", "Cardapio.dat");
        printf("Item removido com sucesso\n");
    }
    else
    {
        remove("Temp.dat");
        printf("Item não encontrado\n");
    }
}

void ExcluirGarcom(FILE *arquivo2)
{
    FILE *temp = fopen("Temp.dat", "wb");
    if (temp == NULL)
    {
        printf("Erro ao excluir o Garçom");
        return;
    }
    Garcom Guerreiro;
    int CodigoExcluir = 0;
    int aux = 0;
    printf("Digite o codigo do garçom que deseja excluir: \n");
    scanf("%d", &CodigoExcluir);

    while (fread(&Guerreiro, sizeof(Garcom), 1, arquivo2) == 1)
    {
        if (Guerreiro.CodigoGarcom != CodigoExcluir)
        {
            fwrite(&Guerreiro, sizeof(Garcom), 1, temp);
        }
        else
        {
            aux = 1;
        }
    }

    fclose(temp);
    if (aux == 1)
    {
        remove("Garcom.dat");
        rename("Temp.dat", "Garcom.dat");
        printf("Item excluido com sucesso\n");
    }
    else
    {
        remove("Temp.dat");
        printf("Item não encontrado\n");
    }
}

void AlterarItemCardapio(FILE *arquivo1)
{
    int codigoAlvo = 0;
    Cardapio Item;
    int achou = 0;
    FILE *temp = fopen("Temp.dat", "wb");

    if (temp == NULL)
    {
        printf("Erro ao alterar o cardápio\n");
        return;
    }

    printf("Digite o Codigo do item para alterar: \n");
    scanf("%d", &codigoAlvo);

    while (fread(&Item, sizeof(Cardapio), 1, arquivo1))
    {
        if (Item.CodigoCardapio == codigoAlvo)
        {
            achou = 1;
            printf("Digite o novo nome do item: ");
            scanf("%s", Item.Objeto);

            printf("Digite o novo preço: ");
            scanf("%f", &Item.PrecoCardapio);
        }

        fwrite(&Item, sizeof(Cardapio), 1, temp);
    }

    fclose(temp);
    remove("Cardapio.dat");
    rename("Temp.dat", "Cardapio.dat");

    if (achou)
    {
        printf("Item alterado com sucesso!\n");
    }
    else
    {
        printf("Item não encontrado.\n");
    }
}

void AlterarGarcom(FILE *Arquivo2)
{
    FILE *Temp = fopen("Temp.dat", "wb");
    if (Temp == NULL)
    {
        printf("Erro ao alterar o Garcom");
        return;
    }
    Garcom Guerreiro;
    int opcao = 0;
    int achou = 0;

    printf("Digite o Codigo do garcom que voce quer alterar: \n");
    scanf("%d", &opcao);

    while (fread(&Guerreiro, sizeof(Garcom), 1, Arquivo2))
    {
        if (opcao == Guerreiro.CodigoGarcom)
        {
            achou = 1;

            printf("Digite o Novo nome do garcom: \n");
            scanf("%s", Guerreiro.NomeGarcom);

            printf("Digite o Novo Codigo do garcom: \n");
            scanf("%d", &Guerreiro.CodigoGarcom);
        }
        fwrite(&Guerreiro, sizeof(Garcom), 1, Temp);
    }

    fclose(Temp);
    remove("Garcom.dat");
    rename("Temp.dat", "Garcom.dat");

    if (achou)
    {
        printf("Item alterado com sucesso!\n");
    }
    else
    {
        printf("Item não encontrado.\n");
    }
}

int main(void)
{
    Mesa *InicioMesas = NULL;
    int opcao = -1;

    do
    {
        printf("\nMenu:\n");
        printf("0 - Sair\n");
        printf("1 - Adicionar item ao Cardápio\n");
        printf("2 - Adicionar Garçom\n");
        printf("3 - Consultar Cardápio\n");
        printf("4 - Consultar Garçom\n");
        printf("5 - Alterar item do Cardápio\n");
        printf("6 - Alterar Garçom\n");
        printf("7 - Excluir item do Cardápio\n");
        printf("8 - Excluir Garçom\n");
        printf("9 - Cadastrar nova Mesa\n");
        printf("10 - Inserir pedido em uma Mesa\n");
        printf("11 - Remover Pedido de uma Mesa\n");
        printf("12 - Fechar conta de uma Mesa (Nota Fiscal)\n");
        printf("13 - Consultar Mesas abertas\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "ab");
            if (!Arq1)
            {
                printf("Erro ao abrir o arquivo do cardápio.\n");
                break;
            }
            CadastrarItemCardapio(Arq1);
            fclose(Arq1);
            break;
        }

        case 2:
        {
            FILE *Arq2 = fopen("Garcom.dat", "ab");
            if (!Arq2)
            {
                printf("Erro ao abrir o arquivo do garçom.\n");
                break;
            }
            CadastrarGarcom(Arq2);
            fclose(Arq2);
            break;
        }

        case 3:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "rb");
            if (!Arq1)
            {
                printf("Erro ao abrir o arquivo do cardápio.\n");
                break;
            }
            ConsultarCardapio(Arq1);
            fclose(Arq1);
            break;
        }

        case 4:
        {
            FILE *Arq2 = fopen("Garcom.dat", "rb");
            if (!Arq2)
            {
                printf("Erro ao abrir o arquivo do garçom.\n");
                break;
            }
            ConsultarGarcom(Arq2);
            fclose(Arq2);
            break;
        }

        case 5:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "rb");
            if (!Arq1)
            {
                printf("Erro ao abrir o arquivo do cardápio.\n");
                break;
            }
            AlterarItemCardapio(Arq1);
            fclose(Arq1);
            break;
        }

        case 6:
        {
            FILE *Arq2 = fopen("Garcom.dat", "rb");
            if (!Arq2)
            {
                printf("Erro ao abrir o arquivo do garçom.\n");
                break;
            }
            AlterarGarcom(Arq2);
            fclose(Arq2);
            break;
        }

        case 7:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "rb");
            if (!Arq1)
            {
                printf("Erro ao abrir o arquivo do cardápio.\n");
                break;
            }
            ExcluirItemCardapio(Arq1);
            fclose(Arq1);
            break;
        }

        case 8:
        {
            FILE *Arq2 = fopen("Garcom.dat", "rb");
            if (!Arq2)
            {
                printf("Erro ao abrir o arquivo do garçom.\n");
                break;
            }
            ExcluirGarcom(Arq2);
            fclose(Arq2);
            break;
        }

        case 9:
            InserirMesa(&InicioMesas);
            break;

        case 10:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "rb");
            if (!Arq1)
            {
                printf("Erro ao abrir o arquivo do cardápio.\n");
                break;
            }
            InserirPedido(&InicioMesas, Arq1);
            fclose(Arq1);
            break;
        }

        case 11:
            RemoverPedido(&InicioMesas);
            break;

        case 12:
        {
            FILE *Arq1 = fopen("Cardapio.dat", "rb");
            if (!Arq1)
            {
                printf("Erro ao fechar o arquivo do cardápio.\n");
                break;
            }

            FILE *Arq2 = fopen("Garcom.dat", "rb");
            if (!Arq2)
            {
                printf("Erro ao fechar o arquivo do garçom.\n");
                fclose(Arq1);
                break;
            }
            FecharMesa(&InicioMesas, Arq2, Arq1);
            fclose(Arq1);
            fclose(Arq2);
            break;
        }

        case 13:
            ConsultarMesas(InicioMesas);
            break;
        case 0:
            printf("Saindo...\n");
            break;

        default:
            printf("Digite um número válido\n");
        }

    } while (opcao != 0);
    return 0;
}