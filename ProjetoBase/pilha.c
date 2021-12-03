#include <stdio.h>
#include <stdlib.h>
#define TAM_PILHA 64

typedef struct {
    int *elementos;
    int topo;
    int tamanho;
} Pilha;

Pilha *initPilha() {
    Pilha* pilha = (Pilha*) malloc(sizeof(Pilha));

    pilha->tamanho = TAM_PILHA;
    pilha->topo = -1;
    pilha->elementos = (int*) malloc(TAM_PILHA * sizeof(int));

    return pilha;
}

void insereElemPilha(Pilha *pilha, int valor) {
    printf("inserindo tipo: %d\n", valor);
    pilha->topo++;
    pilha->elementos[pilha->topo] = valor;
}

int retiraElemPilha(Pilha *pilha) {
    int valor = pilha->elementos[pilha->topo];
    printf("removindo tipo: %d\n", valor);
    pilha->topo--;

    return valor;
}

void imprimePilha(Pilha *pilha) {
    printf("Topo: %d\n", pilha->topo);
    printf("Tamanho: %d\n", pilha->tamanho);
    printf("Elementos: \n");
    for (int i = pilha->topo; i >= 0; i--) {
        printf(" %d\n", pilha->elementos[i]);
    }
}

void verificaTipos(Pilha *pilha) {
    printf("verificando tipos\n");
    int tipo1 = retiraElemPilha(pilha);
    int tipo2 = retiraElemPilha(pilha);

    if (tipo1 == tipo2) {
        insereElemPilha(pilha, tipo1);
    } else {
        printf("ERRO: Tipos não são compatíveis!\n");
        exit(-1);
    }
}

void verificaTiposReturnBool(Pilha *pilha) {
    printf("verificando tipos\n");
    int tipo1 = retiraElemPilha(pilha);
    int tipo2 = retiraElemPilha(pilha);

    if (tipo1 == tipo2) {
        insereElemPilha(pilha, 1);
    } else {
        printf("ERRO: Tipos não são compatíveis!\n");
        exit(-1);
    }
}

int buscaTopoElemPilha(Pilha *pilha) {
    int valor = pilha->elementos[pilha->topo];
    return valor;
}