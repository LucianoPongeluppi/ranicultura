#include <iostream>
#include <cstring>
#include <locale>
#include <string.h>
using namespace std;

void BinarioRa(int *posicao, struct TipoRa *VetorTipoRa){
    FILE *arquivo;
    arquivo = fopen("RaBinario.bin","wb+");
    if (arquivo == NULL)
    {
        printf ("Problemas na criação do Arquivo\n");
        return;
    }
    fwrite(VetorTipoRa, sizeof(TipoRa), *posicao, arquivo);
    fclose(arquivo);
    system("clear");
    cout<<"\nArquivo gerado com sucesso.";
    system ("pause");
}

void BinarioTanque(int *posicao, struct Tanque *VetorTanque){
    FILE *arquivo;
    arquivo = fopen("TanqueBinario.bin","wb+");
    if (arquivo == NULL)
    {
        printf ("Problemas na criação do Arquivo\n");
        return;
    }
    fwrite(VetorTanque, sizeof(Tanque), *posicao, arquivo);
    fclose(arquivo);
    system("clear");
    cout<<"\nArquivo gerado com sucesso.";
    system ("pause");
}

void BinarioRegistro(int *posicao, struct Registro *Movimentacao){
    FILE *arquivo;
    arquivo = fopen("RegistroBinario.bin","wb+");
    if (arquivo == NULL)
    {
        printf ("Problemas na criação do Arquivo\n");
        return;
    }
    fwrite(Movimentacao, sizeof(Registro), *posicao, arquivo);
    fclose(arquivo);
    system("clear");
    cout<<"\nArquivo gerado com sucesso.";
    system ("pause");
}

void CarregarRa(int *posicao, struct TipoRa *VetorTipoRa){
    FILE *arquivo;
    *posicao = 0;
    arquivo = fopen("RaBinario.bin", "rb+");
    if (arquivo){
        fread(VetorTipoRa, sizeof (TipoRa), *posicao, arquivo);
        for (int i = 0; i < *posicao; i++){
            if (VetorTipoRa[i].id != NULL){
                *posicao = (*posicao) + 1;
            }
            fclose(arquivo);
        }
    }
    system("clear");
    cout << "\nArquivo gerado com sucesso.";
    system ("pause");
}

void CarregarTanque(int *posicao, struct Tanque *VetorTanque){
    FILE *arquivo;
    *posicao = 0;
    arquivo = fopen("TanqueBinario.bin", "rb+");
    if (arquivo){
        fread(VetorTanque, sizeof (Tanque), *posicao, arquivo);
        for (int i = 0; i < *posicao; i++){
            if (VetorTanque[i].codigo[0] != NULL){
                *posicao = (*posicao) +1;
            }
            fclose(arquivo);
        }
        
    }
    system("clear");
    cout << "\nArquivo gerado com sucesso.";
    system ("pause");
}

void CarregarRegistro(int *posicao, struct Registro *Movimentacao){
    FILE *arquivo;
    *posicao = 0;
    arquivo = fopen("RegistroBinario.bin", "rb+");
    if (arquivo){
        fread(Movimentacao, sizeof (Registro), *posicao, arquivo);
        for (int i = 0; i < *posicao; i++){
            if (Movimentacao[i].ra.nomeRa[0] != NULL){
                *posicao = (*posicao) + 1;
            }
            fclose(arquivo);
        }
        
    }
    system("clear");
    cout << "\nArquivo gerado com sucesso.";
    system ("pause");
}

void IncluirRa(int *posicao, struct TipoRa *VetorTipoRa){
    TipoRa v;
    cout << "\nCadastrar" << endl;
    
    cout << "Entre com o ID da ra: " << endl;
    cin >> v.id;
    
    cout << "Entre com o nome da ra: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(v.nomeRa, nome1.c_str());
    
    cout << "Entre com a origem da ra: " << endl;
    getline(cin, nome1);
    strcpy(v.origem, nome1.c_str());
    
    VetorTipoRa[*posicao] = v;
    *posicao = (*posicao) + 1;
}

void ListarRa(int i, int *posicao, struct TipoRa *VetorTipoRa){
    if(i == *posicao){
        return;
    }
    cout << "\nIndice: " << i << endl;
    cout << "ID da ra: " << VetorTipoRa[i].id << endl;
    cout << "Nome da ra: " << VetorTipoRa[i].nomeRa << endl;
    cout << "Origem da ra: " << VetorTipoRa[i].origem << endl << endl;
    ListarRa(i + 1, posicao, VetorTipoRa);
}

void IncluirTanque(int *posicao, struct Tanque *VetorTanque){
    Tanque v;
    cout << "\nCadastrar" << endl;
    
    cout << "Entre com o codigo do tanque: " << endl;
    cin >> v.codigo;
    
    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(v.dia, nome1.c_str());
    
    v.qntAnimais = 0;
    int aux = 0;
    
    do{
        cout << "Entre com o tipo do tanque: " << endl;
        cout << "1 - Baia de mantenca" << endl;
        cout << "2 - Baia inicial" << endl;
        cout << "3 - Baia dos girinos" << endl;
        cout << "4 - Baia de acalamento" << endl;
        cout << "5 - Baia de terminacao" << endl;
        cin >> aux;
    }while(aux <=0 || aux > 5);
    if (aux == 1){
        getline(cin, nome1);
        strcpy(v.tipoTanque, "Mantenca");
    }
    if (aux == 2){
        getline(cin, nome1);
        strcpy(v.tipoTanque, "Inicial");
    }
    if (aux == 3){
        getline(cin, nome1);
        strcpy(v.tipoTanque, "Girinos");
    }
    if (aux == 4){
        getline(cin, nome1);
        strcpy(v.tipoTanque, "Acasalamento");
    }
    if (aux == 5){
        getline(cin, nome1);
        strcpy(v.tipoTanque, "Terminacao");
    }
    
    VetorTanque[*posicao] = v;
    *posicao = (*posicao) + 1;
}

void ListarTanque(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    cout << "\nIndice: " << i << endl;
    cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
    cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
    cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
    cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    ListarTanque(i + 1, posicao, VetorTanque);
}

void ListarMantenca(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(VetorTanque[i].tipoTanque, "Mantenca")){
        cout << "\nIndice: " << i << endl;
        cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
        cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
        cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
        cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    }
    ListarMantenca(i + 1, posicao, VetorTanque);
}

void EntradaDeAnimais(int *posicao, int *ra, int *tanque, struct TipoRa *VetorTipoRa, struct Tanque *VetorTanque, struct Registro *Movimentacao){
    Registro r;

    cout << endl;
    ListarRa(0, ra, VetorTipoRa);
    int IdRa;
    cout << "Digite o indice da ra: " << endl;
    cin >> IdRa;
    
    ListarMantenca(0, tanque, VetorTanque);
    int CodigoDoTanque;
    cout << "\nDigite o indice do tanque: " << endl;
    cin >> CodigoDoTanque;
    
    cout << "Digite a quantidade de ras que deseja adicionar: ";
    cin >> r.qnt;
    
    VetorTanque[CodigoDoTanque].qntAnimais += r.qnt;
    
    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(r.data, nome1.c_str());
    strcpy(r.tanqueOrigem.tipoTanque, VetorTipoRa[IdRa].origem);
    strcpy(r.ra.nomeRa, VetorTipoRa[IdRa].nomeRa);
    strcpy(r.destino.tipoTanque, VetorTanque[CodigoDoTanque].codigo);
    strcpy(r.tipoDestino.tipoTanque, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(VetorTanque[CodigoDoTanque].dia, r.data);
    strcpy(VetorTipoRa[IdRa].origem, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(r.motivo, "Nao houve retirada, apenas entrada.");
    
    Movimentacao[*posicao] = r;
    *posicao = (*posicao) + 1;
}

void ListarAcasalamento(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(VetorTanque[i].tipoTanque, "Acasalamento")){
        cout << "\nIndice: " << i << endl;
        cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
        cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
        cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
        cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    }
    ListarAcasalamento(i + 1, posicao, VetorTanque);
}

void Acasalamento(int *posicao, int *ra, int *tanque, struct TipoRa *VetorTipoRa, struct Tanque *VetorTanque, struct Registro *Movimentacao){
    Registro r;

    cout << endl;
    ListarRa(0, ra, VetorTipoRa);
    int IdRa;
    cout << "Digite o indice da ra: " << endl;
    cin >> IdRa;
    
    ListarMantenca(0, tanque, VetorTanque);
    int CodigoDoTanque;
    cout << "\nDigite o indice do tanque de mantenca que deseja retirar as ras: " << endl;
    cin >> CodigoDoTanque;
    
    ListarAcasalamento(0, tanque, VetorTanque);
    int aux;
    cout << "\nDigite o indice do tanque de acasalamento: " << endl;
    cin >> aux;
    
    cout << "Digite a quantidade de ras que deseja adicionar: ";
    cin >> r.qnt;
    
    VetorTanque[CodigoDoTanque].qntAnimais -= r.qnt;
    VetorTanque[aux].qntAnimais += r.qnt;
    
    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(r.data, nome1.c_str());
    strcpy(r.tanqueOrigem.tipoTanque, VetorTipoRa[IdRa].origem);
    strcpy(r.ra.nomeRa, VetorTipoRa[IdRa].nomeRa);
    strcpy(r.destino.tipoTanque, VetorTanque[CodigoDoTanque].codigo);
    strcpy(r.tipoDestino.tipoTanque, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(VetorTanque[CodigoDoTanque].dia, r.data);
    strcpy(VetorTipoRa[IdRa].origem, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(r.motivo, "Movimentacao para acasalamento");
    
    Movimentacao[*posicao] = r;
    *posicao = (*posicao) + 1;
}

void ListarTransferenciaOrigem(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(VetorTanque[i].tipoTanque, "Inicial") || 0 == strcmp(VetorTanque[i].tipoTanque, "Girinos") || 0 == strcmp(VetorTanque[i].tipoTanque, "Acasalamento")){
        cout << "\nIndice: " << i << endl;
        cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
        cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
        cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
        cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    }
    ListarAcasalamento(i + 1, posicao, VetorTanque);
}

void ListarTransferenciaDestino(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(VetorTanque[i].tipoTanque, "Inicial") || 0 == strcmp(VetorTanque[i].tipoTanque, "Girinos") || 0 == strcmp(VetorTanque[i].tipoTanque, "Terminacao")){
        cout << "\nIndice: " << i << endl;
        cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
        cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
        cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
        cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    }
    ListarAcasalamento(i + 1, posicao, VetorTanque);
}

void Transferencia(int *posicao, int *ra, int *tanque, struct TipoRa *VetorTipoRa, struct Tanque *VetorTanque, struct Registro *Movimentacao){
    Registro r;

    cout << endl;
    ListarRa(0, ra, VetorTipoRa);
    int IdRa;
    cout << "Digite o indice da ra: " << endl;
    cin >> IdRa;
    
    ListarTransferenciaOrigem(0, tanque, VetorTanque);
    int CodigoDoTanque;
    cout << "\nDigite o indice do tanque que deseja retirar as ras: " << endl;
    cin >> CodigoDoTanque;
    
    ListarTransferenciaDestino(0, tanque, VetorTanque);
    int aux;
    cout << "\nDigite o indice do tanque de destino das ras: " << endl;
    cin >> aux;
    
    cout << "Digite a quantidade de ras que deseja adicionar: ";
    cin >> r.qnt;
    
    VetorTanque[CodigoDoTanque].qntAnimais -= r.qnt;
    VetorTanque[aux].qntAnimais += r.qnt;
    
    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(r.data, nome1.c_str());
    strcpy(r.tanqueOrigem.tipoTanque, VetorTipoRa[IdRa].origem);
    strcpy(r.ra.nomeRa, VetorTipoRa[IdRa].nomeRa);
    strcpy(r.destino.tipoTanque, VetorTanque[CodigoDoTanque].codigo);
    strcpy(r.tipoDestino.tipoTanque, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(VetorTanque[CodigoDoTanque].dia, r.data);
    strcpy(VetorTipoRa[IdRa].origem, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(r.motivo, "Transferencia");
    
    Movimentacao[*posicao] = r;
    *posicao = (*posicao) + 1;
}


void ListarTerminacao(int i, int *posicao, struct Tanque *VetorTanque){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(VetorTanque[i].tipoTanque, "Terminacao")){
        cout << "\nIndice: " << i << endl;
        cout << "Codigo do tanque: " << VetorTanque[i].codigo << endl;
        cout << "Dia da ultima alteracao: " << VetorTanque[i].dia << endl;
        cout << "Populacao atual do tanque: " << VetorTanque[i].qntAnimais << endl;
        cout << "Tipo do tanque: " << VetorTanque[i].tipoTanque << endl;
    }
    ListarAcasalamento(i + 1, posicao, VetorTanque);
}

void Abater(int *posicao, int *ra, int *tanque, struct TipoRa *VetorTipoRa, struct Tanque *VetorTanque, struct Registro *Movimentacao){
    Registro r;

    cout << endl;
    ListarRa(0, ra, VetorTipoRa);
    int IdRa;
    cout << "Digite o indice da ra: " << endl;
    cin >> IdRa;
    
    ListarTerminacao(0, tanque, VetorTanque);
    int CodigoDoTanque;
    cout << "\nDigite o indice do tanque de terminacao que deseja retirar as ras: " << endl;
    cin >> CodigoDoTanque;

    cout << "Digite a quantidade de ras que deseja abater: ";
    cin >> r.qnt;
    
    VetorTanque[CodigoDoTanque].qntAnimais -= r.qnt;

    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(r.data, nome1.c_str());
    strcpy(r.tanqueOrigem.tipoTanque, VetorTipoRa[IdRa].origem);
    strcpy(r.ra.nomeRa, VetorTipoRa[IdRa].nomeRa);
    strcpy(r.destino.tipoTanque, VetorTanque[CodigoDoTanque].codigo);
    strcpy(r.tipoDestino.tipoTanque, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(VetorTanque[CodigoDoTanque].dia, r.data);
    strcpy(VetorTipoRa[IdRa].origem, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(r.motivo, "Abatimento");
    
    Movimentacao[*posicao] = r;
    *posicao = (*posicao) + 1;
}

void Eliminar(int *posicao, int *ra, int *tanque, struct TipoRa *VetorTipoRa, struct Tanque *VetorTanque, struct Registro *Movimentacao){
    Registro r;
    int aux=0;
    cout << endl;
    ListarRa(0, ra, VetorTipoRa);
    int IdRa;
    cout << "Digite o indice da ra: " << endl;
    cin >> IdRa;
    
    ListarTanque(0, tanque, VetorTanque);
    int CodigoDoTanque;
    cout << "\nDigite o indice do tanque que deseja dar baixa: " << endl;
    cin >> CodigoDoTanque;


    cout << "\nDigite a quantidade de ras que deseja abater: ";
    cin >> r.qnt;
    
    do{
        cout << "\nEntre com o motivo da morte: \n" << "\n1- Doenca\n2- Morte\n" <<endl;
        cin>> aux;
        
    }while (aux>2 || aux <=0 );

    if (aux == 1){
        strcpy(r.motivo, "Doenca");
    }
    if (aux == 2){
        strcpy(r.motivo, "Morte");
    }
    
    VetorTanque[CodigoDoTanque].qntAnimais -= r.qnt;

    cout << "Entre com a data atual: " << endl;
    string nome1;
    cin.ignore();
    getline(cin, nome1);
    strcpy(r.data, nome1.c_str());
    strcpy(r.tanqueOrigem.tipoTanque, VetorTipoRa[IdRa].origem);
    strcpy(r.ra.nomeRa, VetorTipoRa[IdRa].nomeRa);
    strcpy(r.destino.tipoTanque, VetorTanque[CodigoDoTanque].codigo);
    strcpy(r.tipoDestino.tipoTanque, VetorTanque[CodigoDoTanque].tipoTanque);
    strcpy(VetorTanque[CodigoDoTanque].dia, r.data);
    strcpy(VetorTipoRa[IdRa].origem, VetorTanque[CodigoDoTanque].tipoTanque);
    
    Movimentacao[*posicao] = r;
    *posicao = (*posicao) + 1;
}

void ListarMovimentacaoTanque(int i, int *posicao, struct Registro *Movimentacao){
    if(i == *posicao){
        return;
    }
    cout << "\n* * * * * * M O V I M E N T A C A O nº " << i+1 << " * * * * * * \n";
    cout << "Tipo do tanque de origem: " << Movimentacao[i].tanqueOrigem.tipoTanque << endl;
    cout << "Ra: " << Movimentacao[i].ra.nomeRa << endl;
    cout << "Quantidade de ras no tanque: " << Movimentacao[i].qnt << endl;
    cout << "Data da ultima movimentacao: " << Movimentacao[i].data << endl;
    cout << "Motivo da retirada: " << Movimentacao[i].motivo << endl;
    cout << "Tipo do tanque destino: " << Movimentacao[i].tipoDestino.tipoTanque << endl;
    cout << "Codigo do tanque destino: " << Movimentacao[i].destino.tipoTanque << endl;
    ListarMovimentacaoTanque(i + 1, posicao, Movimentacao);
}

void ListarMortesDoenca(int i, int *posicao, struct Registro *Movimentacao){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(Movimentacao[i].motivo, "Doenca")){
        cout << "\n* * * * * * LISTAGEM DE BAIXAS POR DOENCA * * * * * * \n";
        cout << "Codigo do tanque da baixa: " << Movimentacao[i].destino.tipoTanque << endl;
        cout << "Tipo do tanque de origem: " << Movimentacao[i].tipoDestino.tipoTanque << endl;
        cout << "Ra: " << Movimentacao[i].ra.nomeRa << endl;
        cout << "Quantidade de ras que ficaram doentes: " << Movimentacao[i].qnt << endl;
        cout << "Data da baixa: " << Movimentacao[i].data << endl;
    }
    ListarMortesDoenca(i + 1, posicao, Movimentacao);
}

void ListarMortes(int i, int *posicao, struct Registro *Movimentacao){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(Movimentacao[i].motivo, "Morte")){
        cout << "\n* * * * * * LISTAGEM DE MORTES * * * * * * \n";
        cout << "Codigo do tanque da baixa: " << Movimentacao[i].destino.tipoTanque << endl;
        cout << "Tipo do tanque de origem: " << Movimentacao[i].tipoDestino.tipoTanque << endl;
        cout << "Ra: " << Movimentacao[i].ra.nomeRa << endl;
        cout << "Quantidade de ras que morreram: " << Movimentacao[i].qnt << endl;
        cout << "Data da baixa: " << Movimentacao[i].data << endl;
    }
    ListarMortes(i + 1, posicao, Movimentacao);
}

void ListarCarne(int i, int *posicao, struct Registro *Movimentacao){
    if(i == *posicao){
        return;
    }
    if (0 == strcmp(Movimentacao[i].motivo, "Abatimento")){
        cout << "\n* * * * * * RAS TRANSFORMADAS EM CARNE * * * * * * \n";
        cout << "Codigo do tanque da baixa: " << Movimentacao[i].destino.tipoTanque << endl;
        cout << "Tipo do tanque de origem: " << Movimentacao[i].tipoDestino.tipoTanque << endl;
        cout << "Ra: " << Movimentacao[i].ra.nomeRa << endl;
        cout << "Quantidade que foram abatidas: " << Movimentacao[i].qnt << endl;
        cout << "Data de saida: " << Movimentacao[i].data << endl;
    }
    ListarCarne(i + 1, posicao, Movimentacao);
}