#ifndef livros_h
#define livros_h

typedef struct livro{
    char titulo[50];
    char autor[50];	
    struct livro* prox;
}No;

typedef struct lista{
    No* fila;
    No* antigo;
    No* novo;
}Cabeca;

No* carregar_arquivo(FILE* arquivo);
void adicionar(No** lista, Cabeca *cabeca);
void remover_livro(No** lista, Cabeca* cabeca);
void imprimir(No* lista);
No* ordenar(No* lista, int* ordem);
void remover_intervalo(No** lista, char* inicio, char* fim, Cabeca** cabeca);
void salvar_arquivo(Cabeca* cabeca, FILE* arquivo);

#endif
