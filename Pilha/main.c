//PILHA - LIFO (LAST IN, FIRST OUT)

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
}no;

no * criarNo(int conteudo){
    no *novo = (no*) malloc(sizeof(no));
    if(!novo){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    novo->prox = NULL;
    novo->conteudo = conteudo;
    return novo;
}

void inserirNo(no **topo, int conteudo){
    no *p = criarNo(conteudo);
    if(!*topo){
        *topo = p;
    }else{
        p->prox = *topo;
        *topo = p;
    }
    printf("\n-> Item da pilha inserido: %d\n", p->conteudo);
}

no * removerNo(no **topo){
    no *p = NULL;
    if(!*topo){
        printf("Pilha vazia!\n");
        return NULL;
    }
    p = *topo;
    *topo = (*topo)->prox;
    p->prox = NULL;
    printf("\n-> Item da pilha removido: %d\n", p->conteudo);
    return p;
}

void imprimirPilha(no *topo){
    no *p = topo;
    if(!p){
        printf("Pilha vazia!\n");
        return;
    }
    printf("\n\t-> Pilha:\n");
    while(p){
        printf("> %d\n", p->conteudo);
        p = p->prox;
    }
    printf("\n");
}

int main(){
    no *topo = NULL;

    inserirNo(&topo, 10);
    inserirNo(&topo, 20);
    inserirNo(&topo, 30);

    imprimirPilha(topo);

    removerNo(&topo);
    imprimirPilha(topo);
    return 0;
}