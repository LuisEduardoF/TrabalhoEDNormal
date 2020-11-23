#ifndef EXCEPTION_HANDLER
#define EXCEPTION_HANDLER
/*Tipos de Erro (Letra|TipoDeDado):
TipoDeDado:
    P - Pagina 
    C - Contribuicao
    L - Link
    E - Editor
Letras:
    1 - Inexistente ( Quando Nao achar algo igual )
    2 - Duplicata ( Quando já tiver algo igual )
    3 - Nao Autorizado ( Quando o usuario nao tem autorizacao )
    4 - Caminho ( Imprime o caminho no log )
*/
void err_P1(char* PagName, FILE* log);
void err_C1(char* ContribuicaoName, char* PagName, FILE* log);
void err_L1(char* LinkName, char* PagName, FILE* log);
void err_E1(char* EditorName, FILE* log);

void err_P2(char* PagName, FILE* log);
void err_C2(char* ContribuicaoName, char* PagName, FILE* log);
void err_L2(char* LinkName, char* PagName, FILE* log);
void err_E2(char* EditorName, FILE* log);

void err_C3(char* EditorName, char* ContribuicaoName, char* AutorName, FILE* log);

void log4(int caminho, char* Origem, char* Destino, FILE* log);
#endif