#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


Livro* push(Livro* lista, int* tam){
    int indice;
    indice = (*tam)++;
    lista = realloc(lista, indice*sizeof(Livro));
    scanf("%d[^\n]", lista->titulo);
    lista->posicao = indice;
    (*tam)++;
}
Livro* push_selection(Livro* lista, int* posicao, int* tam){
    Livro*temp = malloc(*tam*sizeof(Livro));
    temp = lista;
    if(*posicao > *tam){
        printf("posição invalida\n");
        free(temp);
        return
    }
    while(temp->posicao < (*posicao)-1){
        temp->prox;
    }temp->prox = push(lista, &tam);
    return temp;
}