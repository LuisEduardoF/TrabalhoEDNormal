#ifndef LISTA_PAGINA
#define LISTA_PAGINA
#include "Pagina.h"
typedef struct listapagina *tListaPagina;

tListaPagina inicializaListaPagina();
void addPagina(char* name, char* file, tListaPagina Lp);
void removeAllContribuicoesEditor(char* nameEditor, tListaPagina Lp);
void removeAllLinkPag(tPagina Pagina, tListaPagina Lp);
tPagina removePagina(char*, tListaPagina Lp);
tPagina searchPagina(char* name, tListaPagina Lp);
void printListaPagina(tListaPagina Lp);
void freeListaPagina(tListaPagina Lp);

#endif