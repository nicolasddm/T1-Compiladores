

%{
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include "compilador.h"
#include "tabelaSimbolos.c"
#define TAM_COMANDO 64


int num_vars;
int tamAmem;
char comando[TAM_COMANDO];
int nivelLexico = 0;
int deslocamento = 0;
int numTipo;
TabelaSimbolos *tabelaSimbolos;

%}

%token PROGRAM ABRE_PARENTESES FECHA_PARENTESES
%token VIRGULA PONTO_E_VIRGULA DOIS_PONTOS PONTO
%token T_BEGIN T_END VAR IDENT ATRIBUICAO
%token WRITE READ LABEL TYPE ARRAY OF PROCEDURE
%token FUNCTION GOTO IF THEN ELSE WHILE DO IGUAL
%token DIFERENTE MENOR_IGUAL MAIOR_IGUAL MENOR
%token MAIOR MAIS MENOS OR MULTI DIV AND NOT NUMERO


%%

programa    :{
             tabelaSimbolos = initTabela();
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
        
    }
    atribuicao
    | PONTO_E_VIRGULA
; 

variavel_atribuicao: 
    IDENT {
       Simbolo simbolo = buscaSimbolo(tabelaSimbolos, token);
       printf("simbolo->ident: %s\n", simbolo.ident);
       imprimeSimbolo(simbolo);
    }
;

atribuicao:
    ATRIBUICAO lista_expressoes
    {

    }
;

lista_expressoes:
    lista_expressoes expressao
    | expressao
;

expressao: expressao_simples relacao expressao_simples { }
    | expressao_simples
;

relacao:
    MENOR_IGUAL
    { geraCodigo (NULL, "CMEG"); }
    | MAIOR_IGUAL 
    { geraCodigo (NULL, "CMAG"); }
    | MENOR 
    { geraCodigo (NULL, "CMME"); }
    | MAIOR 
    { geraCodigo (NULL, "CMMA"); }
    | IGUAL 
    { geraCodigo (NULL, "CMIG"); }
    | DIFERENTE 
    { geraCodigo (NULL, "CMDG"); }
;

expressao_simples:
    expressao_simples MAIS termo { geraCodigo (NULL, "SOMA"); }
    | expressao_simples MENOS termo { geraCodigo (NULL, "SUBT"); }
    | expressao_simples OR termo { geraCodigo (NULL, "DISJ"); } 
    | MAIS { } termo { }
    | MENOS { } termo { geraCodigo (NULL, "INVR");  }
    | termo { }
;

termo:
    termo MULTI fator { geraCodigo (NULL, "MULT"); }
    | termo DIV fator { geraCodigo (NULL, "DIVI"); }
    | termo AND fator { geraCodigo (NULL, "CONJ"); }
    | fator { }
    
   
;

fator: 
    NOT fator
    | variavel
    | numero
    | chamada_funcao
    | expressao
   
;

variavel: IDENT
        | IDENT lista_expressoes

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

   yyin=fp;
   yyparse();

   return 0;
}
