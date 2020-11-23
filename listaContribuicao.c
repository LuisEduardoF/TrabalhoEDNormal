#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Contribuicao.h"
#include "listaContribuicao.h"
typedef struct node{
    tContribuicao c;
    struct node *prox;
}*tNode;
tNode inicializaNodeContribuicao(tEditor editor, char* file){
    tNode new = malloc(sizeof(struct node));
    new->c = inicializaContribuicao(editor, file);
    new->prox = NULL;

    return new;
}
void freeNodeContribuicao(tNode n){
    freeContribuicao(n->c);
    free(n);
}
struct listacontribuicao{
    tNode fst, end;
};
int isEmptyC(tListaContribuicao c){
    return c->fst == NULL;
}
int ExistC(tListaContribuicao c){
    return c != NULL;
}
tListaContribuicao inicializaListaContribuicao(){
    tListaContribuicao new = malloc(sizeof(struct listacontribuicao));
    new->fst = new->end = NULL;
    return new;
}
void addContribuicao(tEditor editor, char* file, tListaContribuicao Lc){
    if(ExistC(Lc)){
        tNode c = inicializaNodeContribuicao(editor, file);
        if(isEmptyC(Lc)){
            Lc->fst = Lc->end = c;
        }
        else{
            Lc->end->prox = c;
            Lc->end = c;
            c->prox = NULL;
        }
    }
}
tContribuicao searchContribuicao(char* file,  tListaContribuicao Lc){
    if(ExistC(Lc)){
        if(isEmptyC(Lc)){
            return NULL;
        }
        else{
            tNode p = Lc->fst;
            for(p = Lc->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomeContribuicao(p->c), file)){
                    return p->c;
                }
            }
            return NULL;
        }
    }
}
tContribuicao removeContribuicaoEditor(char* EditorName,  tListaContribuicao Lc){
    if(ExistC(Lc)){
        if(isEmptyC(Lc)){
            return NULL;
        }
        else{
            tNode p = Lc->fst, ant = NULL;
            tContribuicao aux;
            for(p = Lc->fst; p != NULL; p = p->prox){
                if(!strcmp(autor(p->c), EditorName)){
                    break;
                }
                ant = p;
            }
            if(p == NULL){
                return NULL;
            }
            if(p == Lc->fst && p == Lc->end){
                Lc->fst = Lc->end = NULL;
            }
            else if(p == Lc->fst){
                Lc->fst = Lc->fst->prox;
            }
            else if(p == Lc->end){
                Lc->end = ant;
                Lc->end->prox = NULL;
            }
            else{
                ant->prox = p->prox;
            }
            aux = p->c;
            free(p);
            return aux;
        }
    }
}
tContribuicao removeContribuicao(char* file, tListaContribuicao Lc){
    if(ExistC(Lc)){
        if(isEmptyC(Lc)){
            return NULL;
        }
        else{
            tNode p = Lc->fst;
            for(p = Lc->fst; p != NULL; p = p->prox){
                if(!strcmp(returnNomeContribuicao(p->c), file)){
                    return p->c;
                }
            }
            return NULL;
        }
    }
}
void printListaContribuicaoHistorico(tListaContribuicao Lc, FILE* pagFile){
    if(ExistC(Lc)){
        if(!isEmptyC(Lc)){
            for(tNode p = Lc->fst; p != NULL; p = p->prox){
                printDadosContribuicao(p->c, pagFile);
            }
        }
    }
}
void printListaContribuicao(tListaContribuicao Lc, FILE* pagFile){
    if(ExistC(Lc)){
        if(!isEmptyC(Lc)){
            for(tNode p = Lc->fst; p != NULL; p = p->prox){
                printContribuicao(p->c, pagFile);
            }
        }
    }
}
void freeListaContribuicao(tListaContribuicao Lc){
    if(ExistC(Lc)){
        if(!isEmptyC(Lc)){
            tNode aux = NULL;
            for(tNode p = Lc->fst; p != NULL; p = aux){
                aux = p->prox;
                freeNodeContribuicao(p);
            }
        }
        free(Lc);
    }
}