#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
void inicializa(Pno matriz, int linhas) {
    int i;
    for(i = 0; i < linhas; i++)
        m[i] = NULL;
}

void insere(Pno matriz, int valor, int linha, int coluna) {
    Pno novo, aux;
    novo = (Pno)malloc(sizeof(No));
    novo -> info = valor;
    novo -> col = coluna;
    novo -> prox = NULL;
    if(matriz[i] == NULL)
        matriz[i] = novo;
    else
        for(aux = matriz[i]; aux -> prox != NULL; aux = aux -> prox)
            aux -> prox = novo;
}

void imprime_matriz(Pno matriz, int linhas, int colunas) {
    int i, j;
    Pno aux;
    for(i = 0; i < linhas; i++) {
        aux = matriz[i];
        for(j = 0; j < colunas; j++) {
            if((aux != NULL) && (aux -> col == j)) {
                printf("%d ", aux -> info);
                aux = aux -> prox;
            }
            else
                printf("0 ");
        printf("\n");
        }
    }
    
}

void imprime_ultima_coluna(Pno matriz, int linhas, int colunas) {
    int i, j;
    Pno aux;
    for(i = 0; i < linhas; i++) {
        aux = matriz[i];
        for(j = 0; j < colunas; j++) {
            if((aux != NULL) && (aux -> col == colunas - 1)) {
                printf("%d ", aux -> info);
                aux = aux -> prox;
            }
            else
                printf("0 ");
        }
    }
}

void libera(Pno matriz, int linhas) {
    Pno p, q;
    int i;
    for(i = 0; i < linhas; i++) {
        p = matriz[i];
        while(p != NULL) {
            q = p;
            p = p -> prox;
            free(q);
        }
    }
}
