#ifndef MATRIZ_H
#define MATRIZ_H

typedef struct {
    int info;
    int col;
    No* prox;
} No;
typedef No * Pno;

void inicializa(Pno matriz, int linhas);
void insere(Pno matriz, int valor, int linha, int coluna);
void imprime_matriz(Pno matriz, int linhas, int colunas);
void imprime_ultima_coluna(Pno matriz, int linhas, int colunas);
void libera(Pno matriz, int linhas);

#endif