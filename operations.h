#ifndef operations_h
#define operations_h

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
typedef enum { TRUE, FALSE} bool;

//Variáveis
typedef struct maquina {
    int Operacao;
    int Maquina;
    int Tempo;
    struct maquina *proximo;
}   ListaMaquinas;

extern ListaMaquinas *listaMaquinas;
extern int OperacaoInput;
extern int MaquinaInput;
extern int TempoInput;

//Funções
ListaMaquinas *InsertAtBegin(int Operacao, int Maquina, int Tempo, ListaMaquinas *listaMaquinas);
void printMenu();
void PrintLista (ListaMaquinas *listaMaquinas);
bool verificarValoresInput(int Input);
void novasOperacoesInputs();
int retornarNumero(int numero);

#endif