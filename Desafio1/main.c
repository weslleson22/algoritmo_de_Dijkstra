#include <stdio.h>
#include <stdlib.h>

int main(){
    void preencher1();
    void mostrar1();
    int bol=0,op,n=1;


    while(bol==0){



    printf("Bem vindo, digite a operacao que deseja fazer.\n");
    printf("---------------------------------------------\n");
    printf("|(1)  - Preencher aleatoriamente o primeiro vetor       |\n");
    printf("|(2)  - Preencher aleatoriamente o segundo vetor.       |\n");
    printf("|(3)  - Preencher aleatoriamente o terceiro vetor       |\n");
    printf("|(4)  - Imprimir o Vetor 1                              |\n");
    printf("|(5)  - Imprimir o Vetor 2                              |\n");
    printf("|(6)  - Imprimir o Vetor 3                              |\n");
    printf("|(7)  - Buscar Sequencial (vetor 1)                     |\n");
    printf("|(8)  - Ordenação por trocas - bubbleSorte - (vetor1)   |\n");
    printf("|(9)  - Ordenação por seleção (vetor2)                  |\n");
    printf("|(10) - Ordenação por inserção (vetor 3)               |\n");
    printf("|(11) - Busca Binária (vetor 3)                        |\n");
    printf("|(12) - Sair.                                          |\n");
    printf("---------------------------------------------\n");
    scanf("%d",&op);
    switch(op){
        case 1:
            preencher1();

            system("cls");

    break;
        case 2:
             system("cls");




    break;
        case 3:


    break;
        case 4:
            mostrar1();

    break;
        case 5:

    break;
        case 6:

    break;
        case 7:

    break;
        case 8:


        break;
        case 9:


    break;

        case 10:
            break;

        case 11:
            break;
        case 12:
            system("cls");
            printf("Programa encerrado.");
            bol=1;
    break;
        default:
        system("cls");
        printf("Operacao invalida.\n\n---------------------------------------------\n");
            }
        }


    return 0;
    }







