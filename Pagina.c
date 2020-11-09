#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPagina.h"
#include "listaContribuicao.h"
#include "listaLink.h"

struct pagina{
    
    tListaLink l;
    char *nome, *file;
    tListaContribuicao c;
    
};

tPagina inicializaPagina(char* name, char* file){
    tPagina new = malloc(sizeof(struct pagina));
    new->c = inicializaListaContribuicao();
    new->file = strdup(file);
    new->nome = strdup(name);
    new->l = inicializaListaLink();

    return new;
}
void addContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual){
    addContribuicao(Editor, ContribuicaoFile, atual->c);
}
void retiraContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual){
    tContribuicao Contribuicao = searchContribuicao(ContribuicaoFile, atual->c);
    if(Contribuicao != NULL){
        if(!strcmp(autor(Contribuicao), returnNomeEditor(Editor))){
            retirarContribuicao(Contribuicao);
        }
    }
}
int removeContribuicoesEditorPagina(char* Editor, tPagina atual){
    tContribuicao Contribuicao = removeContribuicaoEditor(Editor, atual->c);
    if(Contribuicao != NULL){
        freeContribuicao(Contribuicao);
        return 0;
    }
    else{
        return 1;
    }
}
void addLinkPagina(tPagina secundaria, tPagina principal){
    if(secundaria != NULL && principal != NULL){
        addLink(secundaria, principal->l);
    }
}
int removeLinkPagina(tPagina secundaria, tPagina principal){
    if(secundaria != NULL && principal != NULL){
        if(removeLink(secundaria, principal->l) != NULL)
            return 0;
        else
            return 1;
    }
}
int searchCaminhoLinks(tPagina Origem, tPagina Destino){
    printf("Existe caminho entre %s para %s: %d\n", returnNomePagina(Origem), returnNomePagina(Destino), caminhoLink(Origem, Destino));
}
void printPagina(tPagina p){
    printf("Nome da Página: %s | Arquivo: %s\n", p->nome, p->file);
    printf("--> Historico de contribuicoes\n");
    printListaContribuicaoHistorico(p->c);
    printf("--> Links\n");
    printListaLink(p->l);
    printf("--> Textos\n");
    printListaContribuicao(p->c);
}
char* returnNomePagina(tPagina p){
    return p->nome;
}
void* returnLinkPagina(tPagina p){
    return p->l;
}
void freePagina(tPagina p){
    free(p->nome);
    free(p->file);
    freeListaContribuicao(p->c);
    freeListaLink(p->l);
    free(p);
}