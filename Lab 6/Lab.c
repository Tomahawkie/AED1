#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estudante.h"

int main(){
    Estudante *alunos = NULL;
    int tam=0;
    alunos = carregar_estudante_arquivo(&tam, "alunos.dat");

    int opcao;
    
    do{
        printf("1. Adicionar estudante\n2. Remover estudante\n3. Listar estudante\n4. Sair\n");
        scanf("%d", &opcao);
        if(opcao == 1)incluir_estudante(alunos, &tam);
        else if(opcao == 2)apagar_estudante(alunos, &tam);
        else if(opcao == 3)listar_estudante(alunos, tam);
    }while(opcao != 4);
    salvar_estudante_arquivo(alunos, &tam, "alunos.dat");
    free(alunos);
    return 0;
}