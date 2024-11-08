#ifndef ESTUDANTE_H
#define ESTUDANTE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[50];
    int idade;
}Estudante;

void incluir_estudante(Estudante* alunos, int* tam);
void apagar_estudante(Estudante* alunos, int* tam);
void listar_estudante(Estudante* alunos, int tam);
void salvar_estudante_arquivo(Estudante* alunos, int* tam, char* filename);
Estudante* carregar_estudante_arquivo(int* tam, char* filename);

#endif