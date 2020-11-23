#ifndef CONTRIBUICAO
#define CONTRIBUICAO
#include "Editor.h"
typedef struct contribuicao *tContribuicao;

tContribuicao inicializaContribuicao(tEditor editor, char* file);
void retirarContribuicao(tContribuicao atual);
char* returnNomeContribuicao(tContribuicao atual);
void printDadosContribuicao(tContribuicao, FILE* pagFile);
void printContribuicao(tContribuicao, FILE* pagFile);
char* autor(tContribuicao);
void freeContribuicao(tContribuicao);

#endif
