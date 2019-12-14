#ifndef RADIX_H
#define RADIX_H

void GeraNumeros(int n, int d, int *p);

typedef struct node{
    
    int num;
    struct node *proximo;
    
} Fila;

typedef Fila No;

void adicionar(Fila *p, int num);

Fila *criar_fila();

int reorganizar(Fila *fila);


#endif