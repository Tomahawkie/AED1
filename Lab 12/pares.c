#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int valor;
    struct No* prox;
    struct No* ant;
}No;

typedef struct Cabeca{
    No* inicio;
    No* fim;
}Cabeca;

int somaPares(No* atual, Cabeca* cabeca){
    No* aux = cabeca->inicio;
    if(aux == NULL){
        return 0;
    }
    if(aux->valor % 2 == 0){
        return aux->valor + somaPares(aux->prox);
    }
    return somaPares(aux->prox);
}

void adicionar(Cabeca* cabeca,  int valor){
    if(cabeca->inicio == NULL){
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = novo;
        novo->ant = novo;
        cabeca->inicio = novo;
        cabeca->fim = novo;
    }else{
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->prox = cabeca->inicio;
        novo->ant = cabeca->fim;
        cabeca->inicio->ant = novo;
        cabeca->fim->prox = novo;
        cabeca->fim = novo;
    }
}

int main(){
    Cabeca* cabeca = malloc(sizeof(Cabeca));
    for(int i=0; i<10; i++){
        adicionar(cabeca, i);
    }
    printf("%d\n", somaPares(cabeca));
    return 0;
}

