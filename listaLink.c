#include <stdio.h>
#include <stdlib.h>
#include "listaLink.h"

#define TRUE 1
#define FALSE 0

typedef struct linknode{
    tPagina pag;
    int passei;
    struct linknode *prox;
}*tLinkNode;
tLinkNode inicializaLinkNode(tPagina p){
    tLinkNode new = malloc(sizeof(tLinkNode));
    new->pag = p;
    new->passei = FALSE;
    new->prox = NULL;

    return new;
}
struct listalink{
    tLinkNode fst, end;
};
int isEmptyL(tListaLink l){
    return l->fst == NULL;
}
int ExistL(tListaLink l){
    return l != NULL;
}
tListaLink inicializaListaLink(){
    tListaLink new = malloc(sizeof(tListaLink));
    new->fst = new->end = NULL;
    return new;
}
void addLink(tPagina Pagina, tListaLink Ll){
    if(ExistL(Ll)){
        tLinkNode c = inicializaLinkNode(Pagina);
        if(isEmptyL(Ll)){
            Ll->fst = Ll->end = c;
        }
        else{
            Ll->end->prox = c;
            Ll->end = c;
        }
    }
}
tPagina removeLink(tPagina Pagina, tListaLink Ll){
    if(ExistL(Ll)){
        if(isEmptyL(Ll)){
            printf("Lista Vazia... Retornando NULL\n");
            return NULL;
        }
        else{
            tLinkNode p = Ll->fst, ant = NULL;
            tPagina aux;
            for(p = Ll->fst; p != NULL; p = p->prox){
                if(p->pag == Pagina){
                    break;
                }
                ant = p;
            }
            if(p == NULL){
                return NULL;
            }
            if(p == Ll->fst && p == Ll->end){
                Ll->fst = Ll->end;
            }
            else if(p == Ll->fst){
                Ll->fst = Ll->fst->prox;
            }
            else{
                ant->prox = p->prox;
            }
            aux = p->pag;
            free(p);
            return aux;
        }
    }
}
tPagina searchLink(tPagina name, tListaLink Ll);
void printListaLink(tListaLink Ll){
    if(ExistL(Ll)){
        if(!isEmptyL(Ll)){
            for(tLinkNode p = Ll->fst; p != NULL; p = p->prox){
                printf("%s ", returnNomePagina(p->pag));
            }
            printf("\n");
        }
    }
}
void freeListaLink(tListaLink Ll){
    if(ExistL(Ll)){
        if(!isEmptyL(Ll)){
            tLinkNode aux = NULL;
            for(tLinkNode p = Ll->fst; p != NULL; p = aux){
                aux = p->prox;
                free(p);
            }
        }
        free(Ll);
    }
}