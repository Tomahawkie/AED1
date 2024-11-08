#include <stdio.h>
#include <stdlib.h>
#include "matriz.h"
int main() {
    int m, n, i, j, dado;
    Pno matriz;
    do {
        printf("Insira o número de linhas: ");
        scanf("%d", &m);
        printf("Insira o número de colunas: ");
        scanf("%d", &n);
    } while (m <= 2 || n <= 2);
    
    inicializa(matriz, m);
    
    printf("Insira os dados para preencher a matriz (da esquerda para a direita, de cima para baixo): ");
    for(i = 0; i < m; i++)
        for(j = 0; j < n; j++) {
            scanf("%d", &dado);
            if(dado != 0)
                insere(matriz, dado, i, j);
        }
    
    printf("Imprimindo a matriz\n");
    imprime_matriz(matriz, m, n);
    
    printf("Imprimindo a última coluna da matriz\n");
    imprime_ultima_coluna(matriz, m, n);
    
    printf("Encerrando o programa\n");
    libera(matriz, m);
    
    return 0;
}