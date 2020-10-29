#ifndef PAGINA
#define PAGINA

typedef struct pagina *tPagina;

tPagina inicializaPagina(char* name, char* file);
void addContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual);
int removeContribuicoesEditorPagina(char* Editor, tPagina atual);
void retiraContribuicaoPagina(void* EditorName, char* ContribuicaoFile, tPagina atual);
void addLinkPagina(tPagina secundaria, tPagina principal);
int removeLinkPagina(tPagina secundaria, tPagina principal);
void printPagina(tPagina p);
char* returnNomePagina(tPagina p);
void freePagina(tPagina p);

#endif