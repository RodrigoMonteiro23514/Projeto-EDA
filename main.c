#include <stdio.h>
#include <stdlib.h>
#include "operacoes.h"

int main()  {

    int opcao;
    do
    {
        printMenu();
        scanf("%d", &opcao);
        printf("%d", opcao);
        switch (opcao)
        {
        case 1:
            novasOperacoesInputs();
            system("clear");
            break;
        case 2:
            // Menu Remover Operacao
            break;
        case 3:
            // Menu Alterar Operacao
            break;
        case 4;
            // Menu Quantidade Minima e Listagem
            break;
        case 5;
            // Menu Quantidade Maxima e Listagem
            break;
        case 6;
            // Menu Quantdade media
            break;
        case 7;
            printLista(ListaMaquinas);
            break;
        default:
            break;
        
        }
    
    }   while (opcao != 0);
    
}