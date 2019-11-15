#include <stdio.h>
#include <stdlib.h>

    typedef struct no {
    int info;
    struct no *ant;
    struct no *prox;
    }Lista;

    Lista* crialista() {
    return NULL;
    }

Lista* insere(Lista *list, int valor) {
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->info = valor;
    novo->prox = list;
	novo->ant = NULL;
	/* verifica se a lista não está vazia */
	if (list != NULL)
		list->ant = novo;
    return novo;
}

Lista* insereEntreQuartoQuinto (Lista *list, int n) {
    int x=0;
    for (list!=NULL;list=list->prox) {
        x++;
        if (x == n) {
            Lista *novo = (Lista*) malloc(sizeof(Lista));
            novo->info = (list->info+list->ant->info)/2;

            novo->prox = list;
            novo->ant = list->ant;
            list->ant->prox = novo;
            list->ant = novo;

            Lista *p = list;
            while (p->prox!=NULL) {
                p=p->prox;
            }
            return p;
        }
    }
    return NULL;
}

void imprime (Lista *list) {
    Lista *p;
    for (p = list; p != NULL; p = p->prox) {
        printf("info = %d\n", p->info);
    }
}

int estavazia(Lista *list) {
    return (list == NULL);
}

Lista* busca (Lista *list, int valor) {
    Lista* p;
    for (p=list; p!=NULL; p=p->prox) {
        if (p->info == valor) {
            return p;
        }
    }
    return NULL; /* não achou o elemento */
}

Lista* retira (Lista* list, int val) {
	Lista* p = busca(list,val);
	if (p == NULL) {
		return list;/* não achou o elemento: retorna lista inalterada */
	}
	if (list == p) { /* se é o primeiro elemento */
		list = p->prox;
	}else{
		p->ant->prox = p->prox;
	}
	if (p->prox != NULL){ /* se não é o último elemento */
		p->prox->ant = p->ant;
	}
	free(p);
	return list;
}

    Lista* libera(Lista* lista) {
        Lista *p = lista;
        while (p != NULL) {
            p = lista->prox;
        free(lista);
        lista = p;
    }
    return NULL;
}

int main() {
    Lista *minhalista;

    minhalista = crialista();
    minhalista = insere(minhalista, 1);
    minhalista = insere(minhalista, 2);
    minhalista = insere(minhalista, 3);
    minhalista = insere(minhalista, 4);
    minhalista = insere(minhalista, 5);
    minhalista = insere(minhalista, 6);

    imprime(minhalista);

    Lista *p = insereEntreQuartoQuinto(minhalista,7);
            p = insereEntreQuartoQuinto(minhalista,7);
            p = insereEntreQuartoQuinto(minhalista,7);

    printf("\n\n");
    imprime(minhalista);

    printf("\n\n %d\t%d", p->info, p->ant->info);

    return 0;
}

