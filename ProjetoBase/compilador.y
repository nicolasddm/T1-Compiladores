%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimbolos.c"
#include "pilha.c"
#define TAM_COMANDO 64
#define TAM_ROTULO 16


char comando[TAM_COMANDO];
char rotulo[TAM_ROTULO];
char ident_proc_funcao[TAM_COMANDO];

int num_vars;
int tamAmem;
int nivelLexico = 0;
int deslocamento = 0;
int numTipo;
int tipo;
int elemTipo;
int elemAtribuicaoTipo;
int rotulosTam = -1;
int rotuloDesviaTrue;
int rotuloDesviaFalse;
int numParams = 0;

TabelaSimbolos *tabelaSimbolos;
Simbolo elemento;
Simbolo simboloElem;
Simbolo elemAtribuicao;
Pilha *pilhaExpressao;
Pilha *pilhaRotulos;
Pilha *pilhaDmem;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR ATRIBUICAO
%token WRITE READ LABEL TYPE ARRAY OF PROCEDURE
%token FUNCTION GOTO IF THEN ELSE WHILE DO IGUAL
%token DIFERENTE MENOR_IGUAL MAIOR_IGUAL MENOR
%token MAIOR MAIS MENOS OR MULTI DIV AND NOT NUMERO IDENT

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE
%%

programa    :{
             geraCodigo (NULL, "INPP");
             }
             PROGRAM IDENT
             ABRE_PARENTESES lista_idents FECHA_PARENTESES PONTO_E_VIRGULA
             bloco PONTO {
             imprimeTabela(tabelaSimbolos);
             geraCodigo (NULL, "PARA");
             }
;

bloco:
    parte_declara_vars
    
    parte_declara_algo_ou_nada
    
    comando_composto {
        imprimeTabela(tabelaSimbolos);
        int tamDmem = retiraElemPilha(pilhaDmem);
        retiraSimbolos(tabelaSimbolos, tamDmem);
        sprintf(comando, "DMEM %d", tamDmem);
        geraCodigo (NULL, comando);
    }
;

parte_declara_algo_ou_nada:  
    {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(comando, "DSVS R%02d", rotulosTam);
        geraCodigo(NULL, comando);
    }  parte_declara_funcoes_ou_procedimentos
    {
        if (pilhaRotulos->topo >= 0) {
            rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
            sprintf(comando, "R%02d:NADA", rotuloDesviaTrue);
            geraCodigo(NULL, comando);
        }
    }
    |
;

parte_declara_funcoes_ou_procedimentos: 
    declara_procedimento PONTO_E_VIRGULA
    // | declara_funcao PONTO_E_VIRGULA
;

declara_procedimento: 
    PROCEDURE {
        deslocamento = 0;
        nivelLexico++;
        rotulosTam++;
        sprintf(comando, "R%02d:ENPR %d", rotulosTam, nivelLexico);
        geraCodigo(NULL, comando);
        
    }
    IDENT { 
        strcpy(ident_proc_funcao, token);
        Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
        strcpy(atributos->categoria, "proc");
        atributos->nivelLexico = nivelLexico;
        atributos->rotulo = rotulosTam;
        insereSimbolo(tabelaSimbolos, ident_proc_funcao, atributos);

    } 
    tem_parametro_ou_nada PONTO_E_VIRGULA
    {

    }
    bloco
    {
        retiraSimbolos(tabelaSimbolos, numParams);
        rotuloDesviaFalse = retiraElemPilha(pilhaRotulos);
        rotuloDesviaTrue =  retiraElemPilha(pilhaRotulos);
        sprintf(comando, "RTPR %d, %d", nivelLexico, numParams);
        geraCodigo(NULL, comando);
        nivelLexico--;
    }
;    

tem_parametro_ou_nada: 
    // | ABRE_PARENTESES parametros FECHA_PARENTESES
;

parte_declara_vars:  var;

var         : { tamAmem = 0; } VAR declara_vars
            { /* AMEM */
                  sprintf(comando, "AMEM %d", tamAmem);
                  geraCodigo (NULL, comando);
                  insereElemPilha(pilhaDmem, tamAmem);
            }
            |
;

declara_vars: declara_vars declara_var
            | declara_var
;

declara_var : { }
              lista_id_var DOIS_PONTOS
              tipo
              { 
                imprimeTabela(tabelaSimbolos);
                atualizaTipo(tabelaSimbolos, numTipo, tamAmem);
              }
              PONTO_E_VIRGULA
;

tipo        : IDENT  
              {
                if (!strcmp(token, "integer")){
                    numTipo = 0;
                } else if(!strcmp(token, "boolean")) {
                    numTipo = 1;
                }
              }
;

lista_id_var: lista_id_var VIRGULA IDENT
            { /* insere �ltima vars na tabela de s�mbolos */
               Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
               strcpy(atributos->categoria, "vs");
               atributos->tipo = -1;
               atributos->nivelLexico = nivelLexico;
               atributos->deslocamento = deslocamento;

               insereSimbolo(tabelaSimbolos, token, atributos);
               deslocamento++;
               tamAmem++;

            }
            | IDENT { /* insere vars na tabela de s�mbolos */
               Atributos *atributos = (Atributos*) malloc(sizeof(Atributos));
               strcpy(atributos->categoria, "vs");
               atributos->tipo = -1;
               atributos->nivelLexico = nivelLexico;
               atributos->deslocamento = deslocamento;

               insereSimbolo(tabelaSimbolos, token, atributos);
               deslocamento++;
               tamAmem++;
            }
;

lista_idents: 
    lista_idents VIRGULA IDENT
    | IDENT
;


comando_composto: T_BEGIN comandos ponto_e_virgula_ou_vazio T_END

comandos: comandos PONTO_E_VIRGULA comando
    | comando
;

ponto_e_virgula_ou_vazio: 
    PONTO_E_VIRGULA
    | 

comando: variavel_atribuicao 
    {
        elemAtribuicao = simboloElem;
        elemAtribuicaoTipo = elemTipo;
    }
    atribuicao_ou_procedimento
    | comando_composto
    | comando_repetitivo
    | comando_condicional
    | read
    | write
; 

comando_condicional: 
    parte_if_then parte_else
    | parte_if_then %prec LOWER_THAN_ELSE
;

parte_if_then: 
    IF expressao 
    {
        if (retiraElemPilha(pilhaExpressao) != 1) {
            printf("A expressão da condicional deve sempre retornar booleano!");
        }
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(comando, "DSVF R%02d", rotulosTam);
        geraCodigo(NULL, comando);
    }
    THEN {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
    } comando {
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        rotuloDesviaFalse =  retiraElemPilha(pilhaRotulos);
        sprintf(comando, "DSVS R%02d", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
        sprintf(comando, "R%02d:NADA", rotuloDesviaFalse);
        geraCodigo(NULL, comando);
        insereElemPilha(pilhaRotulos, rotuloDesviaTrue);
    }
;

parte_else:
    ELSE comando {
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        sprintf(comando, "R%02d:NADA", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
    }

read: READ ABRE_PARENTESES le_idents FECHA_PARENTESES;

le_idents: 
    le_idents VIRGULA variavel
    {
        if (strcmp(elemento.atributos->categoria, "vs") == 0) {
            geraCodigo (NULL, "LEIT");
            sprintf(comando, "ARMZ %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Esta variável não é uma variável simples para realizar leitura!");
            exit(-1);
        }
    }
    | variavel
    {
        if (strcmp(elemento.atributos->categoria, "vs") == 0) {
            geraCodigo (NULL, "LEIT");
            sprintf(comando, "ARMZ %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Esta variável não é uma variável simples para realizar leitura!");
            exit(-1);
        }
    }
;

write: WRITE ABRE_PARENTESES escreve_expressoes FECHA_PARENTESES;

escreve_expressoes: 
    escreve_expressoes VIRGULA expressao
    {
        geraCodigo (NULL, "IMPR");
        retiraElemPilha(pilhaExpressao);
    }
    | expressao
    {
        geraCodigo (NULL, "IMPR");
        retiraElemPilha(pilhaExpressao);
    }
;



comando_repetitivo: 
    WHILE 
    {
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(rotulo, "R%02d:NADA", rotulosTam);
        geraCodigo(NULL, rotulo);
    }
    expressao 
    {
        if (retiraElemPilha(pilhaExpressao) != 1) {
            printf("Tipo da expressão condicional deve ser booleano\n");
        }
        rotulosTam++;
        insereElemPilha(pilhaRotulos, rotulosTam);
        sprintf(rotulo, "DSVF R%02d", rotulosTam);
        geraCodigo(NULL, rotulo);
    } 
    DO comando
    {
        rotuloDesviaFalse = retiraElemPilha(pilhaRotulos);
        rotuloDesviaTrue = retiraElemPilha(pilhaRotulos);
        sprintf(comando, "DSVS R%02d", rotuloDesviaTrue);
        geraCodigo(NULL, comando);
        sprintf(comando, "R%02d:NADA", rotuloDesviaFalse);
        geraCodigo(NULL, comando);
    } 
;

variavel_atribuicao: 
    IDENT {
        simboloElem = buscaSimbolo(tabelaSimbolos, token);
        elemTipo = simboloElem.atributos->tipo;
        imprimeSimbolo(simboloElem);
    }
;

atribuicao_ou_procedimento:
    atribuicao
    | chama_procedimento
;

chama_procedimento: 
    {
        if (strcmp(elemAtribuicao.atributos->categoria, "proc") != 0) {
            printf("A variável precisa ser um procedimento\n");
            exit(-1);
        }
        insereElemPilha(pilhaRotulos, elemAtribuicao.atributos->rotulo);
    }
    lista_expressoes_ou_nada
    {
        sprintf(comando, "CHPR R%02d, %d", retiraElemPilha(pilhaRotulos), nivelLexico);
        geraCodigo (NULL, comando);
    }
;

lista_expressoes_ou_nada: ;

atribuicao:
    ATRIBUICAO lista_expressoes
    {
        if (elemAtribuicaoTipo == retiraElemPilha(pilhaExpressao)) {
            sprintf(comando, "ARMZ %d, %d", elemAtribuicao.atributos->nivelLexico, elemAtribuicao.atributos->deslocamento);
            geraCodigo (NULL, comando);
        } else {
            printf("Tipo da variável de atribuição e valor a ser atribuido são diferentes!");
            exit(-1);
        }
    }
;

lista_expressoes:
    lista_expressoes expressao
    | expressao
;

expressao: 
    expressao_simples MENOR_IGUAL expressao_simples 
    { geraCodigo (NULL, "CMEG"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples MAIOR_IGUAL expressao_simples
    { geraCodigo (NULL, "CMAG"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples MENOR expressao_simples
    { geraCodigo (NULL, "CMME"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples MAIOR expressao_simples
    { geraCodigo (NULL, "CMMA"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples IGUAL expressao_simples
    { geraCodigo (NULL, "CMIG"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples DIFERENTE expressao_simples
    { geraCodigo (NULL, "CMDG"); verificaTiposReturnBool(pilhaExpressao); }
    | expressao_simples
;

expressao_simples:
    expressao_simples MAIS termo { geraCodigo (NULL, "SOMA");  verificaTipos(pilhaExpressao);  }
    | expressao_simples MENOS termo { geraCodigo (NULL, "SUBT");  verificaTipos(pilhaExpressao); }
    | expressao_simples OR termo { geraCodigo (NULL, "DISJ");  verificaTiposReturnBool(pilhaExpressao); } 
    | MAIS termo { verificaTipos(pilhaExpressao); }
    | MENOS termo { geraCodigo (NULL, "INVR");  verificaTipos(pilhaExpressao); }
    | termo
;

termo:
    termo MULTI fator { geraCodigo (NULL, "MULT");  verificaTipos(pilhaExpressao); }
    | termo DIV fator { geraCodigo (NULL, "DIVI");  verificaTipos(pilhaExpressao); }
    | termo AND fator { geraCodigo (NULL, "CONJ");  verificaTiposReturnBool(pilhaExpressao); }
    | fator
;


fator: 
    variavel 
    { 
        insereElemPilha(pilhaExpressao, elemTipo); 
        if (strcmp(elemento.atributos->categoria, "vs") == 0) {
            sprintf(comando, "CRVL %d, %d", elemento.atributos->nivelLexico, elemento.atributos->deslocamento);
        }
        geraCodigo (NULL, comando);
    }
    | NOT fator
    | numero { insereElemPilha(pilhaExpressao, 0); imprimePilha(pilhaExpressao); }
    | chamada_funcao { }
    | ABRE_PARENTESES expressao FECHA_PARENTESES
   
;

variavel: 
        IDENT {
            elemento = buscaSimbolo(tabelaSimbolos, token);
            imprimeSimbolo(elemento);
            elemTipo = elemento.atributos->tipo;
        }

numero: 
    NUMERO { sprintf(comando, "CRCT %s", token); geraCodigo(NULL, comando); }
;

chamada_funcao: ;


%%

int main (int argc, char** argv) {
    FILE* fp;
    extern FILE* yyin;

    if (argc<2 || argc>2) {
            printf("usage compilador <arq>a %d\n", argc);
            return(-1);
        }

    fp=fopen (argv[1], "r");
    if (fp == NULL) {
        printf("usage compilador <arq>b\n");
        return(-1);
    }


/* -------------------------------------------------------------------
 *  Inicia a Tabela de S�mbolos
 * ------------------------------------------------------------------- */
    tabelaSimbolos = initTabela();
    pilhaExpressao = initPilha();
    pilhaRotulos = initPilha();
    pilhaDmem = initPilha();

    yyin=fp;
    yyparse();

    return 0;
}
