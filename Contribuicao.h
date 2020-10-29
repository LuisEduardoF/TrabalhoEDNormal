#ifndef CONTRIBUICAO
#define CONTRIBUICAO
#include "Editor.h"
typedef struct contribuicao *tContribuicao;

tContribuicao inicializaContribuicao(tEditor editor, char* file);
char* autor(tContribuicao);
void retirarContribuicao(tContribuicao atual);
char* returnNomeContribuicao(tContribuicao atual);
void printContribuicao(tContribuicao);
void freeContribuicao(tContribuicao);

#endif
