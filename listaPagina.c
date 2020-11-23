#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaPagina.h"
typedef struct node{
    tPagina p;
    struct node *prox;
}*tNode;
tNode inicializaNodePagina(char* nome, char* file){
    tNode new = malloc(sizeof(struct node));
    new->p = inicializaPagina(nome, file);
    new->prox = NULL;
    return new;
}
void freeNodePagina(tNode n){
    freePagina(n->p);
    free(n);
}
struct listapagina{
    tNode fst, end;
};
int isEmptyP(tListaPagina p){
    return p->fst == NULL;
}
int ExistP(tListaPagina p){
    return p != NULL;
}
tListaPagina inicializaListaPagina(){
    tListaPagina new = malloc(sizeof(struct listapagina));
    new->fst = new->end = NULL;
    return new;
}
tPagina removePagina(char* name, tListaPagina Lp){
     if(ExistP(Lp)){
        if(isEmptyP(Lp)){
            return NULL;
        }
        else{
            tNode p = Lp->fst, ant = NULL;
            tPagina aux;
            for(p = Lp->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomePagina(p->p), name)){
                    break;
                }
                ant = p;
            }
            if(p == NULL){
                return NULL;
            }
            if(p == Lp->fst && p == Lp->end){
                Lp->fst = Lp->end = NULL;
            }
            else if(p == Lp->fst){
                Lp->fst = Lp->fst->prox;
            }
            else if(p == Lp->end){
                Lp->end = ant;
                Lp->end->prox = NULL;
            }
            else{
                ant->prox = p->prox;
            }
            aux = p->p;
            free(p);
            return aux;
        }
    }
}
void removeAllLinkPag(tPagina Pagina, tListaPagina Lp){
    for(tNode p = Lp->fst; p != NULL; p = p->prox){
        while(1){
            if(excludeLinkPagina(Pagina, p->p) == NULL)
                break;
        }
    }
}
void removeAllContribuicoesEditor(char* nameEditor, tListaPagina Lp){
    for(tNode p = Lp->fst; p != NULL; p = p->prox){
        while(1){
            if(excludeContribuicoesEditorPagina(nameEditor, p->p))
                break;
        }
    }
}
tPagina searchPagina(char* name, tListaPagina Lp){
    if(ExistP(Lp)){
        if(isEmptyP(Lp)){
            return NULL;
        }
        else{
            tNode p = Lp->fst;
            for(p = Lp->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomePagina(p->p), name)){
                    return p->p;
                }
            }
            return NULL;
        }
    }
}
int caminhoExiste(tPagina Origem, tPagina Destino){
    searchCaminhoLinks(Origem, Destino);
}
void addPagina(char* name, char* file, tListaPagina Lp){
    if(ExistP(Lp)){
        tNode c = inicializaNodePagina(name, file);
        if(isEmptyP(Lp)){
            Lp->fst = Lp->end = c;
        }
        else{
            Lp->end->prox = c;
            Lp->end = c;
        }
    }
}
void printListaPagina(tListaPagina Lp){
    for(tNode p = Lp->fst; p != NULL; p = p->prox){
        printPagina(p->p);
    }
}
void freeListaPagina(tListaPagina Lp){
    if(ExistP(Lp)){
        if(!isEmptyP(Lp)){
            tNode aux = NULL;
            for(tNode p = Lp->fst; p != NULL; p = aux){
                aux = p->prox;
                freeNodePagina(p);
            }
        }
        free(Lp);
    }
}
