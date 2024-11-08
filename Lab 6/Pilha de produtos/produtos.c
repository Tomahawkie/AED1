#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "produtos.h"

Produtos* carregar_produtos_arquivo(,int* tam, char* estoque){

    FILE* file = fopen(estoque, "a+");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return NULL;
    }
    fseek(file, 0, SEEK_END);
    long tamanho = ftell(file);
    rewind(file);
    Produtos* pilha = (Produtos*) malloc(tamanho);
    fread(pilha, sizeof(Produtos), tamanho, file);
    tam = tamanho/sizeof(Produtos);
    fclose(file);
    return pilha;
}


Pno push(Produtos* pilha, int* tam, char* estoque){
    No* novo_no = (No*) malloc(sizeof(No));
    prinft("Digite o nome do produto: ");
    fgets(novo_no->produto, 50, stdin);
   
    printf("Digite o estoque do produto: ");
    scanf("%d", &novo_no->estoque);
    getchar(); // buffer
   
    printf("Digite o preco do produto: ");
    scanf("%f", &novo_no->preco);
    getchar(); // buffer
   
    (*tam)++;
    novo_no->prox = pilha->topo;
    pilha->topo = novo_no;
    FILE* file =fopen(estoque, "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    fwrite(pilha, sizeof(Produtos), tam, file);
    fclose(file);
    return pilha;
}


Pno pop(Produtos* pilha, int* tam, char* estoque){
    if(pilha->topo == NULL){
        printf("A pilha esta vazia\n");
        return;
    }
    No* temp = malloc(sizeof(No));
    temp = pilha->topo;
    pilha->topo = pilha->topo->prox;
    free(temp);
    
    (*tam)--;
    
    FILE* file = fopen(estoque, "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    fwrite(pilha, sizeof(Produtos), tam, file);
    fclose(file);
    return pilha;
}
Pno peek(Produtos* pilha){
    if(pilha->topo == NULL){
        printf("A pilha esta vazia\n");
        return;
    }
    No* temp = malloc(sizeof(No));
    temp = pilha->topo;
    while(temp != NULL){
        printf("Nome: %s\n", temp->topo->produto);
        printf("Estoque: %d\n", temp->topo->estoque);
        temp = temp->prox;
    }
    return pilha;
}
 
void salvar_produtos_arquivo(Produtos* pilha, int* tam, char* estoque){
    FILE* file = fopen(estoque, "w");
    if(file == NULL){
        printf("Erro ao abrir o arquivo\n");
        return;
    }
    fwrite(pilha, sizeof(Produtos), *tam, file);
    fclose(file);
}