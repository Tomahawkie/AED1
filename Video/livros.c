#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "livros.h"


No* carregar_arquivo(FILE* arquivo){
    FILE* file = arquivo;
    No* fila;
    file = fopen("arquivo.txt", "a");
    fclose(file);
    file = fopen("arquivo.txt", "r");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        fclose(file);
        return 0;
        } 
    No* temp;
    while(fread(temp, sizeof(No), 1, file) == 1){
        temp = malloc(sizeof(No));
        }
    fclose(file);
    return temp;
    } //abre o arquivo e inicia a fila

No* ordenar(No* lista, int* ordem){
    if(lista == NULL || lista->prox == NULL){
        return lista;
    }
    No *atual, *anterior, *ptr = NULL;
    int trocado;
    do{
        trocado = 0;
        atual = lista;
        anterior = NULL;
        while(atual->prox != ptr){
            No* prox = atual->prox;
            if (((*ordem) == 1 && strcmp(atual->titulo, prox->titulo) > 0) ||
                ((*ordem) == 2 && strcmp(atual->autor, prox->autor) < 0)){
                atual->prox = prox->prox;
                prox->prox = atual;
                
                anterior->prox = prox;
                trocado = 1;
            } else{
                atual = atual->prox;
            }
            anterior = atual;
        }
        ptr = atual;    
    }while(trocado);
    return lista;
    } // ordena a lista como o usuario desejar

void adicionar_fila(Cabeca** cabeca, No* temp){
    No* aux = (*cabeca)->fila;
    if(*cabeca == NULL){
        *cabeca = malloc(sizeof(Cabeca));
        (*cabeca)->fila = temp;
        (*cabeca)->antigo = temp;
        (*cabeca)->novo = temp;
    }
    else{
        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = temp;
        (*cabeca)->novo = temp;
} // adiciona o livro na fila(idade)
}
void adicionar(No** lista, Cabeca *cabeca){
    No* temp = malloc(sizeof(No)), *aux = *lista;
    if(temp == NULL){
        printf("Erro ao alocar memoria\n");
        return ;
    }
    printf("Nome do Livro\n");
    fgets(temp->titulo, 50, stdin);
    printf("Nome do autor\n");
    fgets(temp->autor, 50, stdin);
    if(lista == NULL){
        *lista = temp;
    }else {
        while(aux != NULL){
            aux = aux->prox;
        }
        aux->prox = temp;
    }
    adicionar_fila(&cabeca, temp);
    
}//adiciona o livro na lista

void remover_fila(Cabeca** cabeca, No* temp){
    No* aux = (*cabeca)->fila, *anterior = NULL;
    while(aux->prox != NULL && aux->titulo != temp->titulo){
        anterior = aux;
        aux = aux->prox;
    }
    if(aux == (*cabeca)->antigo){
        (*cabeca)->antigo = aux->prox;
        free(aux);
        return;
    }if(aux == (*cabeca)->novo){
        (*cabeca)->novo = anterior;
        free(anterior);
        return;
    }
    anterior->prox = aux->prox;
    free(aux);
}//remove o livro da fila(idade)
void remover_livro(No** lista, Cabeca* cabeca)
{
    if(*lista == NULL){
        printf("lista vazia\n");
        return;
    }
    char titulo[50];
    printf("digite o titulo a ser removido\n");
    scanf("%s", titulo);
    No* temp, *anterior = NULL; 
    temp = *lista;
    while(temp->prox != NULL && temp->titulo != titulo){
        anterior = temp;
        temp = temp->prox;
    }if(temp == NULL){
        printf("Titulo não encontrado\n");
        return;
    }
    anterior->prox = temp->prox;
    adicionar_fila(&cabeca, temp);
    free(temp);
}//remove o livro da lista

void imprimir(No* lista){
    No* temp = lista;
    if(temp == NULL){
        printf("lista vazia\n");
        return;
    }
    while(temp != NULL){
        printf("%s\n", temp->titulo);
        temp = temp->prox;
    }
} // imprimir
void remover_intervalo(No** lista, char* inicio, char* fim, Cabeca** cabeca){
    No* temp = *lista;
    while(temp != NULL){
        if(temp->titulo >= inicio && temp->titulo <= fim){
            No* aux = temp;
            remover_fila(cabeca, temp);
            temp = temp->prox;
            free(aux);
        }else{
            temp = temp->prox;
        }
}
} // remove um intervalo

void salvar_arquivo(Cabeca* cabeca, FILE* arquivo){
    FILE *file = arquivo;
    file = fopen("arquivo.txt", "a");
    if(file == NULL){
        printf("Erro ao abrir o arquivo!\n");
        fclose(file);
        return ;
        } 
    No* temp = cabeca->fila;
    while(temp != NULL){
        fwrite(temp, sizeof(No), 1, file);
        temp = temp->prox;
    }
    fclose(file);
}// salva a fila(idade) no arquivo
