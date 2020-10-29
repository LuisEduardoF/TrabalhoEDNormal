#ifndef EDITOR
#define EDITOR

typedef struct editor *tEditor;

tEditor inicializaEditor(char* name);
void printEditor(tEditor);
char* returnNomeEditor(tEditor e);
void freeEditor(tEditor);
#endif