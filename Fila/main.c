//QUEUE (FILA) - FIFO (FIRST IN, FIRST OUT)

#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int conteudo;
    struct no *prox;
}no;

no *criarNo(int conteudo){
    no *novo = (no*) malloc(sizeof(no));

    novo->prox = NULL;
    novo->conteudo = conteudo;
    return novo;
}

//ENQUEUE - Enfileirar
void inserirNo(no **head, int conteudo){
    no *p;
    no *rear = *head;

    if(*head == NULL){
        *head = p = criarNo(conteudo);
    }else{
        while(rear->prox != NULL){
            rear = rear->prox;
        }
        p = criarNo(conteudo);
        rear->prox = p;
        rear = p;
    }
    printf("-> Item da fila inserido: %d\n", p->conteudo);
}
//DEQUEUES - Desinfileirar
no *removerNO(no **head){
    no *p;
    if(*head == NULL){
        return NULL;
    }
    p = *head;
    *head = (*head)->prox;
    p->prox = NULL;
    printf("\n-> Item da fila removido: %d\n", p->conteudo);
    return p;
}

void imprimirFila(no *head){
    no *p = head;
    if(p == NULL){
        printf("-> Fila vazia!\n");
        return;
    }
    printf("\n\t-> Fila:\n");
    while(p != NULL){
        printf("> %d ", p->conteudo);
        p = p->prox;
    }
    printf("\n");
}

int main(){
    no *head = NULL;

    printf("\n");
    inserirNo(&head, 10);
    inserirNo(&head, 20);
    inserirNo(&head, 30);
    imprimirFila(head);

    removerNO(&head);
    imprimirFila(head);
    
    return 0;
}
