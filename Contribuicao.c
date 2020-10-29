#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "Contribuicao.h"

struct contribuicao{
    char* file;
    int retirada;
    tEditor editor;
};

tContribuicao inicializaContribuicao(tEditor editor, char* file){
    tContribuicao new = malloc(sizeof(tContribuicao));
    new->editor = editor;
    new->retirada = 0;
    new->file = strdup(file);

    return new;
}
void retirarContribuicao(tContribuicao atual){
    atual->retirada = 1;
}
char* autor(tContribuicao atual){
    return returnNomeEditor(atual->editor);
}
char* returnNomeContribuicao(tContribuicao atual){
    return atual->file;
}
void printContribuicao(tContribuicao atual){
    printf("Nome do Editor: %s\t|\tNome do arquivo de contribuicao: %s ", returnNomeEditor(atual->editor), atual->file);
    if(atual->retirada)
        printf("<<retirada>>");
    printf("\n");
}
void freeContribuicao(tContribuicao atual){
    free(atual->file);
    free(atual);
}
