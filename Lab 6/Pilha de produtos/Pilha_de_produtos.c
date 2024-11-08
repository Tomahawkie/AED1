#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "produtos.h"

int main(){
    int tam = 0;
    Produtos* pilha() = (Produtos*) malloc(sizeof(Produtos));;
     
    pilha->topo = NULL;
    pilha = carregar_produtos_arquivo(&tam, "estoque.txt");
    int op = 0;
    
    do{
        printf("1 - Cadastrar\n2 - Remover\n3 - Imprimir\n4 - Sair\n");
        scanf("%d", &op);
        getchar();
        switch(op){
            case 1:
                pilha = Pno pop(pilha, &tam, "estoque.txt");
                break;
            case 2:
                pilha = pop(pilha, &tam, "estoque.txt");
                break;
            case 3:
                pilha = peek(pilha);
                break;
            case 4:
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(op != 4);

    salvar_produtos_arquivo(pilha, &tam, "estoque.txt");

    free(pilha);

    


    return 0;
}