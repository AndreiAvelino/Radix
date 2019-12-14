#include <stdio.h>
#include <stdlib.h>
#include "Radix.h"

void GeraNumeros(int n, int d, int *p){
    
    int i = 0;
    int cont = d;
    int valor = 0;
        
    if(d == 1) d = d*10;
        
    while (cont>1){
        d = d*10;
        cont--;
    }
  
    for (i; i < n; i++){
        valor = rand() % d;
        *p = valor;
        *p++;
    }
}




/*Função para criar fila*/
Fila *criar_fila(){
    
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    fila->proximo = NULL;
    
    return fila;
}

/*Função para adicionar um número na fila*/
void adicionar(Fila *p, int num){
    
    No *no = p;
    while (no->proximo != NULL) no = no->proximo;
    
    No *novono = malloc(sizeof(Fila));
    
    novono->proximo = NULL;
    novono->num = num;
    no->proximo = novono;
    
}

/*Função para retirar os números da fila e descaloca-los*/
int reorganizar(Fila *fila){

    int num = 0;
    No *no = fila;
    
    if (fila->proximo != NULL){
        
        no = no->proximo;
    
        if (no->proximo != NULL){
            fila->proximo = no->proximo;
            num = no->num;
            free(no);
            return num;
        }

        if (no->proximo == NULL){
            fila->proximo = NULL;
            num = no->num;
            free(no);
            return num;
        }
    }
}

