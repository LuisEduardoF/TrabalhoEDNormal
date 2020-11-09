#ifndef LISTA_EDITOR
#define LISTA_EDITOR
#include "Pagina.h"
typedef struct listalink *tListaLink;

tListaLink inicializaListaLink();
void addLink(tPagina Pagina, tListaLink Ll);
tPagina removeLink(tPagina Pagina, tListaLink Lpl);
tPagina searchLink(tPagina Pagina, tListaLink Ll);
int caminhoLink(tPagina Origem, tPagina Destino);
void printListaLink(tListaLink Ll);
void freeListaLink(tListaLink Ll);

#endif