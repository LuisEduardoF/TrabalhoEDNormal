#ifndef LISTA_CONTRIBUICAO
#define LISTA_CONTRIBUICAO
#include "Contribuicao.h"

typedef struct listacontribuicao *tListaContribuicao;

tListaContribuicao inicializaListaContribuicao();
void addContribuicao(tEditor e, char* file, tListaContribuicao Lc);
tContribuicao searchContribuicao(char* file,  tListaContribuicao Lc);
tContribuicao removeContribuicaoEditor(char* EditorName,  tListaContribuicao Lc);
tContribuicao removeContribuicao(char* file, tListaContribuicao Lc);
void printListaContribuicaoHistorico(tListaContribuicao Lc, FILE* pagFile);
void printListaContribuicao(tListaContribuicao Lc, FILE* pagFile);
void freeListaContribuicao(tListaContribuicao Lc);
#endif
