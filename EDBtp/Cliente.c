
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <conio.h>  //clrscr

#define BUFFER 64

/* Estrutura da lista declarada para armazenar nossos dados. */
typedef struct lista {
        char *nome;
        int cpf;
        struct lista *proximo;
} Dados;

/* Prototipo das funcoes de manuseio dos dados. */
Dados *inicia_dados(char *nome, int cpf);
Dados *insere_dados(Dados *dados, char *nome, int cpf);
void exibe_dados(Dados *dados);
void busca_dados(Dados *dados, char *chave);
Dados *deleta_dados(Dados *dados);
int checa_vazio(Dados *dados);

/* Prototipo das funcoes do menu.*/
void insere(void);
void exibe(void);
void busca(void);
void deleta(void);

/* Inicializa a estrutura de dados principal. */
Dados *principal = NULL;

/* Cria a nova lista apontando o proximo no para NULL. */
Dados *inicia_dados(char *nome, int cpf) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->cpf = cpf;
        novo->proximo = NULL;

        return novo;
}

/* Como a lista nao esta mais vazia, apontamos o proximo no para lista anterior. */
Dados *insere_dados(Dados *dados, char *nome, int cpf) {

        Dados *novo;

        novo = (Dados *)malloc(sizeof(Dados));
        novo->nome = (char *)malloc(strlen(nome)+1);
        strncpy(novo->nome, nome, strlen(nome)+1);
        novo->cpf = cpf;
        novo->proximo = dados;

        return novo;
}

/* Percorre todos os campos da lista e imprime ate o ponteiro proximo chegar em NULL. */
void exibe_dados(Dados *dados) {

        fprintf(stdout, "Cadastro:\n\n");

        fprintf(stdout, "------------------------\n");

        for (; dados != NULL; dados = dados->proximo) {
                printf(stdout, "Nome: %s\n", dados->nome);
                printf(stdout, "CPF: %d\n", dados->cpf);
                printf(stdout, "------------------------\n ");
        }
        printf("Pressione uma tecla para continuar.");
        getch();
}

/* Percorre cada ponta comparando o nome com a chave. */
void busca_dados(Dados *dados, char *chave) {

        int achou = 0;

        fprintf(stdout, "Cadastro:\n\n");
        for (; dados != NULL; dados = dados->proximo) {
                if (strcmp(chave, dados->nome) == 0) {

                        printf(stdout, "------------------------\n");
                        printf(stdout, "Nome: %s\n", dados->nome);
                        printf(stdout, "CPF: %d\n", dados->cpf);
                        printf(stdout, "------------------------\n");
                        achou++;
                }
        }

        if (achou == 0)
                printf(stdout, "Nenhum resultado encontrado.\nPressione uma tecla para continuar.\n");
        else
                printf(stdout, "Foram encontrados %d registros. \nPressione uma tecla para continuar.\n", achou);

//
        getch();
}

/* Deleta o ultimo registro inserido. */
Dados *deleta_dados(Dados *dados) {

        Dados *novo;

        novo = dados->proximo;

        free(dados->nome);
        free(dados);

        fprintf(stdout, "O ultimo registro inserido foi deletado com sucesso.\\n");
//

        return novo;
}

/* a pena checa se a lista e NULL ou nao. */
int checa_vazio(Dados *dados) {

        if (dados == NULL) {
                fprintf(stdout, "Lista vazia!\\n");
//
                return 1;
        } else
                return 0;
}

/* Obtem os dados necessarios para chamar as funcoes de manuseio de dados. */
void insere(void) {

        char *nome;
        int cpf;

        nome = (char *)malloc(BUFFER);

        fprintf(stdout, "\n\nDigite o Nome: \n----> ");
        scanf("%s", nome);
        fprintf(stdout, "\n");

        fprintf(stdout, "Digite a CPF: \n----> ");
        scanf("%d", &cpf);
        fprintf(stdout, "\n");

        if (principal == NULL)
                principal = inicia_dados(nome, cpf);
        else
                principal = insere_dados(principal, nome, cpf);
}

void exibe(void) {

        if (!checa_vazio(principal))
                exibe_dados(principal);

}

void busca(void) {

        char *chave;

        if (!checa_vazio(principal)) {

                chave = (char *)malloc(BUFFER);

                fprintf(stdout, "Digite o nome para buscar: \\n--> ");
                scanf("%s", chave);

                busca_dados(principal, chave);
                getch();
        }
}

void deleta(void) {

        if (!checa_vazio(principal))
                principal = deleta_dados(principal);
}
