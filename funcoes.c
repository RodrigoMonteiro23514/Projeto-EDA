
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include <locale.h>
#include <wchar.h>  // caracteres especiais
#include <windows.h>

/**
 * @brief Get the Int object
 * 
 * @param Max 
 * @param Min 
 * @return int 
 */

int GetInt(int Max, int Min)
{
    int Numero = -1;

    printf("\n> ");
    scanf(" %d", &Numero);

    while (Numero > Max || Numero < Min)
    {
        printf("\n Escolha Invalida\n\n");
        printf("\n> ");
        scanf(" %d", &Numero);
    }

    system("cls");
    return Numero;
}



///Grava num Ficheiro
  //Lista de Operacoes
  //Ficheiro Escrito/Atualizado

void GravarFicheiro(Operacao* listagemo)
{
    FILE* Ficheiro;

    Ficheiro = fopen("file.txt", "w");
    //fprintf(Ficheiro,"Maquina|U.Tempo");

    while (listagemo != NULL)
    {

        setlocale(LC_ALL, "Portuguese");

       while (listagemo->Maquinas != NULL)
        {
           // fprintf(Ficheiro, "\n");

            fprintf(Ficheiro, "%d %d\n", listagemo->Maquinas->Id, listagemo->Maquinas->untempo);
            listagemo->Maquinas = listagemo->Maquinas->proximo;
        }

        if (listagemo->proximo != NULL)
        {
            fprintf(Ficheiro, "\n");
        }
               fprintf(Ficheiro, "NUM_OP- %d", listagemo->Id);

        listagemo = listagemo->proximo;
       
       
        

         
    }
}

//Le um Ficheiro
    //Lista  com as cenas que estão no Ficheiro

Job* LerFicheiro()
{
    FILE* Ficheiro;
    int Temp, IdOperacoes, IdMaquinas, TempoMaquinas;
    Operacao* auxOperacao,* listagemo = NULL;
    Maquina* auxMaquina,* listagemm = NULL;
    Job* listagemj = NULL;
    setlocale(LC_ALL, "Portuguese");

    Ficheiro = fopen("file.txt", "r");

    if (Ficheiro == NULL)
    {
        return false;
        //IdOperacoes = NULL;
    }

    while (!feof(Ficheiro))
    {
     
        while (fscanf(Ficheiro, "%d", &IdMaquinas) == 1)
        {

            fscanf(Ficheiro, " %d", &TempoMaquinas);
            auxMaquina = novamaquina(IdMaquinas, TempoMaquinas);
            listagemm = novamaquinafim(&listagemm, auxMaquina);

            fscanf(Ficheiro, "%*c");
        }
        setlocale(LC_ALL, "Portuguese");

         fscanf(Ficheiro, "NUM_OP- %d", &IdOperacoes);

        auxOperacao = novaoperacao(IdOperacoes);
        auxOperacao->Maquinas = listagemm;
        listagemo = novaoperacaofim(&listagemo, auxOperacao);
        listagemm = NULL;
       
    }

    Job* auxJob = novojob(1);
    auxJob->Operacoes = listagemo;
    listagemj = novojobfim(&listagemj, auxJob);

    return listagemj;
}



//Cria uma Operacao
//Id da Operacao Nova
//Uma Operacao nova

Operacao* novaoperacao(int Id)
{
    Operacao* operacaonova = (Operacao*)malloc(sizeof(Operacao));

    if (operacaonova == NULL)
    {
        return NULL;
    }

    operacaonova->Id = Id;
    operacaonova-> Maquinas = NULL;
    operacaonova->proximo = NULL;

    return operacaonova;
}

//Insere Operacao na Lista de Operacoes (no Final)
 
    //Lista de Operacoes
    //Nova Operacao
 
 //Lista de Operacoes com a Operacao (no Final)

Operacao* novaoperacaofim(Operacao** listagemo, Operacao* operacaonova)
{
    operacaonova->proximo = NULL;

    if (*listagemo == NULL)
    {
        *listagemo = operacaonova;
    }
    else
    {
        Operacao* Ultimo = *listagemo;

        while (Ultimo->proximo != NULL)
        {
            Ultimo = Ultimo->proximo;
        }

        Ultimo->proximo = operacaonova;
    }

    return *listagemo;
}

//Remove uma Operacao
//Lista das Operacoes
//Id da Operacao que quer Remover
//Lista de Operacoes sem a Operacao Removida

Operacao* eliminaroperacao(Operacao* listagemo, int Id)
{
    if (listagemo == NULL)
    {
        return NULL;
    }

    if (!operacaoexiste(listagemo, Id))
    {
        return NULL;
    }

    Operacao* aux = pesquisaoperacao(listagemo, Id);
    Operacao* auxOperacao = listagemo;

    while (auxOperacao != NULL)
    {
        if (auxOperacao == aux)
        {
                listagemo = auxOperacao->proximo;
            free(aux);
            return listagemo;
        }
        if (auxOperacao->proximo == aux)
        {
            auxOperacao->proximo = aux->proximo;
            free(aux);
            return listagemo;
        }
    }
    return listagemo;
}

//Procura uma Operacao
//Lista das Operacoes
//Id da Operacao que quer Procurar
//Operacao Procurada

Operacao* pesquisaoperacao(Operacao* listagemo, int Id)
{
    if (listagemo == NULL)
    {
        return NULL;
    }
    else
    {
        Operacao* aux = listagemo;

        while (aux != NULL)
        {
            if (aux->Id == Id)
            { 
                return (aux);
            }
            aux = aux->proximo;
        }
        return NULL;
    }
}

///Troca uma Operacao 
 
 //Lista das Operacoes
 //Id da Operacao que quer Trocar
 //Id da Operacao 2 que quer Trocar
 
 //Lista das Operacoes com as 2 Operacoes trocadas

Operacao* TrocarOperacao(Operacao* listagemo, int IdOperacao, int IdOperacaoTroca)
{
    if (listagemo == NULL)
    {
        return NULL;
    }

    Operacao* auxOperacao = pesquisaoperacao(listagemo, IdOperacao);
    Operacao* auxOperacaoTroca = pesquisaoperacao(listagemo, IdOperacaoTroca);
    Operacao* temp;

    auxOperacao->Maquinas = temp->Maquinas;
    auxOperacao->Maquinas = auxOperacaoTroca->Maquinas;
    auxOperacaoTroca->Maquinas = temp->Maquinas;

    return listagemo;
}



//Verificar se uma Operacao  existe
 //Lista das Operacoes
 //Id da Operacao
 // Nota IMPORTANTE: true - Existe Operacao / false - Nao existe Ooperação
 // NULL = VAZIO
bool operacaoexiste(Operacao* listagemo, int Id)
{
    if (listagemo == NULL)
    {
        return false;
    }

    Operacao* aux = listagemo;
    while (aux != NULL)
    {
        if (aux->Id == Id)
        {
            return true;
        }
        aux = aux->proximo;
    }
    return false;
}

//Mostra a Lista de Operacoes Fornecida
 //Lista das Operacoes
 //Lista Printada

void listaroperacoes(Operacao* listagemo)
{
    Operacao* aux = listagemo;
    
    while (aux != NULL)
    {
        printf("operacao: %d\n", aux->Id);
        listarmaquinas(aux->Maquinas);
        aux = aux->proximo;
    }
}

//Mostra os Ids de Todas as Operacoes
 //Lista de Operacoes
 
void menumostrarop(Operacao* listagemo)
{
    Operacao* aux = listagemo;
    while (aux != NULL)
    {
        printf("Codigo: %d", aux->Id);
        aux = aux->proximo;
    }
    printf("\n");
}


//Cria uma Maquina
 //Id da Maquina Nova
 //Tempo da Maquina Nova

Maquina* novamaquina(int Id, int untempo)
{
    Maquina* maquinanova = (Maquina*)malloc(sizeof(Maquina));

    if (maquinanova == NULL)
    {
        return NULL;
    }

    maquinanova->Id = Id;
    maquinanova->untempo = untempo;
    maquinanova->proximo = NULL;

    return maquinanova;
}

// Insere uma Maquina no Inicio de uma Lista Fornecida
    //Lista das Maquinas
    //Maquina que quer por na Lista
    //Lista das Maquinas

Maquina* novamaquinafim(Maquina** listagemm, Maquina* maquinanova)
{
    maquinanova->proximo = NULL;

    if (*listagemm == NULL)
    {
        *listagemm = maquinanova;
    }
    else
    {
        Maquina* Ultimo = *listagemm;

        while (Ultimo->proximo != NULL)
        {
            Ultimo = Ultimo->proximo;
        }

        Ultimo->proximo = maquinanova;
    }

    return *listagemm;
}

// Remove uma Maquina numa Lista Fornecida
 //Lista das Maquinas
 //Id da Maquina que quer Remover
 //Lista das Maquinas sem a Maquina Removida

Maquina* eliminarmaquina(Maquina* listagemm, int Id)
{
    if (listagemm == NULL)
    {
        return NULL;
    }

    if (!maquinaexiste(listagemm, Id))
    {
        return NULL;
    }

    if (listagemm->Id == Id)
    {
        Maquina* aux = listagemm;
        listagemm = listagemm->proximo;
        free(aux);
    }
    else
    {
        Maquina* aux = listagemm;
        Maquina* auxAnt = aux;

        while (aux && aux->Id != Id)
        {
            auxAnt = aux;
            aux = aux->proximo;
        }
        if (aux != NULL)
        {
            auxAnt->proximo = aux->proximo;
            free(aux);
        }
    }
    return listagemm;
}

// Procura uma Maquina numa Lista Fornecida
 //Lista das Maquinas
 //Id da Maquina que quer Procurar
 //Maquina Procurada

Maquina* pesquisarmaquina(Maquina* listagemm, int Id)
{
    if (listagemm == NULL)
    {
        return NULL;
    }
    else
    {
        Maquina* aux = listagemm;

        while (aux != NULL)
        {
            if (aux->Id == Id)
            {
                return (aux);
            }
            aux = aux->proximo;
        }
    }
    return NULL;
}

//Ve se Existe a Maquina no Contexto Fornecido
 //Lista das Maquinas
 //Id da Maquina que quer saber se Existe
 // true - Existe , false - Nao existe

bool maquinaexiste(Maquina* listagemm, int Id)
{ 
    if (listagemm == NULL)
    {

        return false;
    }

    Maquina* aux = listagemm;
    while (aux != NULL)
    {
        if (aux->Id == Id)
        {
            return true;
        }
        aux = aux->proximo;
    }
    return false;
}

//Mostra a Lista de Maquinas
 //Lista das Maquinas com respetiva unidade de tempo
 

void listarmaquinas(Maquina* listagemm)
{
    Maquina* aux = listagemm;
    while (aux != NULL)
    {
        printf("Maquina: %d\n   Unidade de tempo: %d\n", aux->Id, aux->untempo);
        aux = aux->proximo;
    }
}
//Cria um Job
//Id 

Job* novojob(int Id)
{
    Job* jobnovo = (Job*)malloc(sizeof(Job));
    if (jobnovo == NULL) return NULL;

    jobnovo->Id = Id;
    jobnovo->Operacoes = NULL;
    jobnovo->proximo = NULL;

    return jobnovo;
}

//Insere um Job no Final de uma Lista
 //Lista de Jobs
 //Novo Job

Job* novojobfim(Job** listagemj, Job* jobnovo)
{
    jobnovo->proximo = NULL;

    if (*listagemj == NULL)
    {
        *listagemj = jobnovo;
    }
    else
    {
        Job* Ultimo = *listagemj;

        while (Ultimo->proximo != NULL)
        {
            Ultimo = Ultimo->proximo;
        }

        Ultimo->proximo = jobnovo;
    }

    return *listagemj;
}

 //Mostra Job 
Job* pesquisarjob(Job* listagemj, int Id)
{
    if (listagemj == NULL)
    {
        return NULL;
    }
    else
    {
        Job* aux = listagemj;

        while (aux != NULL)
        {
            if (aux->Id == Id)
            {
                return (aux);
            }
            aux = aux->proximo;
        }
    }
    return NULL;
}




//Vê se o Job já Existe
 
bool jobexiste(Job* listagemj, int Id)
{
    if (listagemj == NULL)
    {

        return false;
    }

    Job* aux = listagemj;
    while (aux != NULL)
    {
        if (aux->Id == Id)
        {
            return true;
        }
        aux = aux->proximo;
    }
    return false;
}

// Mostra a Representação do Job

void visualizarjob(Job* listagemj)
{
    Job* aux = listagemj;
    while (aux != NULL)
    {
        //EM PORTUGUES - ERRO ORTOGRAFICO CORRIG.
        setlocale(LC_ALL, "Portuguese");
        printf("Plano de Processo:\n", aux->Id);
      
        listaroperacoes(aux->Operacoes);
        aux = aux->proximo;
    }
}
