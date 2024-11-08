#include <stdio.h>
#include <stdlib.h>


typedef struct estudante{
	char nome[50];
	int idade[10];
}estudante;


int main(){
	FILE *file
	estudante a[5];
	
	for(int i=0; i<5; i++){
		fgets(a[i].nome, 50, stdin);
		scanf("%d", &a[i].idade);
		printf("%s", a[i].nome);
		printf("%d", a[i].idade);
	}
	fopen("caio.bin", "wb");
		if (file == NULL){
        printf("erro ao abrir o arquivo!\n");
        return 1;
    }
	fwrite(a, sizeof(estudante), 5, file);

	for (int i = 0; i<5; i++){
		printf("%s", a[i].nome);
		printf("%d", a[i].idade);
	}
	fclose(file);
	return 0;
}
