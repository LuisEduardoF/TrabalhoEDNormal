#ifndef PAGINA
#define PAGINA

typedef struct pagina *tPagina;

tPagina inicializaPagina(char* name, char* file);
void addContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual, FILE* log);
int excludeContribuicoesEditorPagina(char* Editor, tPagina atual);
void retiraContribuicaoPagina(void* EditorName, char* ContribuicaoFile, tPagina atual, FILE* log);
void addLinkPagina(tPagina secundaria, tPagina principal, FILE* log);
tPagina excludeLinkPagina(tPagina secundaria, tPagina principal);
void removeLinkPagina(tPagina secundaria, tPagina principal, FILE* log);
int searchCaminhoLinks(tPagina Origem, tPagina Destino);
void printPagina(tPagina p);
char* returnNomePagina(tPagina p);
char* returnFilePagina(tPagina p);
void* returnLinkPagina(tPagina p);
void freePagina(tPagina p);

#endif