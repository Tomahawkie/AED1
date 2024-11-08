#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estudante.h"

// Angelo Bianco Franzen Breseghello RA 163554
// Caio Veloso RA 168775

void incluir_estudante(Estudante** alunos, int* tam){  
    *alunos = realloc(*alunos, ++(*tam)*sizeof(Estudante));
    if(*alunos == NULL){
        printf("Erro ao alocar memoria");
        return;
    }
	int indice = (*tam)--; 
    
    getchar(); // limpar o buffer do opcao
    printf("Nome\n");
	scanf("%[^\n]", *alunos[indice]->nome);
    printf("Idade\n");
    scanf("%d", &(*alunos)[indice].idade);
    getchar(); //pegar o enter
    
}

void apagar_estudante(Estudante** alunos, int* tam){
    char apagar[50];
    printf("Qual o nome do estudante que voce quer apagar\n");
    scanf("%[^\n]",apagar);
    for (int i=0; i< *tam; i++){
       if(strcmp(apagar, *alunos[i]->nome) == 0){
            for (int j = i; j < *tam - 1; j++) {
                *alunos[j] = *alunos[j + 1];  
            }
			(*tam)--;
			*alunos = realloc(*alunos, (*tam)*sizeof(Estudante));
			printf("Estudante %s foi removido.\n");
		    i = (*tam); // para parar o for do i
       }
    }
	
	printf("Estudante %s não encontrado.\n", apagar);
}

void listar_estudante(Estudante* alunos, int* tam){
    for(int i=1; i<=*tam; i++){
        printf("%d. Nome:%s\tIdade:%d\n", i, alunos[i].nome, alunos[i].idade);
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
    FILE* file = fopen(filename, "rb"); // estava wb o qual apaga o conteúdo do arquivo
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        fclose(file);
        return 0;
        } 
	
    fseek(file, 0, SEEK_END);
    *tam = ftell(file)/sizeof(Estudante); 
    rewind(file);
	
	if (*tam == 0){
		printf("Arquivo vazio!\n");
		return NULL;
	}
	
    Estudante* lista = malloc((*tam)*sizeof(Estudante));
    if(lista == NULL ){
        printf("Erro ao alocar memoria\n");
    }
    fread(lista, sizeof(Estudante), *tam, file);

    return lista;
} 


