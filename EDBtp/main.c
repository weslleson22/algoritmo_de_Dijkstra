#include<stdio.h>
#include<stdlib.h>

//Prototipos

void insere();
void busca();
void deleta_dados();
void cadastroPedido();
int menu();

    int main(){
    int bol=0,op,n=1;


    while(bol==0){



    printf("*****************Bem vindo, digite a operacao que deseja fazer.******************\n");
    printf("---------------------------------------------------------------------------------\n");
    printf("|(1)  - Inserir produto de forma ordenada(crescente)                            |\n");
    printf("|(2)  - Buscar produto usando a busca Binaria                                   |\n");
    printf("|(3)  - Alterar produto                                                         |\n");
    printf("|(4)  - Excluir estoque                                                         |\n");
    printf("|(5)  - Exibir Estoque                                                          |\n");
    printf("|(6)  - Cadastrar cliente e manter em ordem crescente aplicando o selectionSort |\n");
    printf("|(7)  - Alterar Cliente                                                         |\n");
    printf("|(8)  - Exluir Cliente                                                          |\n");
    printf("|(9)  - Exibir Cliente                                                          |\n");
    printf("|(10) - Realizar Vendas                                                         |\n");
    printf("|(11) - Criar uma cópia da Lista das vendas realizadas                          |\n");
    printf("|(12) - Consultar vendas                                                        |\n");
    printf("|(13) - Sair.                                                                   |\n");
    printf("--------------------------------------------------------------------------------|\n");
    scanf("%d",&op);
    switch(op){
        case 1:
//            insere();
//            cadastroPedido();

            system("cls");

    break;
        case 2:
             system("cls");

    break;
        case 3:
             system("cls");
    break;
        case 4:
         system("cls");

    break;
        case 5:
             system("cls");

    break;
        case 6:
            insere();

         system("cls");
    break;
        case 7:

         system("cls");
    break;
        case 8:
             system("cls");
        deleta_dados();


   break;
        case 9:
         system("cls");
         busca();
   break;

        case 10:
        system("cls");
    break;

      case 11:
         system("cls");
    break;

       case 12:
         system("cls");
    break;
        case 13:
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


