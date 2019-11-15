#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

    int   main(){
    //menu
    int opcao, decisao;

    void vetor1();
    void mostra();

    printf("1-  Preencher aleatoriamente o primeiro vetor\n");
    printf("2-  Preencher aleatoriamente o segundo vetor\n");
    printf("3-  Preencher aleatoriamente o terceiro vetor\n");
    printf("4-  Imprimir vetor 1\n");
    printf("5-  Imprimir vetor 2\n");
    printf("6   Imprimir vetor 3\n");
    printf("7   Busca Sequencial (vetor 1)\n");
    printf("8   Ordenação por trocas - bubbleSorte - Vetor1\n");
    printf("10  Ordenação por inserção vetor 3\n");
    printf("11  Busca Binária (vetor 3)\n");
    printf("12  Sair\n");






    scanf("%d", &opcao);

    switch (opcao) {
    case 1:

       vetor1();
        break;
    case 2:


        break;
    case 3:


        break;
    case 4:
        mostra();


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
        printf("voce pediu para sair, prencione qualquer tecla para continuar\n");
        break;
    default:

        printf("voce deve escolher uma opcao valida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");

    }
}
