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
    return lista;
}

void push_selection(Livro** lista, int* posicao, int* tam){
    Livro *temp, *novo = malloc(*tam*sizeof(Livro));
    temp = lista;

    if(*posicao > *tam){
        printf("posição invalida\n");
        free(temp);
        return;
    }
    novo = push(novo, tam);
    novo->posicao = *posicao;
    while(temp->posicao < (*posicao)-1){
        temp = temp->prox;
    }
    novo->prox = temp->prox;
    temp->prox = novo;
    temp = novo->prox;
    while(temp!= NULL){
        temp->posicao++;
        temp->prox;
    }

}
void search(Livro* lista, char titulo[50]){
    Livro* temp;
    temp = lista;
    if(lista == NULL){
        printf("Lista vazia!\n");
        return ;
    }
    while(temp->prox != NULL){
        if(titulo == temp->titulo){
            pritf("posicao : %d \n", temp->posicao);
            return ;
        }
        temp = temp->prox;
    } 
    prinf("titulo não encontrado");
    return ;
}
void remover(Livro** lista, int* posicao, int* tam){
    Livro* temp , *anterior = malloc(*tam*sizeof(Livro));
    if(lista==NULL){
        printf("lista vazia\n");
        return;
    } 
        temp = lista;
        while(temp->prox != NULL){
            if(temp->posicao == *posicao){
                anterior->prox = temp->prox;
                while(anterior->prox != NULL){
                    anterior->prox->posicao--;
                    anterior = anterior->prox;
                }
                free(temp);
                (*tam)--;
                return;
            }
            anterior = temp;
            temp = temp->prox;
        }
    printf("posicao nao encontrada\n");
    return;
}
void remover_ultimo(Livro** lista, int* tam){
    if(lista == NULL){
        printf("Lista vazia\n");
        return;
    }
    Livro* temp, *anterior;
    temp = lista;
    while(temp->prox != NULL){
        anterior = temp;
        temp = temp->prox;
    }
    anterior->prox = temp->prox;
    (*tam)--;
    free(temp);
}
void imprimir(Livro* lista){
    Livro* temp;
    temp = lista;
    while (temp != NULL){
        printf("%d : %s", temp->posicao, temp->titulo);
        temp = temp->prox;    
    }
    return;
}
