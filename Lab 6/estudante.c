#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

void incluir_estudante(Estudante* alunos, int* tam){  
    Estudante* temp = realloc(alunos, (*tam+1)*sizeof(Estudante));
    if(temp == NULL){
        printf("Erro ao alocar memoria");
        return;
    }
    alunos = temp;
    getchar(); // limpar o buffer do opcao
    printf("Nome\n");
    fgets(alunos[*tam].nome, 50, stdin);
    alunos[*tam].nome[strcspn(alunos[*tam].nome, "\n")] = '\0';//pegar o \n do fgets
    printf("Idade\n");
    scanf("%d", &alunos[*tam].idade);
    getchar(); //pegar o enter
    (*tam)++;
}

void apagar_estudante(Estudante* alunos, int* tam){
    
    char apagar[50];
    printf("Qual o nome do estudante que voce quer apagar\n");
    fgets(apagar, 50, stdin);
    apagar[strcspn(apagar, "\n")] = '\0'; //pegar o \n do fgets
    for (int i=0; i<*tam; i++){
       if(strcmp(apagar, alunos[i].nome) == 0){
            for (int j = i; j < *tam - 1; j++) {
                alunos[j] = alunos[j + 1];  
            }
       }
    }
    (*tam)--;
    alunos = realloc(alunos, (*tam)*sizeof(Estudante));
}

void listar_estudante(Estudante* alunos, int* tam){
    for(int i=1; i<=*tam; i++){
        printf("%d. Nome:%s\tIdade:%d\n", i, alunos.nome, alunos.idade);
    }
}


void salvar_estudante_arquivo(Estudante* alunos, int* tam, char* filename){
    FILE* file = fopen(filename, "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        fclose(file);
        } 
    fwrite(alunos, sizeof(Estudante), *tam, file);
    fclose(file);
}
Estudante* carregar_estudante_arquivo(int* tam, char* filename){
    FILE* file = fopen(filename, "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        fclose(file);
        return 0;
        } 
    fseek(file, 0, SEEK_END);
    *tam = ftell(file)/sizeof(Estudante);
    rewind(file);
    Estudante* lista = malloc((*tam)*sizeof(Estudante));
    if(lista == NULL){
        printf("Erro ao alocar memoria\n");
    }
    fread(lista, sizeof(Estudante), *tam, file);

    return lista;
}


