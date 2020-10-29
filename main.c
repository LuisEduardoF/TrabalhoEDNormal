#include <stdio.h>
#include <string.h>
#include "wikiED.h"
#define TAM_MAX 200
void readInput(char* entrada, tWikiED wiked){

    FILE* file = fopen(entrada, "r");
    char opCode[TAM_MAX];
    while(fscanf(file, "%s", opCode) == 1){
        if(!strcmp(opCode,"INSEREPAGINA")){
            char PaginaNome[TAM_MAX], PaginaFile[TAM_MAX];
            fscanf(file, "%s %s%*c", PaginaNome, PaginaFile);
            inserePagina(PaginaNome, PaginaFile, wiked);
        }
        else if(!strcmp(opCode,"RETIRAPAGINA")){
            char PaginaNome[TAM_MAX];
            fscanf(file, "%s%*c", PaginaNome);
            retiraPagina(PaginaNome, wiked);
        }
        else if(!strcmp(opCode,"INSEREEDITOR")){
            char EditorNome[TAM_MAX];
            fscanf(file, "%s%*c", EditorNome);
            insereEditor(EditorNome, wiked);
        }
        else if(!strcmp(opCode,"RETIRAEDITOR")){
            char EditorNome[TAM_MAX];
            fscanf(file, "%s%*c", EditorNome);
            retiraEditor(EditorNome, wiked);
        }
        else if(!strcmp(opCode,"INSERECONTRIBUICAO")){
            char PaginaNome[TAM_MAX], EditorNome[TAM_MAX], ColabFile[TAM_MAX];
            fscanf(file, "%s %s %s%*c", PaginaNome, EditorNome, ColabFile);
            insereContribuicao(PaginaNome, EditorNome, ColabFile, wiked);
        }
        else if(!strcmp(opCode,"RETIRACONTRIBUICAO")){
            char PaginaNome[TAM_MAX], EditorNome[TAM_MAX], ColabFile[TAM_MAX];
            fscanf(file, "%s %s %s%*c", PaginaNome, EditorNome, ColabFile);
            retiraContribuicao(PaginaNome, EditorNome, ColabFile, wiked);
        }
        else if(!strcmp(opCode,"INSERELINK")){
            char PaginaPrincipal[TAM_MAX], PaginaSecundaria[TAM_MAX];
            fscanf(file, "%s %s%*c", PaginaPrincipal, PaginaSecundaria);
            //insereLink(PaginaPrincipal, PaginaSecundaria, wiked);
        }
        else if(!strcmp(opCode,"RETIRALINK")){
            char PaginaPrincipal[TAM_MAX], PaginaSecundaria[TAM_MAX];
            fscanf(file, "%s %s%*c", PaginaPrincipal, PaginaSecundaria);
        }
        else if(!strcmp(opCode,"CAMINHO")){
            char PaginaInicial[TAM_MAX], PaginaFinal[TAM_MAX];
            fscanf(file, "%s %s%*c", PaginaInicial, PaginaFinal);
        }
        else if(!strcmp(opCode,"IMPRIMEPAGINA")){
            char PaginaNome[TAM_MAX];
            fscanf(file, "%s%*c", PaginaNome);
            imprimePagina(PaginaNome, wiked);
        }
        else if(!strcmp(opCode,"IMPRIMEWIKED")){
            imprimeWiki(wiked);
        }
        else{
            freeWiki(wiked);
            break;
        }
    }
    fclose(file);
}
int main(int argc, char* argv[]){
    tWikiED wiked = inicializaWiked();
    readInput(argv[1], wiked);
    /*
    inserePagina("Fisica", "fisica.txt", wiked);  inserePagina("Artes", "artes.txt", wiked); inserePagina("UFES", "ufes.txt", wiked);
    //retiraPagina("Psicologia", wiked);
    insereEditor("Pedro", wiked);
    insereEditor("Maria", wiked);
    insereEditor("Joao", wiked);
    insereEditor("Ana", wiked);
    insereEditor("Edu", wiked);
    retiraEditor("Edu", wiked);

    insereContribuicao("Fisica", "Pedro", "c1.txt", wiked);
    insereContribuicao("Fisica", "Maria", "c2.txt", wiked);
    insereContribuicao("Fisica", "Pedro", "c3.txt", wiked);
    insereContribuicao("Artes", "Maria", "c4.txt", wiked);
    insereContribuicao("Artes", "Ana", "c5.txt", wiked);
    retiraContribuicao("Artes", "Ana", "c5.txt", wiked);
    retiraEditor("Maria", wiked);
    imprimeWiki(wiked);
    freeWiki(wiked);
    */
    return 0;
}