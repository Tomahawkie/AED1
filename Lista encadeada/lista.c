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
    return lista
}
void push_selection(Livro* lista, int* posicao, int* tam){
    Livro *temp, *novo = malloc(*tam*sizeof(Livro));
    temp = lista;

    if(*posicao > *tam){
        printf("posição invalida\n");
        free(temp);
        return
    }
    novo = push(novo, tam);
    novo->posicao = *posicao;
    while(temp->posicao < (*posicao)-1){
        temp->prox;
    }
    novo->prox = temp->prox;
    temp->prox = novo;
    temp = novo->prox;
    while(temp!= NULL){
        temp->posicao++;
        temp->prox;
    }

    return novo;
}
void search(Livro* lista, char titulo[50]){
    if(lista == NULL){
        printf("Lista vazia!\n");
        return
    }
    while(titulo[50] != lista->titulo){
        lista->prox;
    }
    

}
