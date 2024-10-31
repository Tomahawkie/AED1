#include <stdio.h> 
#include <stdlib.h> 
#include "estudante.h"


int main(){
    FILE *file;
    estudante aluno[5];
    for(int i=0; i<5; i++){
        aluno[i]= registrar_aluno();
    }
    salvar_alunos(aluno, file);
    for(int i=0; i<5; i++){
    imprimir(aluno, file);
    return 0;
    }
}
