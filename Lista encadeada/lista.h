#ifndef lista_h
#define lista_h

typedef struct livro{
    char titulo;
    int posicao;
    struct livro*prox;
}Livro;

Livro* push(Livro* livro, int* tam);
void push_selection(Livro** livro, int* posicao, int* tam);
void remover(Livro** livro, int* posicao, int* tam);
void remover_ultimo(Livro** lista, int* tam);
void search(Livro* livro, int* posicao);
void imprimir(Livro* livro);


#endif
