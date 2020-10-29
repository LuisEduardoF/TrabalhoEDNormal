#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "listaContribuicao.h"

struct editor{
    char* nome;
};

tEditor inicializaEditor(char* name){
    tEditor new = malloc(sizeof(tEditor));
    new->nome = strdup(name);
    return new;
}
void printEditor(tEditor e){
    printf("Nome do Editor: %s\n", e->nome);
}
char* returnNomeEditor(tEditor e){
    return e->nome;
}
void freeEditor(tEditor e){
    free(e->nome);
    free(e);
}