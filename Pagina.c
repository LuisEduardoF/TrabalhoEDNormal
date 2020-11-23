#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPagina.h"
#include "listaContribuicao.h"
#include "listaLink.h"
#include "ExceptionHandler.h"

struct pagina{
    tListaLink l; 
    tListaContribuicao c;
    char *nome, *file;  
};

tPagina inicializaPagina(char* name, char* file){
    tPagina new = malloc(sizeof(struct pagina));
    new->c = inicializaListaContribuicao();
    new->file = strdup(file);
    new->nome = strdup(name);
    new->l = inicializaListaLink();

    return new;
}
void addContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual, FILE* log){
    tContribuicao Contrib = searchContribuicao(ContribuicaoFile, atual->c);
    if(Contrib == NULL)
        addContribuicao(Editor, ContribuicaoFile, atual->c);
    else{
        err_C2(ContribuicaoFile, atual->nome, log);
        fprintf(log, "Source: INSERECONTRIBUICAO %s %s %s\n\n", atual->nome, returnNomeEditor(Editor), ContribuicaoFile);
    }
    
}
void retiraContribuicaoPagina(void* Editor, char* ContribuicaoFile, tPagina atual, FILE* log){
    tContribuicao Contribuicao = searchContribuicao(ContribuicaoFile, atual->c);
    if(Contribuicao != NULL){
        if(!strcmp(autor(Contribuicao), returnNomeEditor(Editor))){
            retirarContribuicao(Contribuicao);
        }
        else{
            err_C3(returnNomeEditor(Editor), ContribuicaoFile, autor(Contribuicao), log);
            fprintf(log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", atual->nome, returnNomeEditor(Editor), ContribuicaoFile);
        }
    }
    else{
        err_C1(ContribuicaoFile, atual->nome, log);
        fprintf(log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", atual->nome, returnNomeEditor(Editor), ContribuicaoFile);
    }
}
int excludeContribuicoesEditorPagina(char* Editor, tPagina atual){
    tContribuicao Contribuicao = removeContribuicaoEditor(Editor, atual->c);
    if(Contribuicao != NULL){
        freeContribuicao(Contribuicao);
        return 0;
    }
    else{
        return 1;
    }
}
void addLinkPagina(tPagina secundaria, tPagina principal, FILE* log){
    tPagina PaginaLink = searchLink(secundaria, principal->l);

    if(PaginaLink == NULL){
        addLink(secundaria, principal->l);
    }
    else{
        err_L2(PaginaLink->nome, principal->nome, log);
        fprintf(log, "Source: INSERELINK %s %s\n\n", principal->nome, secundaria->nome);
    }
}
tPagina excludeLinkPagina(tPagina secundaria, tPagina principal){
    if(secundaria != NULL && principal != NULL){
        return removeLink(secundaria, principal->l);
    }
}
void removeLinkPagina(tPagina secundaria, tPagina principal, FILE* log){
    tPagina PaginaLink = searchLink(secundaria, principal->l);
    if(PaginaLink != NULL){
        removeLink(secundaria, principal->l);
    }
    else{
        err_L1(secundaria->nome, principal->nome, log);
        fprintf(log, "Source: RETIRACONTRIBUICAO %s %s\n\n", principal->nome, secundaria->nome);
    }
}
int searchCaminhoLinks(tPagina Origem, tPagina Destino){
    return caminhoLink(Origem, Destino);
}
void printPagina(tPagina p){
    FILE* pagFile = fopen(p->file, "w");

    fprintf(pagFile, "Nome da Página: %s | Arquivo: %s\n", p->nome, p->file);

    fprintf(pagFile, "--> Historico de contribuicoes\n");
    printListaContribuicaoHistorico(p->c, pagFile);

    fprintf(pagFile, "--> Links\n");
    printListaLink(p->l, pagFile);

    fprintf(pagFile, "--> Textos\n");
    printListaContribuicao(p->c, pagFile);

    fclose(pagFile);
}
char* returnNomePagina(tPagina p){
    return p->nome;
}
char* returnFilePagina(tPagina p){
    return p->file;
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