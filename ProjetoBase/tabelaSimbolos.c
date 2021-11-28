#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 128
#define TAM_TABELA 25

/* Categorias: 
    Variável Simples: {nível léxico, deslocamento, tipo} -> var
    Procedimento: {}
    Função: {}
    Parâmetro Formal: {}
    Rótulo: {}
 */

typedef struct {
	char ident[TAM_MAX];
    int categoria;
    int nivelLexico;
    int tipo;
    int deslocamento;
} Simbolo;

typedef struct {
    Simbolo *simbolos;
    int topo;
    int tamanho;
} TabelaSimbolos;

/*
# Init() -> retorna tabela de simbolos inicial alocada
# Insere(ident, atributos) -> insere o identificador indicado na TS, assim como seus atributos;
# Busca(ident) -> Retorna a entrada (os atributos) da TS associados ao ident procurado.
# Retira(n) Retira às últimas n entradas da TS.
# Imprime(TS) -> imprime tabela de símbolos.
*/

TabelaSimbolos* init() {
    TabelaSimbolos *tabelaSimbolos = (TabelaSimbolos *) malloc(sizeof(TabelaSimbolos));

    tabelaSimbolos->topo = -1;
    tabelaSimbolos->tamanho = TAM_TABELA;
    Simbolo *simbolos = (Simbolo*) malloc(TAM_TABELA * sizeof(Simbolo));
    tabelaSimbolos->simbolos = simbolos;
    
    return tabelaSimbolos;
}

Simbolo buscaSimbolo(char ident) {

}

void insereSimbolo(char ident, int nivelLexico, int tipo, int deslocamento, int categoria) {

}

void retiraSimbolos(int n) {

}

void imprimeTabela(TabelaSimbolos ts) {

}

void imprimeSimbolo(Simbolo simbolo) {

}

void atualizaTipo() {
    
}