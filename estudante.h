#include <stdio.h>
#include <stdlib.h>

typedef struct Student{
    char name[50];
    int age;
}estudante;
estudante registrar_aluno(){
    estudante a;
    fgets(a.name, 50, stdin);
    scanf("%d", &a.age);
    getchar();
    return a;
    }
void salvar_alunos(estudante a[], const char*filename){
    FILE *file;
    file = fopen("caio.dat", "wb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        return ;
    }
    fwrite(a, sizeof(estudante), 5, file);
    fclose(file);
}
void imprimir(estudante a[], const char *filename){
    FILE *file;
    file = fopen("caio.dat", "rb");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!");
        return ;
    }
    fread(a, sizeof(estudante), 5, file);      
    for (int i = 0; i < 5; i++) {
        printf("Nome: %sIdade: %d\n", a[i].name, a[i].age);    
    }
    fclose(file);
}
