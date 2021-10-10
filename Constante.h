#define INICIALIZAR 0
#define INCLUIRRA 1
#define LISTARRA 2
#define INCLUIRTANQUE 3
#define LISTARTANQUE 4
#define ENTRADAANIMAIS 5
#define ACASALAMENTO 6
#define TRANFERENCIA 7
#define ABATE 8
#define ELIMINAR 9
#define LISTARMOVIMENTACAOTANQUE 10
#define LISTARMORTES 11
#define LISTARDOENTES 12
#define LISTARTRANSFORMACAOEMCARNE 13
#define SAIR 14

typedef struct TipoRa{
    int id;
    char nomeRa[50];
    char origem[50];
};

typedef struct Tanque{
    char codigo[50];
    char dia[50];
    int qntAnimais;
    char tipoTanque[50];
};

typedef struct Registro{
    TipoRa ra;
    Tanque destino;
    Tanque tipoDestino;
    Tanque tanqueOrigem;
    char motivo[50];
    char data[50];
    int qnt;
};