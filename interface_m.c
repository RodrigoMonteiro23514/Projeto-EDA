#include <stdio.h>
#include <stdlib.h>
#include<conio.h>
#include "headermenu.h"
#include "estruturas.h"

/**
 * Menu Principal
 * 
 */
void menuprincipal()
{
    system("cls");
    int Escolha;
    Job* listagemj = LerFicheiro();

    do
    {   
        printf("---------------------------------------------------------------------\n");
        printf("---------------------- MENU-------------------------------------\n");
        printf("---------------------------------------------------------------------\n"
               " 1.Inserir nova operacao\n"
               " 2.Remover operacao\n"
               " 3.Modificar operacao\n"
               " 4.Visualizar\n"
               " 0.Sair\n");

        Escolha = GetInt(8, 0);

        switch (Escolha)
        {
        case 1:

            listagemj = novaoperacaomenu(listagemj);
            break;
            
        
        case 2:
            listagemj = eliminaroperacaomenu(listagemj);
            break;

        case 3:
            listagemj = alteraroperacaomenu(listagemj);
            break;

        case 4:
           
            listarjobmenu(listagemj);
            break;
        case 0:
            break;

        default:
            printf("\n\t Escolha Invalida \n\n");
            menuprincipal();
            break;
        }
    } while (Escolha != 0);

    GravarFicheiro(listagemj->Operacoes);
}

/**
 Mostra o Job Introduzido no Programa
 * 
  Lista de Jobs;
 */


void listarjobmenu(Job* listagemj)
{
   if (listagemj == NULL)
   {
       printf("O Job nao existe!");
       menuprincipal();
   }
    else
    {
        visualizarjob(listagemj);
        printf("Aperte uma tecla...");
    getche();
    system("cls");
    return;
    }
    
    
    
}

/**
 *Menu para Adicionar Operacoes
 * 
 *  Lista de Jobs
 *  Lista de Jobs com Nova Operacao
 */
Job* novaoperacaomenu(Job* listagemj)
{
    int IdOperacao;

    system("cls");

    printf("Qual é o código da máquina que deseja inserir?\n\t"); // /t -> afastamento da margem
    scanf(" %d", &IdOperacao);

    if (operacaoexiste(listagemj->Operacoes, IdOperacao) == true)
    {
        printf("\n Escolha Inválida\n\n");
        printf("\nOperacao ja existe\n\n");
        printf("Aperte alguma tecla...");
        getche();
        system("cls");
        return listagemj;
    }

    Operacao* auxOperacao = novaoperacao(IdOperacao);

    Maquina* auxMaquina;
    auxMaquina = novamaquinamenu(auxMaquina);

    auxOperacao->Maquinas = auxMaquina;

    listagemj->Operacoes =  novaoperacaofim(&listagemj->Operacoes, auxOperacao);

    system("cls");
     printf("\n Operacao adicionada\n\n");
        printf("Aperte alguma tecla...");
    getche();
    system("cls");
    return listagemj;
}

/**
 * Menu para Adicionar Maquinas
 * 
 * Lista de Maquinas
 * Lista de Mquinas com Maquinas Adicionadas 
 */
Maquina* novamaquinamenu(Maquina* listagemm)
{
    int Escolha;
    listagemm = NULL;

    do
    {
        system("cls");

        system("cls");
        printf("1 - Inserir Maquina \n"
               "0 - Confirmar\n");

        Escolha = GetInt(1, 0);

        switch(Escolha)
        {
        case 1:
            system("cls");

            int IdMaquina, untempo;

            printf("Qual é o código da máquina que deseja inserir? ");
            scanf(" %d", &IdMaquina);
            printf("Qual é o tempo da máquina que deseja inserir? ");
            scanf(" %d", &untempo);

            Maquina* auxMaquina = novamaquina(IdMaquina, untempo);
            listagemm = novamaquinafim(&listagemm, auxMaquina);
            break;

        case 0:
            return listagemm;
        
        default:
            printf("\n\t Escolha Invalida\n\n");
            return listagemm;
        }
    } while (Escolha != 0); 
}

//Menu para Remover uma Operacao
 //Lista de Jobs 
 // Lista de Jobs sem Operacao

Job* eliminaroperacaomenu(Job* listagemj)
{
    system("cls");

    int IdOperacao;

    menumostrarop(listagemj->Operacoes);

    printf("Qual é o código da máquina que deseja remover?\n\t");
    scanf(" %d", &IdOperacao);

    if (operacaoexiste(listagemj->Operacoes, IdOperacao) == false)
    {
        printf("Escolha Inválida\n\n");
        printf("Operacao não existe\n\n");
        printf("Aperte alguma tecla...");
        getche();
        system("cls");
        return listagemj;
    }

    Job* auxJob = pesquisarjob(listagemj, listagemj->Id);
    Operacao* auxOperacao = pesquisaoperacao(listagemj->Operacoes, IdOperacao);

    if (auxOperacao != NULL)
    {
        Operacao* auxOperacao2 = pesquisaoperacao(listagemj->Operacoes, IdOperacao - 1);
        if (auxOperacao2 != NULL)
        {
            auxOperacao2->proximo = auxOperacao->proximo;
        }
        else
        {
            auxJob->Operacoes = auxOperacao->proximo;
        }
        free(auxOperacao);
        auxOperacao = auxJob->Operacoes;
        IdOperacao = 1;
        while (auxOperacao != NULL)
        {
            auxOperacao->Id = IdOperacao;
            IdOperacao++;
            auxOperacao = auxOperacao->proximo;
        }
    }

    system("cls");
     printf("operação eliminada com sucesso\n\n");
        printf("Aperte alguma tecla...");
    getche();
    system("cls");
    return listagemj;
}

//Menu para escolher que Operacao quer Alterar
//Lista de Jobs
//Lista de Jobs com Operacao Alterada

    Job* alteraroperacaomenu(Job* listagemj)
{
    system("cls");

    int IdOperacao;

    menumostrarop(listagemj->Operacoes);

    printf("Qual é o código da operação que deseja alterar?\n\t");
    scanf(" %d", &IdOperacao);

    if (operacaoexiste(listagemj->Operacoes, IdOperacao) == false)
    {
         printf("Escolha Inválida\n\n");
        printf("A operação não existe\n\n");
        printf("Aperte alguma tecla...");
        getche();
        system("cls");
        return listagemj;
    }

    Operacao* auxOperacao = pesquisaoperacao(listagemj->Operacoes, IdOperacao);

    auxOperacao = alterarescolhaoperacaomenu(auxOperacao, listagemj->Operacoes);

    system("cls");
    printf("Aperte alguma tecla...");
    getche();
    system("cls");
    return listagemj;
}


//Menu para Alterar a Operacao
  
    //Operacao Escolhida 
    //Lista de Operacoes 
    //Lista de Operacoes Atualizada 
 
 Operacao* alterarescolhaoperacaomenu(Operacao* OperacaoEscolhida, Operacao* listagemo)
{
    int Escolha;

    do
    {
        system("cls");
        printf("\t  1. Inserir maquina \n"
               "\t  2. Eliminar maquina \n"
               "\t  3. Modificar o tempo de uma maquina \n"
               "\n\\ 0. Voltar para trás\n");

        Escolha = GetInt(4, 0);
        switch(Escolha)
        {
        case 1:
            system("cls");

            int Id, untempo;

            printf("Digite o código da maquina:\n\t> ");
            scanf(" %d", &Id);
            printf("Digite o tempo da maquina:\n\t> ");
            scanf(" %d", &untempo);

            Maquina* maquinanova = novamaquina(Id, untempo);
            OperacaoEscolhida->Maquinas = novamaquinafim(&OperacaoEscolhida->Maquinas, maquinanova);
            break;

        case 2:
            system("cls");

            int Id2;

            printf("Digite o código da maquina:\n\t> ");
            scanf(" %d", &Id2);

            Maquina* auxMaquina = pesquisarmaquina(OperacaoEscolhida->Maquinas, Id2);

            if (auxMaquina == NULL)
            {
                    printf("Escolha Inválida\n\n");
                printf("A maquina não existe\n\n");
                printf("Aperte alguma tecla...");
                getche();
                system("cls");
                break;
            }

            OperacaoEscolhida->Maquinas = eliminarmaquina(OperacaoEscolhida->Maquinas, auxMaquina->Id);
            break;

        case 3:
            system("cls");

            int Id3, NovoTempo;

            printf("Digite o código da maquina:\n\t> ");
            scanf(" %d", &Id3);

            Maquina* auxMaquina2 = pesquisarmaquina(OperacaoEscolhida->Maquinas, Id3);

            if (auxMaquina2 == NULL)
            {
                printf("Escolha Inválida\n\n");
                printf("A maquina não existe\n\n");
                printf("Aperte alguma tecla...");
                getche();
                system("cls");
                break;
            }

            printf("Digite a nova unidade de tempo:\n\t> ");
            scanf(" %d", &NovoTempo);

            auxMaquina2->untempo = NovoTempo;

            printf("O tempo foi alterado");
                printf("Aperte alguma tecla...");
            getche();
            system("cls");
            break;
        
        case 0:
            return listagemo;

        default:
            printf("\n Escolha Inválida\n\n");
            return listagemo;
        }
    } while (Escolha != 0);
    
}



