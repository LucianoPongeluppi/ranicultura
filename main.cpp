#include <stdio.h>
#include <cstring>
#include <locale>
#include <iostream>
#include "Constante.h"
#include "Controle.h"
using namespace std;

int main()
{
    int sair = 0;
    int opcao;
    int PosicaoRa = 0;
    int PosicaoTanque = 0;
    int PosicaoMovimentacao = 0;
    struct TipoRa *VetorTipoRa;
    struct Tanque *VetorTanque;
    struct Registro *Movimentacao;
    
    CarregarRa(&PosicaoRa, VetorTipoRa);
    CarregarTanque(&PosicaoTanque, VetorTanque);
    CarregarRegistro(&PosicaoMovimentacao, Movimentacao);
    
    do{
        cout << "\nSistema" << endl;
        cout << INICIALIZAR << " - Inicializar" << endl;
        cout << INCLUIRRA << " - Incluir nova ra." << endl;
        cout << LISTARRA << " - Listar ras." << endl;
        cout << INCLUIRTANQUE << " - Incluir tanque." << endl;
        cout << LISTARTANQUE << " - Lista tanques." << endl;
        cout << ENTRADAANIMAIS << " - Entrada de animais." << endl;
        cout << ACASALAMENTO << " - Acasalamento." << endl;
        cout << TRANFERENCIA << " - Tranferencia." << endl;
        cout << ABATE << " - Abate." << endl;
        cout << ELIMINAR << " - Eliminar." << endl;
        cout << LISTARMOVIMENTACAOTANQUE << " - Listar os dados de movimentacao de um tanque." << endl;
        cout << LISTARMORTES << " - Listar animais que morreram." << endl;
        cout << LISTARDOENTES << " - Listar animais que ficaram doente." << endl;
        cout << LISTARTRANSFORMACAOEMCARNE << " - Listar animais que foram transformados em carne." << endl;
        cout << SAIR << " - Sair" << endl;
        cout << "Entre com opcao" << endl;
        cin >> opcao;
        switch(opcao){
            case INICIALIZAR:
                int total;
                cout << "Entre com o tamanho do vetor das ras" << endl;
                cin >> total;
                VetorTipoRa = (struct TipoRa *) malloc (total*sizeof(struct TipoRa));
                cout << "Entre com o tamanho do vetor do tanque" << endl;
                cin >> total;
                VetorTanque = (struct Tanque *) malloc (total*sizeof(struct Tanque));
                cout << "Entre com o tamanho do vetor de registro" << endl;
                cin >> total;
                Movimentacao = (struct Registro *) malloc (total*sizeof(struct Registro));
                break;
            case INCLUIRRA: 
                IncluirRa(&PosicaoRa, VetorTipoRa);
                cout << "\nValor do contador\n" << PosicaoRa << endl;
                break;
            case LISTARRA:
                ListarRa(0, &PosicaoRa, VetorTipoRa);
                break;
            case INCLUIRTANQUE:
                IncluirTanque(&PosicaoTanque, VetorTanque);
                cout << "\nValor do contador\n" << PosicaoTanque << endl;
                break;
            case LISTARTANQUE:
                ListarTanque(0, &PosicaoTanque, VetorTanque);
                break;
            case ENTRADAANIMAIS:
                EntradaDeAnimais(&PosicaoMovimentacao, &PosicaoRa, &PosicaoTanque, VetorTipoRa, VetorTanque, Movimentacao);
                break;
            case ACASALAMENTO:
                Acasalamento(&PosicaoMovimentacao, &PosicaoRa, &PosicaoTanque, VetorTipoRa, VetorTanque, Movimentacao);
                break;
            case TRANFERENCIA:
                Transferencia(&PosicaoMovimentacao, &PosicaoRa, &PosicaoTanque, VetorTipoRa, VetorTanque, Movimentacao);
                break;
            case ABATE:
                Abater(&PosicaoMovimentacao, &PosicaoRa, &PosicaoTanque, VetorTipoRa, VetorTanque, Movimentacao);
                break;
            case ELIMINAR:
                Eliminar(&PosicaoMovimentacao, &PosicaoRa, &PosicaoTanque, VetorTipoRa, VetorTanque, Movimentacao);
                break;
            case LISTARMOVIMENTACAOTANQUE:
                ListarMovimentacaoTanque(0, &PosicaoMovimentacao, Movimentacao);
                break;
            case LISTARMORTES:
                ListarMortes(0, &PosicaoMovimentacao, Movimentacao);
                break;
            case LISTARDOENTES:
                ListarMortesDoenca(0, &PosicaoMovimentacao, Movimentacao);
                break;
            case LISTARTRANSFORMACAOEMCARNE:
                ListarCarne(0, &PosicaoMovimentacao, Movimentacao);
                break;
            case SAIR: cout << "Deseja Realmente sair?" << endl << "1 - Sim" << endl << "2 - Nao" << endl;
				cin >> sair;
				if (sair == 1)
				    BinarioRa(&PosicaoRa, VetorTipoRa);
				    BinarioTanque(&PosicaoTanque, VetorTanque);
				    BinarioRegistro(&PosicaoMovimentacao, Movimentacao);
				    opcao = (SAIR + 1); 
			    break;
			default:
			break;
        }
    }while(opcao >= 0 && opcao <= SAIR);
    free (VetorTipoRa);
    free (VetorTanque);
    free (Movimentacao);
}
