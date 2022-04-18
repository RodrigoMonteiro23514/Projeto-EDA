#ifndef estruturas
#define estruturas

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>


//Estrutura para armazenar uma Operacao
  
  //Uma Operacao tem um Id e uma Lista de Maquinas
  //Tem um apontador para a proxima Operacao
  
typedef struct Operacao
{
    int Id;
    struct Maquina* Maquinas;
    struct Operacao* proximo;
} Operacao;

//Estrutura para armazenar uma Maquina

 //Uma Maquina tem um Id e uma Unidade de Tempo.
 //Tem um apontador para a proxima Maquina

typedef struct Maquina
{
    int Id;
    int untempo;
    struct Maquina* proximo;
} Maquina;

//Estrutura para armazenar um Job
 //Um Job tem um Id e uma Lista de Operacoes.
   //Tem apontador para o proximo Job
        //Struct pouco importante para a fase 1
typedef struct Job
{
    int Id;
    struct Operacao* Operacoes;
    struct Job* proximo;
} Job;


extern Maquina* listagemm;
extern Operacao* listagemo;
extern Job* listagemj;

//Funcoes Auxiliares

int GetInt(int Max, int Min);



// Funcoes de Ficheiros

void GravarFicheiro(Operacao* listagemo);
Job* LerFicheiro();



// Funcoes das Operacoes

Operacao* novaoperacao(int Id);
Operacao* novaoperacaofim(Operacao** listagemo, Operacao* operacaonova);
Operacao* eliminaroperacao(Operacao* listagemo, int Id);
Operacao* pesquisaoperacao(Operacao* listagemo, int Id);
bool operacaoexiste(Operacao* listagemo, int Id);
void listaroperacoes(Operacao* listagemo);
void menumostrarop(Operacao* listagemo);


// Funçoes das Máquinas

Maquina* novamaquina(int Id, int untempo);
Maquina* novamaquinafim(Maquina** listagemm, Maquina* maquinanova);
Maquina* eliminarmaquina(Maquina* listagemm, int Id);
Maquina* pesquisarmaquina(Maquina* listagemm, int Id);
bool maquinaexiste(Maquina* listagemm, int Id);
void listarmaquinas(Maquina* listagemm);



// Funçoes de Job

Job* novojob(int Id);
Job* novojobfim(Job** listagemj, Job* jobnovo);
Job* pesquisarjob(Job* listagemj, int Id);
bool jobexiste(Job* listagemj, int Id);
void visualizarjob(Job* listagemj);

#endif