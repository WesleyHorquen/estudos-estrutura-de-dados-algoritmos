#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int valor;
    struct no *proximo;
    
}no;

no * novoNo(int valor){
    no *novo = (no *) malloc(sizeof(no));
    
    if(novo){
        novo->valor = valor;
        novo->proximo = NULL;
        printf("\nNovo no criado com valor: %d", valor);
    }else{
        printf("\nErro ao alocar memoria para novo no!\n");
    }
    return novo;
}

no * inserirNoInicio(no **lista, int valor){
    no *novo = novoNo(valor);
    
    if(!novo){
        printf("\nErro: Falha ao alocar memória.\n");
    }else{
        novo->proximo = *lista;
        *lista = novo;
        printf("\nNovo no inserido no inicio.\n");
    }
    return *lista;
}

no * inserirNoPosicao(no **lista, int valor, int posicao){
    no *novo = novoNo(valor);
    
    if(!novo){
        printf("\nErro: Falha ao alocar memória.\n");
        return *lista;
    }
    if(posicao == 0){
        novo->proximo = *lista;
        *lista = novo;
        printf("\nNovo no inserido na posicao %d.\n", posicao);
    }else{
        no *aux = *lista;
        int i;
        // Percorre até a posição anterior
        for(i = 0; i < posicao - 1 && aux != NULL; i++){
            aux = aux->proximo;
        }
        if(aux == NULL){
            printf("\nErro: Posicao invalida.\n");
            free(novo);
        }else{
            // Insere na posição desejada
            novo->proximo = aux->proximo;
            aux->proximo = novo;
            printf("\nNovo no inserido na posicao %d.\n", posicao);
        }
    }
    return *lista;
}

no * inserirNoFinal(no **lista, int valor){
    no *novo = novoNo(valor);
    
    if(!novo){
        printf("\nErro: Falha ao alocar memória.\n");
        return *lista;
    }
    if(*lista == NULL){
        *lista = novo;
    }else{
        no *aux = *lista;
        // Percorre até o último nó
        while (aux->proximo != NULL){
            aux = aux->proximo;
        }
        // Insere no final
        aux->proximo = novo;
        printf("\nNovo no inserido no final.\n");
    }
    return *lista;
}

no * removerNoPosicao(no **lista, int posicao){
    if(*lista == NULL){
        printf("\nErro: Lista vazia.\n");
        return *lista;
    }
    no *temp;
    if(posicao == 0){
        temp = *lista;
        *lista = (*lista)->proximo;
        free(temp);
        printf("\nNo na posicao %d removido.\n", posicao);
    }else{
        no *aux = *lista;
        int i;
        // Percorre até a posição anterior
        for(i = 0; i < posicao - 1 && aux != NULL; i++){
            aux = aux->proximo;
        }
        if(aux == NULL || aux->proximo == NULL){
            printf("\nErro: Posicao invalida.\n");
        }else{
            temp = aux->proximo;
            aux->proximo = temp->proximo;
            free(temp);
            printf("\nNo na posicao %d removido.\n", posicao);
        }
    }
    return *lista;
}

void exibirLista(no *lista){
    printf("\n-> Elementos da lissta:\n");
    while(lista != NULL){
        printf("> %d ", lista->valor);
        lista = lista->proximo;
    }
    printf("\n");
}

int main()
{
    no *lista = NULL;
    
    novoNo(2);
    inserirNoInicio(&lista, 1);
    inserirNoInicio(&lista, 3);
    inserirNoFinal(&lista, 0);
    inserirNoPosicao(&lista, 10, 2);
    inserirNoPosicao(&lista, 20, 1);
    inserirNoInicio(&lista, 99);
    inserirNoFinal(&lista, 100);
    exibirLista(lista);

    removerNoPosicao(&lista, 3);
    exibirLista(lista);
    
    return 0;
}