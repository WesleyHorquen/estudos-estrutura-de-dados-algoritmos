/*
Desafio: Organizar uma lista encadeada de pessoas por idade, depois criar outra lista com todos os nomes repetidos, e organizar essa lista por idade também.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no{
    int idade;
    char nome[100];
    struct no *prox;
}no;

no * novoNo(int idade, const char *nome){
    no *novo = (no *) malloc(sizeof(no));
    
    if(novo){
        novo->idade = idade;
        strcpy(novo->nome, nome);
        novo->prox = NULL;
        printf("> Novo no criado com Nome %s e idade %d\n", novo->nome, novo->idade);
    }else{
        printf("\n> Erro ao alocar memoria para novo no!\n");
    }
    return novo;
}

void inserirNo(no **lista, int idade, const char *nome){
    no *novo = novoNo(idade, nome);
    
    if(!novo){
        printf("\n> Erro: Falha ao alocar memória.\n");
        return;
    }
    if(*lista == NULL || idade < (*lista)->idade){
        novo->prox = *lista;
        *lista = novo;
    }else{
        no *aux = *lista;

        while (aux->prox != NULL && aux->prox->idade <= idade){
            aux = aux->prox;
        }
        novo->prox = aux->prox;
        aux->prox = novo;
    }
}

no * imprimirListaOrdenada(no *lista){
    printf("\n\t>>> Lista <<<\n");
    while(lista != NULL){
        printf("Nome: %s\t|\tIdade: %d\n", lista->nome, lista->idade);
        lista = lista->prox;
    }
    printf("\n");
    return lista;
}

no * listaRepetidos(no *lista){
    no *listaRepetidos = NULL;
    no *aux1 = lista;

    while(aux1 != NULL){
        no *aux2 = aux1->prox;
        int repetiu = 0;
        while(aux2 != NULL){
            if(strcmp(aux1->nome, aux2->nome) == 0){
                repetiu = 1;
                //Insere o que repetiu
                inserirNo(&listaRepetidos, aux2->idade, aux2->nome);
            }
            aux2 = aux2->prox;
        }
        if(repetiu){
            //Insere o primeiro que repetiu
            inserirNo(&listaRepetidos, aux1->idade, aux1->nome);
        }
        aux1 = aux1->prox;
    }
    return listaRepetidos;
}

void imprimirListaRepetidos(no *listaRepetidos){
    printf("\n\t>>> Lista Repetidos <<<\n");
    while(listaRepetidos != NULL){
        printf("Nome: %s\t|\tIdade: %d\n", listaRepetidos->nome, listaRepetidos->idade);
        listaRepetidos = listaRepetidos->prox;
    }
    printf("\n");
}

int main(){
    no *lista = NULL;

    printf("\n");
    inserirNo(&lista, 40, "Antonio");
    inserirNo(&lista, 20, "Isabel");
    inserirNo(&lista, 10, "Jose");
    inserirNo(&lista, 30, "Antonio");
    inserirNo(&lista, 20, "Jose");
    inserirNo(&lista, 15, "Maria");
    
    imprimirListaOrdenada(lista);
    imprimirListaRepetidos(listaRepetidos(lista));

    return 0;
}