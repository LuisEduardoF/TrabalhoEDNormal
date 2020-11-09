#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "Contribuicao.h"
#define MAX_TAM 200
struct contribuicao{
    char* file;
    int retirada;
    tEditor editor;
};

tContribuicao inicializaContribuicao(tEditor editor, char* file){
    tContribuicao new = malloc(sizeof(struct contribuicao));
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
void printDadosContribuicao(tContribuicao atual){
    printf("%s %s ", returnNomeEditor(atual->editor), atual->file);
    if(atual->retirada)
        printf("<<retirada>>");
    printf("\n");
}
void printContribuicao(tContribuicao atual){
    printf("-------- %s (%s) --------\n", atual->file, autor(atual));
    FILE* file = fopen(atual->file, "r");
    char lixo;
    while((lixo = fgetc(file)) != EOF){
        printf("%c",lixo);
    }
    printf("\n");
    fclose(file);
}
void freeContribuicao(tContribuicao atual){
    free(atual->file);
    free(atual);
}
