#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*4. Lista encadeada
Faça a implementação completa da livraria lista:
 lista.h: Declaração de funções e structs.
 lista.c: Implementação das funções.
 main.c: Exemplo completo de uso da lista encadeada.
Considere os seguintes requisitos adicionais:
 Implemente uma função para contar os elementos da lista.
 Adicione uma função para inserir em uma posição específica.
 Modifique a função de busca para retornar a posição do elemento.
 Adicione uma função para remover o último elemento.
 Implemente uma função para imprimir todos os elementos da lista.*/
int main(){
    Livro* lista = malloc(sizeof(Livro));
    int tam = 0, posicao, opcao;
    do {
    printf("1. Para adicionar\n2. Para adicionar em uma posicao especifica\n3. Para remover em uma posicao especifica\n4. para remover o ultimo\n5. Para obter a posicao do item\n 6. Para imprimir a lista\n7. Para sair\n");
    scanf("%d[^\n]", opcao);
    switch (opcao)
    {
    case 1:
        lista = push(lista, &tam);
        break;
    case 2:
        printf("Em qual posicao?\n");
        scanf("%d[^\n]", posicao);
        push_selection(&lista, &posicao, &tam);
        break;
    case 3:
        printf("Em qual posicao?\n");
        scanf("%d[^\n]", posicao);
        remover(&lista, &posicao, &tam);
    case 4:
        remover_ultimo(lista, &tam);
    case 5:
        printf("Em qual posicao?\n");
        scanf("%d[^\n]", posicao);
        search(lista, posicao);
    case 6:
        imprimir(lista);
    case 7:
        printf("Saindo...");
        free(lista);
        exit(EXIT_FAILURE);
    default:
        printf("opcao invalida");
        break;
    }while(opcao != 7)

    return 0;
}
