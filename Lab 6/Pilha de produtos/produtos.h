#ifndef PRODUTOS_H
#define PRODUTOS_H

typedef struct{
    char nome[50];
    int estoque;
    float preco;
    struct No* prox;
}No;
typedef No *Pno;

typedef struct{
    No* topo; 
}Produtos;


Produtos* carregar_produtos_arquivo(int* tam, char* estoque);
Pno push(Produtos* pilha, int* tam, char* estoque);
Pno pop(Produtos* pilha, int* tam, char* estoque);
Pno peek(Produtos* pilha);
void salvar_produtos_arquivo(Produtos* pilha, int* tam, char* estoque);

#endif