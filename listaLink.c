#include <stdio.h>
#include <stdlib.h>
#include "listaLink.h"


typedef struct linknode{
    tPagina pag;
    struct linknode *prox;
}*tLinkNode;
tLinkNode inicializaLinkNode(tPagina p){
    tLinkNode new = malloc(sizeof(struct linknode));
    new->pag = p;
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
    tListaLink new = malloc(sizeof(struct listalink));
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
                Ll->fst = Ll->end = NULL;
            }
            else if(p == Ll->fst){
                Ll->fst = Ll->fst->prox;
            }
            else if(p == Ll->end){
                Ll->end = ant;
                Ll->end->prox = NULL;
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
tPagina searchLink(tPagina Pag, tListaLink Ll){
    if(ExistL(Ll)){
        if(isEmptyL(Ll)){
            printf("Lista Vazia... Retornando NULL\n");
            return NULL;
        }
        else{
            tLinkNode p = Ll->fst;
            for(p = Ll->fst; p != NULL; p = p->prox){
                if(p->pag == Pag){
                    return p->pag;
                }
            }
            return NULL;
        }
    }
}
int caminhoUTIL(tPagina Origem, tPagina Destino, tListaLink linkAux){
    printf("Pagina origem: %s\n", returnNomePagina(Origem));
    //Verifica se A página já foi visitada
    if(searchLink(Origem, linkAux) != NULL){
        return 0;
    }
    //Se a página não foi visitada ainda, adiciona ela na lista
    else{
        addLink(Origem, linkAux);
    }
    //Verifica se a página atual tem a página destino nos links dela ou se ela própria já é o destino
    if(searchLink(Destino, returnLinkPagina(Origem)) != NULL || Origem == Destino){
        return 1;
    }
    //Se não tiver, ele vai entrar em todos os links da página origem e fazer o mesmo processo
    else{
        tListaLink l = returnLinkPagina(Origem);
        for(tLinkNode p = l->fst; p != NULL; p = p->prox){
            if(caminhoUTIL(p->pag, Destino, linkAux)){
                return 1;
            }
        }
    }
    return 0;
}
int caminhoLink(tPagina Origem, tPagina Destino){
    int ExisteCaminho = 0;
    tListaLink linkAux = inicializaListaLink();
    ExisteCaminho = caminhoUTIL(Origem, Destino, linkAux);
    freeListaLink(linkAux);

    return ExisteCaminho;
}
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