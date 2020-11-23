#include <stdio.h>
#include <stdlib.h>
#include "listaPagina.h"
#include "listaEditor.h"
#include "wikiEd.h"
#include "ExceptionHandler.h"
struct wikiED{
    tListaPagina p;
    tListaEditor e;
    FILE *log, *wiki;
};

tWikiED inicializaWiked(){
    tWikiED new = malloc(sizeof(struct wikiED));

    new->p =  inicializaListaPagina();
    new->e = inicializaListaEditor();
    new->log = fopen("log.txt", "w");

    return new;
}
void inserePagina(char* nome, char* file, tWikiED w){
    tPagina Pagina = searchPagina(nome, w->p);
    if(Pagina == NULL){
        addPagina(nome, file, w->p);
    }
    else{
        err_P2(nome, w->log);
        fprintf(w->log, "Source: INSEREPAGINA %s %s\n\n", nome, file);
    }
}
void retiraPagina(char* namePag, tWikiED w){
    tPagina Pagina = removePagina(namePag, w->p);
    if(Pagina != NULL){
        removeAllLinkPag(Pagina, w->p); 
        freePagina(Pagina);
    }
    else{
        err_P1(namePag, w->log);
        fprintf(w->log, "Source: RETIRAPAGINA %s\n\n", namePag);
    }
}
void insereEditor(char* nome, tWikiED w){
    tEditor Editor = searchEditor(nome, w->e);
    if(Editor == NULL){
        addEditor(nome, w->e);
    }
    else{
        err_E2(nome, w->log);
        fprintf(w->log, "Source: INSEREEDITOR %s\n\n", nome);
    }
}
void retiraEditor(char* nameEdt, tWikiED w){
    tEditor Editor = removeEditor(nameEdt, w->e);
    if(Editor != NULL){
        removeAllContribuicoesEditor(nameEdt, w->p);
        freeEditor(Editor);
    }
    else{
        err_E1(nameEdt, w->log);
        fprintf(w->log, "Source: RETIRAPAGINA %s\n\n", nameEdt);
    }
}
void insereContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina Pagina = searchPagina(namePag, w->p);
    tEditor Editor = searchEditor(nameEdt, w->e);
    if(Pagina != NULL && Editor != NULL){
        addContribuicaoPagina(Editor, file, Pagina, w->log);
    }
    else{
        if(Pagina == NULL){
            err_P1(namePag, w->log);
            fprintf(w->log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", namePag, nameEdt, file);
        }
        if(Editor == NULL){
            err_E1(nameEdt, w->log);
            fprintf(w->log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", namePag, nameEdt, file);
        }
    }
}
void retiraContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina Pagina = searchPagina(namePag, w->p);
    tEditor Editor = searchEditor(nameEdt, w->e);
    if(Pagina != NULL && Editor != NULL){
        retiraContribuicaoPagina(Editor, file, Pagina, w->log);
    }
    else{
        if(Pagina == NULL){
            err_P1(namePag, w->log);
            fprintf(w->log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", namePag, nameEdt, file);
        }
        if(Editor == NULL){
            err_E1(nameEdt, w->log);
            fprintf(w->log, "Source: RETIRACONTRIBUICAO %s %s %s\n\n", namePag, nameEdt, file);
        }
    }
}
void insereLink(char* namePag1, char* namePag2, tWikiED w){
    tPagina Principal = searchPagina(namePag1, w->p), Secundaria = searchPagina(namePag2, w->p);
    if(Principal != NULL && Secundaria != NULL){
        addLinkPagina(Secundaria, Principal, w->log);
    }
    else{
        if(Principal == NULL){
            err_P1(namePag1, w->log);
            fprintf(w->log, "Source: INSERELINK %s %s\n\n", namePag1, namePag2);
        }
        if(Secundaria == NULL){
            err_P1(namePag2, w->log);
            fprintf(w->log, "Source: INSERELINK %s %s\n\n", namePag1, namePag2);
        }
    }
}
void retiraLink(char* namePag1, char* namePag2, tWikiED w){
    tPagina Principal = searchPagina(namePag1, w->p), Secundaria = searchPagina(namePag2, w->p);
    if(Principal != NULL && Secundaria != NULL){
        removeLinkPagina(Secundaria, Principal, w->log);
    }
    else{
        if(Principal == NULL){
            err_P1(namePag1, w->log);
            fprintf(w->log, "Source: RETIRALINK %s %s\n\n", namePag1, namePag2);
        }
        if(Secundaria == NULL){
            err_P1(namePag2, w->log);
            fprintf(w->log, "Source: RETIRALINK %s %s\n\n", namePag1, namePag2);
        }
    }
}
int caminho(char* namePag1, char* namePag2, tWikiED w){
    tPagina Origem = searchPagina(namePag1, w->p), Destino = searchPagina(namePag2, w->p);
    if(Origem != NULL && Destino != NULL){
        log4(caminhoExiste(Origem, Destino), namePag1, namePag2, w->log);
    }
    else{
        if(Origem == NULL){
            err_P1(namePag1, w->log);
            fprintf(w->log, "Source: CAMINHO %s %s\n\n", namePag1, namePag2);
        }
        if(Destino == NULL){
            err_P1(namePag2, w->log);
            fprintf(w->log, "Source: CAMINHO %s %s\n\n", namePag1, namePag2);
        }
    }
}
void imprimePagina(char* namePag1, tWikiED w){
    tPagina Pagina = searchPagina(namePag1, w->p);
    if(Pagina != NULL){
        printPagina(Pagina);
    }
    else{
        err_P1(namePag1, w->log);
        fprintf(w->log, "Source: IMPRIMEPAGINA %s\n\n", namePag1);
    }
}
void imprimeWiki(tWikiED w){
    printListaPagina(w->p);
}
void freeWiki(tWikiED w){
    freeListaPagina(w->p);
    freeListaEditor(w->e);
    fclose(w->log);
    free(w);
}