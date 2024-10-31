#include <stdio.h>
#include <stdlib.h>

/*
Tarefas práticas (não é para entregar):

Peça ao usuário um vetor de n elementos inteiros. Depois, duplique o tamanho
incluíndo os mesmos elementos com sinal negativo. Imprima o vetor ordenado.

Dado um arquivo de texto que contém uma sequência de números inteiros, com
comprimento desconhecido, faça uma função que armazene esses números em um
vetor cujo tamanho seja exatamente o da sequência de números (Leia o arquivo uma
só vez!)*/

int espelhar_vetor(int *v, int n){
    
    v = realloc(2*n, sizeof(int));
    for (int i=0; i<n ; i++){
        v[i] = v[n+i] - 2*v[i];
    }

}
int ordernar(int *v, int n){
    for (int i=0; i<2*n)
}
int main(){
    int n;
    printf("Digite o tamanho do vetor de numeros inteiros");
    scanf("%d", &n);
    int *v;
    v = malloc(n, sizeof(int));
    for (int i=0; i<n; i++){
        printf("digite os elemento do vetor");
        scanf("%d", &v[i]);
    }
    




    return 0;
}