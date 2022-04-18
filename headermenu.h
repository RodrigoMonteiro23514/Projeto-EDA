#include <stdio.h>
#include "estruturas.h"


void menuprincipal();
void listarjobmenu(Job* listagemj);
Job* novaoperacaomenu(Job* listagemj);
Maquina* novamaquinamenu(Maquina* listagemm);
Job* eliminaroperacaomenu(Job* listagemj);
Job* alteraroperacaomenu(Job* listagemj);
Operacao* alterarescolhaoperacaomenu(Operacao* OperacaoEscolhida, Operacao* listagemo);

