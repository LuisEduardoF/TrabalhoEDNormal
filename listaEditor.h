#ifndef LISTA_EDITOR
#define LISTA_EDITOR
#include "Editor.h"
typedef struct listaeditor *tListaEditor;

tListaEditor inicializaListaEditor();
void addEditor(char* name, tListaEditor Le);
tEditor removeEditor(char* name, tListaEditor Le);
tEditor searchEditor(char* name, tListaEditor Le);
void printListaEditor(tListaEditor Le);
void freeListaEditor(tListaEditor Le);

#endif