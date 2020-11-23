#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Editor.h"
#include "listaEditor.h"
typedef struct node{
    tEditor e;
    struct node *prox;
}*tNode;
tNode inicializaNodeEditor(char* nome){
    tNode new = malloc(sizeof(struct node));
    new->e = inicializaEditor(nome);
    new->prox = NULL;
    return new;
}
void freeNodeEditor(tNode n){
    freeEditor(n->e);
    free(n);
}
struct listaeditor{
    tNode fst, end;
};
int isEmptyE(tListaEditor e){
    return e->fst == NULL;
}
int ExistE(tListaEditor e){
    return e != NULL;
}
tListaEditor inicializaListaEditor(){
    tListaEditor new = malloc(sizeof(struct listaeditor));
    new->fst = new->end = NULL;
    return new;
}
tEditor removeEditor(char* name, tListaEditor Le){
     if(ExistE(Le)){
        if(isEmptyE(Le)){
            return NULL;
        }
        else{
            tNode p = Le->fst, ant = NULL;
            tEditor aux;
            for(p = Le->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomeEditor(p->e), name)){
                    break;
                }
                ant = p;
            }
            if(p == NULL){
                return NULL;
            }
            if(p == Le->fst && p == Le->end){
                Le->fst = Le->end = NULL;
            }
            else if(p == Le->fst){
                Le->fst = Le->fst->prox;
            }
            else if(p == Le->end){
                Le->end = ant;
                Le->end->prox = NULL;
            }
            else{
                ant->prox = p->prox;
            }
            aux = p->e;
            free(p);
            return aux;
        }
    }
}
tEditor searchEditor(char* name, tListaEditor Le){
    if(ExistE(Le)){
        if(isEmptyE(Le)){
            return NULL;
        }
        else{
            tNode p = Le->fst;
            for(p = Le->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomeEditor(p->e), name)){
                    return p->e;
                }
            }
            return NULL;
        }
    }
}
void addEditor(char* name, tListaEditor Le){
    if(ExistE(Le)){
        tNode c = inicializaNodeEditor(name);
        if(isEmptyE(Le)){
            Le->fst = Le->end = c;
        }
        else{
            Le->end->prox = c;
            Le->end = c;
        }
    }
}
void printListaEditor(tListaEditor Le){
    for(tNode p = Le->fst; p != NULL; p = p->prox){
        printEditor(p->e);
    }
}
void freeListaEditor(tListaEditor Le){
    if(ExistE(Le)){
        if(!isEmptyE(Le)){
            tNode aux = NULL;
            for(tNode p = Le->fst; p != NULL; p = aux){
                aux = p->prox;
                freeNodeEditor(p);
            }
        }
        free(Le);
    }
}
