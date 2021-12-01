

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

TabelaSimbolos *tabelaSimbolos;
Simbolo elemento;
Simbolo simboloElem;
Simbolo elemAtribuicao;
Pilha *pilhaExpressao;
Pilha *pilhaRotulos;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR ATRIBUICAO
%token WRITE READ LABEL TYPE ARRAY OF PROCEDURE
%token FUNCTION GOTO IF THEN ELSE WHILE DO IGUAL
%token DIFERENTE MENOR_IGUAL MAIOR_IGUAL MENOR
%token MAIOR MAIS MENOS OR MULTI DIV AND NOT NUMERO IDENT


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

bloco       :
              parte_declara_vars
              {
              }

              comando_composto {
                  imprimeTabela(tabelaSimbolos);
                  retiraSimbolos(tabelaSimbolos, tamAmem);
                  sprintf(comando, "DMEM %d", tamAmem);
                  geraCodigo (NULL, comando);
              }
              ;




parte_declara_vars:  var
;


var         : { tamAmem = 0; } VAR declara_vars
            { /* AMEM */
                  sprintf(comando, "AMEM %d", tamAmem);
                  geraCodigo (NULL, comando);
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

lista_idents: lista_idents VIRGULA IDENT
            | IDENT
;


comando_composto: T_BEGIN comandos PONTO_E_VIRGULA T_END

comandos: comandos PONTO_E_VIRGULA comando
    | comando 
    
;

comando: variavel_atribuicao 
    {
        elemAtribuicao = simboloElem;
        elemAtribuicaoTipo = elemTipo;
    }
    atribuicao
    | PONTO_E_VIRGULA
    | comando_repetitivo
    | read
    | write
; 

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
    DO comando_composto
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

    yyin=fp;
    yyparse();

    return 0;
}
