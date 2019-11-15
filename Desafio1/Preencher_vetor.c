#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

void preencher1(){


int vet [1000];
   int i;
   srand(time(NULL));
    for(i=0; i<1000;i++){
            vet[i] = rand() % 100;




    }
    printf("Numeros gerados sucesso:");
    getch();
    return 0;



}






void mostrar1(){


int vet [100];
   int i;

    for(i=0; i<100;i++){
           printf("%d ", vet[i]);
           printf("\n");




    }
    printf("Numeros gerados ");
    getch();
    return 0;



}

