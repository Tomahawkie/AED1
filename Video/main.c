#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"


//funçoes 


int main(){
    FILE* arquivo;
    No* lista =malloc(sizeof(No));
    Cabeca* cabeca=malloc(sizeof(Cabeca));
    carregar_arquivo(arquivo, &cabeca);
    int ordem = 0, opcao = 0;
    char inicio, fim;
    do{
        printf("digite 1 para adicionar\n2 para remover\n3 para imprimir\n4 para ordenar\n5 para remover um intervalo\n6 para sair\n");
        scanf("%d", &opcao);
        switch (opcao)
        {
        case 1:
            while(lista != NULL){
                lista =lista->prox;
            }
            lista = adicionar(lista, cabeca);
            break;
        case 2:
            remover_livro(&lista, cabeca);
            break;
        case 3:
            imprimir(lista);
            break;
        case 4:
            printf("digite 1 para ordem crescente ou 2 para decrescente\n");
            scanf("%d", &ordem);
            lista = ordenar(lista, &ordem);
            break;
        case 5:
            printf("digite o intervalo de tempo que deseja excluir\n");
            scanf("%c", &inicio);
            scanf("%c", &fim);
            remover_intervalo(&lista, &inicio, &fim, &cabeca);
            break;
        case 6:
            printf("saindo...\n");
            break;
        default: 
            printf("Opção inválida\n");
            break;
        }
    }while(opcao != 6);
    salvar_arquivo(cabeca, arquivo);
    No* aux;
    while(lista != NULL){
        aux=lista;
        lista = lista->prox;
        free(aux);
        aux = cabeca->fila;
        cabeca->fila = aux->prox;
        free(aux);
    }
    free(cabeca);
    return 0;
}

