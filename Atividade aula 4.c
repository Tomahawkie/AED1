#include <stdio.h> 
#include <stdlib.h> 

struct Student{
    char name[50];
    int age;
};

int main(){
    FILE *file;
    struct Student students[5];
    for(int i=0; i<5; i++){
        fgets(students[i].name, 50, stdin);
        scanf("%d", &students[i].age);
        getchar();
    }
    
    file = fopen("caio.dat", "wb");
	if (file == NULL){
        printf("erro ao abrir o arquivo!\n");
        return 1;
    }
    
	fwrite(&students, sizeof(struct Student), 5, file);
	fclose(file);
	
	for(int i=0; i<5; i++){
		students[i].name[0] = '\0';
		students[i].age = 0;
	}
	file = fopen("caio.dat", "rb");
	if (file == NULL){
        printf("erro ao abrir o arquivo!\n");
        return 1;
    }
	fread(&students, sizeof(struct Student), 5, file);
	fclose(file);
	 for (int i = 0; i < 5; i++) {
        printf("Nome: %sIdade: %d\n", students[i].name, students[i].age);
    }
    return 0;
}
