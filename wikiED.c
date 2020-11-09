#include <stdio.h>
#include <stdlib.h>
#include "listaPagina.h"
#include "listaEditor.h"
#include "wikiEd.h"
struct wikiED{
    tListaPagina p;
    tListaEditor e;
};

tWikiED inicializaWiked(){
    tWikiED new = malloc(sizeof(struct wikiED));
    new->p =  inicializaListaPagina();
    new->e = inicializaListaEditor();

    return new;
}
void inserePagina(char* nome, char* file, tWikiED w){
    addPagina(nome, file, w->p);
}
void retiraPagina(char* namePag, tWikiED w){
    tPagina Pagina = removePagina(namePag, w->p);
    if(Pagina != NULL){
        removeAllLinkPag(Pagina, w->p); 
        freePagina(Pagina);
    }
}
void insereEditor(char* nome, tWikiED w){
    addEditor(nome, w->e);
}
void retiraEditor(char* nameEdt, tWikiED w){
    tEditor Editor = removeEditor(nameEdt, w->e);
    if(Editor != NULL){
        removeAllContribuicoesEditor(nameEdt, w->p);
        freeEditor(Editor);
    }  
}
void insereContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina Pagina = searchPagina(namePag, w->p);
    tEditor Editor = searchEditor(nameEdt, w->e);
    if(Pagina != NULL && Editor != NULL){
        addContribuicaoPagina(Editor, file, Pagina);
    }
    else{
        if(Pagina == NULL){
            printf("Pagina não encontrada ");
        }
        if(Editor == NULL){
            printf("Editor não encontrado ");
        }
        printf("\n");
    }
}
void retiraContribuicao(char* namePag, char* nameEdt, char* file, tWikiED w){
    tPagina Pagina = searchPagina(namePag, w->p);
    tEditor Editor = searchEditor(nameEdt, w->e);
    if(Pagina != NULL && Editor != NULL){
        retiraContribuicaoPagina(Editor, file, Pagina);
    }
}
void insereLink(char* namePag1, char* namePag2, tWikiED w){
    tPagina Principal = searchPagina(namePag1, w->p), Secundaria = searchPagina(namePag2, w->p);
    if(Principal != NULL && Secundaria != NULL){
        addLinkPagina(Secundaria, Principal);
    }
}
void retiraLink(char* namePag1, char* namePag2, tWikiED w){
    tPagina Principal = searchPagina(namePag1, w->p), Secundaria = searchPagina(namePag2, w->p);
    if(Principal != NULL && Secundaria != NULL){
        removeLinkPagina(Secundaria, Principal);
    }
}
int caminho(char* namePag1, char* namePag2, tWikiED w){
    tPagina Origem = searchPagina(namePag1, w->p), Destino = searchPagina(namePag2, w->p);
    if(Origem != NULL && Destino != NULL){
        caminhoExiste(Origem, Destino);
    }
}
void imprimePagina(char* namePag1, tWikiED w){
    tPagina Pagina = searchPagina(namePag1, w->p);
    if(Pagina != NULL){
        printPagina(Pagina);
    }
}
void imprimeWiki(tWikiED w){
    printListaPagina(w->p);
}
void freeWiki(tWikiED w){
    freeListaPagina(w->p);
    freeListaEditor(w->e);
    free(w);
}