#include <stdio.h>
#include <stdlib.h>
void err_P1(char* PagName, FILE* log){
    fprintf(log, "Pagina: %s nao encontrada...\n", PagName);
}
void err_C1(char* ContribuicaoName, char* PagName, FILE* log){
    fprintf(log, "Contribuicao: %s nao encontrada na pagina %s...\n", ContribuicaoName, PagName);
}
void err_L1(char* LinkName, char* PagName, FILE* log){
    fprintf(log, "Link: %s nao encontrado na pagina %s...\n", LinkName, PagName);
}
void err_E1(char* EditorName, FILE* log){
    fprintf(log, "Editor(a): %s nao encontrado(a)...\n", EditorName);
}

void err_P2(char* PagName, FILE* log){
    fprintf(log, "Pagina: %s ja foi usada... Tente outro nome...\n", PagName);
}
void err_C2(char* ContribuicaoName, char* PagName, FILE* log){
    fprintf(log, "Contribuicao: Verificado repost da Contribuicao: %s na Pagina: %s... Cancelando inserçao\n", ContribuicaoName, PagName);
}
void err_L2(char* LinkName, char* PagName, FILE* log){
    fprintf(log, "Link: %s ja existe na pagina: %s, abortanto insercao...\n", LinkName, PagName);
}
void err_E2(char* EditorName, FILE* log){
    fprintf(log, "Editor(a): %s ja foi criado(a)... Tente outro nome...\n", EditorName);
}

void err_C3(char* EditorName, char* ContribuicaoName, char* AutorName, FILE* log){
    fprintf(log, "Nao Autorizado: Usuario: %s tentou retirar Contribuicao %s, cujo autor é %s\n", EditorName, ContribuicaoName, AutorName);
}

void log4(int caminho, char* Origem, char* Destino, FILE* log){
    if(caminho){
        fprintf(log,"Caminho: Existe caminho entre %s ate %s\n\n", Origem, Destino);
    }
    else{
        fprintf(log, "Caminho: Nao existe caminho entre %s ate %s\n\n", Origem, Destino);
    }
}
