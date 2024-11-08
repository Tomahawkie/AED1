#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "book.h"

// Angelo Bianco Franzen Breseghello RA 163554
// Caio Veloso RA 168775

int main() {
    Pno topo =NULL;
    
    int op = 0;
    do{
        printf("1 - push\n2- pop\n3 - peek\n4 - Limpar vetor\n5 - Sair\n");
        scanf("%d", &op);
        getchar();  //buffer
        switch (op)
        {
        case 1:
            topo = push(topo);
            break;
        
        case 2:
            pop(&topo);
            break;
        
        case 3:
            topo = peek(topo);
            break;
        
        case 4:
            limpa(topo);
            break;
        case 5:
            default:
                printf("Opcao invalida\n");
                break;
        }

    }while(op != 5);
    free(topo);
    return 0;
}