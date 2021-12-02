#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 128
#define TAM_TABELA 64

/* Categorias: 
    0: Variável Simples: {nível léxico, deslocamento, tipo} -> var
    1: Procedimento: {}
    2: Função: {}
    3: Parâmetro Formal: {}
    4: Rótulo: {}
*/


typedef struct {
    char categoria[TAM_MAX];
    int tipo;
    int nivelLexico;
    int deslocamento;
    int rotulo;
} Atributos;

typedef struct {
	char ident[TAM_MAX];
    Atributos *atributos;
} Simbolo;

typedef struct {
    Simbolo *simbolos; // simbolos[0..topo]
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

TabelaSimbolos* initTabela() {
    TabelaSimbolos *tabelaSimbolos = (TabelaSimbolos *) malloc(sizeof(TabelaSimbolos));

    tabelaSimbolos->topo = -1;
    tabelaSimbolos->tamanho = TAM_TABELA;
    Simbolo *simbolos = (Simbolo*) malloc(TAM_TABELA * sizeof(Simbolo));
    tabelaSimbolos->simbolos = simbolos;
    
    return tabelaSimbolos;
}


Simbolo buscaSimbolo(TabelaSimbolos *tabelaSimbolos, char ident[]) {
    
    for (int i = tabelaSimbolos->topo; i >= 0; i--) {
        if (strcmp(tabelaSimbolos->simbolos[i].ident, ident) == 0) {
            return tabelaSimbolos->simbolos[i];
        } 
    }
    
    exit(-1);
}

void insereSimbolo(TabelaSimbolos *tabelaSimbolos, char ident[], Atributos *atributos) {
    printf("ident: %s\n", ident);
    tabelaSimbolos->tamanho++;
    tabelaSimbolos->topo++;
    tabelaSimbolos->simbolos[tabelaSimbolos->topo].atributos = atributos;
    strncpy(tabelaSimbolos->simbolos[tabelaSimbolos->topo].ident, ident, TAM_MAX);
}

void retiraSimbolos(TabelaSimbolos *tabelaSimbolos, int n) {
    tabelaSimbolos->topo -= n;
}

void imprimeSimbolo(Simbolo simbolo) {
    printf("simboloIdent: %s\n", simbolo.ident);
    Atributos *atributos = simbolo.atributos;
    printf("categoria: %s; tipo: %d; nivel léxico: %d; deslocamento: %d;\n", atributos->categoria, atributos->tipo, atributos->nivelLexico, atributos->deslocamento);
}

void imprimeTabela(TabelaSimbolos *tabelaSimbolos) {
    printf("topo: %d;\ntamanho: %d;\n", tabelaSimbolos->topo, tabelaSimbolos->tamanho);
    for (int i = tabelaSimbolos->topo; i >= 0; i--) {
        imprimeSimbolo(tabelaSimbolos->simbolos[i]);
    }
}

void atualizaTipo(TabelaSimbolos *tabelaSimbolos, int tipo, int num_simbolos) {
    int topo = tabelaSimbolos->topo;
    for (int i = 0; i < num_simbolos; i++) {
        if(tabelaSimbolos->simbolos[topo - i].atributos->tipo == -1) {
            tabelaSimbolos->simbolos[topo - i].atributos->tipo = tipo;
        }
    }
}