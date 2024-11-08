#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

// Angelo Bianco Franzen Breseghello RA 163554
// Caio Veloso RA 168775

Livro add_livro(){
    Livro livro;
    printf("Qual o Titulo, autor e ano de lançamento do livro respectivamente?\n");
    fgets(livro.titulo, 100, stdin);
    // getchar();
    fgets(livro.autor, 50, stdin);
    getchar();
    scanf("%d", &livro.ano);
    return livro;
}
Pno push(Pno topo){
    Pno temp = malloc(sizeof(No));
    if(temp == NULL){
        printf("erro ao alocar memoria\n");
        return NULL;
    }else{
        temp->livros = add_livro();
        temp->proximo = topo;
        return temp;
    }
}
void pop(Pno* topo){
    Pno temp = topo;
    if(temp == NULL){
        printf("pilha vazia\n");
    }else{
        *topo = temp->proximo;
        free(temp);
    }
}
Pno peek(Pno topo){
    Pno temp = malloc(sizeof(No));
    temp = topo;
    if(topo == NULL){
        printf("pilha vazia\n");
        return NULL;
    }else{
        while(topo != NULL){
            printf("Titulo: %s\nAutor: %s\nAno de lançamento: %d\n", topo->livros.titulo, topo->livros.autor, topo->livros.ano);
            topo = topo->proximo;
        }
    }
}
void limpar(Pno topo){
    while(topo != NULL){
        Pno temp = topo->proximo;
        free(topo);
    }
    printf("pilha liberada\n");
}