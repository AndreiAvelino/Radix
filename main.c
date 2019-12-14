#include <stdio.h>
#include "Radix.h"

int main()
{
    
    int n = 9;
    int d = 3;
    int x[n];
    int aux[n];
    int *p = &x[0];

    int divisor = 1;
    int j = 0;
    int l = 0;
    Fila *fila[10];


    /*Função para gerar os números aleatórios, os números são passados para o vetor
    a partir de um ponteiro*/
    GeraNumeros(n, d, p);
    
    printf("Os números gerados foram: \n");
    for (int i = 0; i<n; i++){
        printf("%d \n", x[i]);
    }
    
    // Cria 10 filas, de 0 a 9
    for (j; j<10; j++){
        fila[j] = criar_fila();
    }
    

    for (int k = 0; k<n; k++){
        
        /* Os números são divididos, quanto maior a divisão, menor ele será
        exemplo: 5632/1 = 5632; 5632/10 = 563; 5632/100 = 56. Deste número, será
        tirado os 10% que serão comparados para entrar na fila*/
        for (l = 0; l <n; l++){
            aux[l] = x[l]/divisor;
        }
        
        /* Retirada dos 10%, exemplo, 10% de 526 é 6, e este 6 será usado para
        chamar a sua fila respectiva*/
        for (l = 0; l<n; l++){
            j = aux[l]%10;
            adicionar(fila[j], x[l]);
            
            //printf("Valor %d inserido na fila %d \n", x[l], j);
        }
        
        /*Aumenta o valor do divisor, divisor começa valendo 1, e acada ciclo 
        multiplica 10*/
        divisor = divisor*10;
        
        
        
        /* O valor será retirado da fila e voltará pro X, na ordem númerica do seu
        menor número*/
        
        j = 0;
        for (l = 0; l<10; l++){
            while(fila[l]->proximo != NULL){
                x[j] = reorganizar(fila[l]);
                j++;
            }
        }
    }
    //Imprime o vetor
    printf("\n");
    printf("Vetor organizado: \n");
    for (int i = 0; i<n; i++){
        printf("%d\n", x[i]);
    }
}
