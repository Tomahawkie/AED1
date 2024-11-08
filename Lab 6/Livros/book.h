#ifndef BOOK_H
#define BOOK_H

// Angelo Bianco Franzen Breseghello RA 163554
// Caio Veloso RA 168775

typedef struct {
    char titulo[100];
    char autor[50];
    int ano;
    
}Livro;

typedef struct {
    Livro livros;
    struct No* proximo;
}No;

typedef No *Pno;

Pno push(Pno topo);
void pop(Pno* topo);
Pno peek(Pno topo);
void limpa(Pno topo);


#endif 