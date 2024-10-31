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

int* espelhar_vetor(int *v, int n){
    
    v = (int*)realloc(v, 2*n*sizeof(int));
    for (int i=0; i<n ; i++){
        v[n+i] = (-1)*v[i];
    }
    return v;
}
int* fInsertion_Sort(int *pVetor, int n)
{
    int vAux;
    int vTemp;
    int vTroca;

    for (vAux=1; vAux < n; vAux++) // vAux começa na posição 1 do vetor e vai até a ultima posição;
    {
        vTemp = vAux; // vTemp recebe a posição que está passando no "for";

        while (pVetor[vTemp] < pVetor[vTemp-1]) // Enquanto o valor que está passando na posição "vTemp" for menor que a posição "vTemp" menos 1, ocorre a troca;
        { // Ocorre a troca;
            vTroca          = pVetor[vTemp];
            pVetor[vTemp]   = pVetor[vTemp-1];
            pVetor[vTemp-1] = vTroca;
            vTemp--; // vTemp decrementa 1;

            if (vTemp == 0) // Quando "vTemp" chegar na posição 0, primeira posição do vetor, o laço while para;
                break;
        }

    }
    return pVetor;
}
void imprimir(int *v, int n){
    for (int i=0; i<(2*n); i++){
        printf("%d\n", v[i]);
    }
}    
int main(){
    int n;
    printf("Digite o tamanho do vetor de numeros inteiros");
    scanf("%d", &n);
    int *v;
    v = (int*)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        printf("digite os elemento do vetor");
        scanf("%d", &v[i]);
    }
    
    v = espelhar_vetor(v, n);
    imprimir(v, n);
    v=fInsertion_Sort(v, n);
    imprimir(v, n);
    free(v);
    return 0;
}
