#include "operacoes.h"
/*-Variáveis 
Declaração das variáveis globais utilizadas
ListaMaquinas -> Novo apontador para nova lista de Operações
OperacaoInput; MaquinaInput; TempoInput -> Inputs do utilizador
*/
ListaMaquinas *ListaMaquinas = NULL; // Declaração nova lista
int OperacaoInput;
int MaquinaInput;
int TempoInput;

/* - Funções para executar a manipulação da lista
InsertAtBegin -> Adiciona uma nova operação no início da lista
PrintLista -> Lista as operações inseridas
*/ 
ListaMaquinas *InsertAtBegin(int Operacao, int Maquina, int Tempo, ListaMaquinas *ListaMaquinas) {

    ListaMaquinas *new = (ListaMaquinas *)malloc (sizeof(ListaMaquinas));

    if (new != NULL) {

        new -> Operacao = Operacao;
        new -> Maquina = Maquina;
        new -> Tempo = Tempo;
        new -> proximo = ListaMaquinas;

        return(new);
    }   else {
        return(ListaMaquinas);
        }
    
}
void printLista(ListaMaquinas *ListaMaquinas) {
    char opcao;
    int posicao = 1;
    system("clear");

    if (ListaMaquinas != NULL) {
        printf("Maquinas");
        while(ListaMaquinas != NULL) {
            printf("%d\n", posicao);
            printf("Numero da Operacao: %d\n", ListaMaquinas->Operacao);
            printf("Numero da Maquina: %d\n", ListaMaquinas->Maquina);
            printf("Duracao: %d\n", ListaMaquinas-> Tempo);
            ListaMaquinas = ListaMaquinas->proximo;
            posicao++;
        }
    }
    
    printf("-----------------------------------------------------------------------------\n");
    scanf("%c", &opcao);
    do{
        printf("Clique em 'r' para voltar: ")
        scanf("%c", &opcao);
        printf("opcao: %c\n", &opcao);
    }   while ((opcao != 'r') && (opcao != 'R'));
    system("clear");
}   

/*Funções para realizar tarefas de verificação
verificarValoresInput-> recebe valores e faz a verificação
*/

bool verificarValoresInput(int input) {
    if (input > 0)
    {
        return TRUE;
    } else {
        return FALSE;
    }
}

/* Inputs
Menu para visualizar os processos
printMenu -> print das diferentes opções; novasOperacoesInputs -> recessão dos inputs do utilizador de uma nova operação
*/
void printMenu(){
    printf("                                         MENU                                        \n");
    printf("1 - Inserir operação nova\n");
    printf("2 - Remover operação\n");
    printf("3 - Mudar operação\n");
    printf("4 - Quantidade mínima e listagem\n");
    printf("5 - Quantidade máxima e listagem\n");
    printf("6 - Quantidade média\n");
    printf("7 - Sair\n");
    printf("opcao: ");
}

void novasOperacoesInputs() {
    char opcao;
    system("clear");
    do{
        printf("Numero da operacao:");
        scanf("%d", &OperacaoInput);

        if (verificarValoresInput(OperacaoInput) == FALSE)
        printf("Invalido, por favor insira um valor > 0\n");
    } while (verificarValoresInput(OperacaoInput) == FALSE); 

    do { system("clear");
        do {
            printf ("Numero da maquina: ");
            scanf("%d", &MaquinaInput);
            if (verificarValoresInput(MaquinaInput) == FALSE)
            printf("Invalido, por favor insira um valor > 0\n");
        }   while (verificarValoresInput(MaquinaInput) == FALSE);

        do {
            printf("Tempo: ");
            scanf("%d", &TempoInput);
            if (verificarValoresInput(TempoInput) == FALSE)
            printf("Invalido, por favor insira um valor > 0\n");
        }   while (verificarValoresInput(TempoInput) == FALSE);

        ListaMaquinas = InsertAtBegin(OperacaoInput, MaquinaInput, TempoInput, ListaMaquinas);

        if (ListaMaquinas != NULL) {
            printf("Uma maquina nova foi inserida com sucesso!!\n");
        }   else {
            printf("Erro!!");   
        }

        do {
            printf("Inserir (s/n): ");
            scanf("%c", &opcao);
        } while (opcao != 's' && opcao != 'S' && opcao != 'n' && opcao != 'N');

    } while(opcao == 's' || opcao == 'S');

}


// Remover a partir da posicao

ListaMaquinas *removeByposition(int position, ListaMaquinas *ListaMaquinas); {

    ListaMaquinas *p = ListaMaquinas;
    ListaMaquinas *q = NULL;

    for (int i = 0; i < position - 1; i++)
    {
        q = p;
        p = p -> proximo;
    }
    q -> proximo = p -> proximo;
}


// Receber dados dos ficheiros e guardar na memoria
/* void GuardarJobsMemoria() -> guardar jobs na memoria e checkar quantos estão na pasta

*/



