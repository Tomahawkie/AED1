#ifndef lista_h
#define lista_h

typedef struct livro{
    char titulo;
    int posicao;
    struct livro*prox;
}Livro;

void push(Livro* livro, int* tam);
Livro* push_selection(Livro* livro, int position, int* tam);
void pop(Livro* livro, int* tam);
void search(Livro* livro, int* tam);
void imprimir(Livro* livro);


#endif