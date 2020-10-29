#ifndef WIKIED
#define WIKIED

typedef struct wikiED *tWikiED;

tWikiED inicializaWiked();
void inserePagina(char* nome, char* file, tWikiED);
void retiraPagina(char* namePag, tWikiED);
void insereEditor(char* nome, tWikiED);
void retiraEditor(char* nameEdt, tWikiED);
void insereContribuicao(char* namePag, char* nameEdt, char* file, tWikiED);
void retiraContribuicao(char* namePag, char* nameEdt, char* file, tWikiED);
void insereLink(char* namePag1, char* namePag2, tWikiED);
void retiraLink(char* namePag1, char* namePag2, tWikiED);
int caminho(char* namePag1, char* namePag2, tWikiED);
void imprimePagina(char* namePag1, tWikiED);
void imprimeWiki(tWikiED);
void freeWiki(tWikiED);

#endif