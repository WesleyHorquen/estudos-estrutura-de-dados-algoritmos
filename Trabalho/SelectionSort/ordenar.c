#include "ordenar.h"

// Ele criar um vetor alocando mémoria dinamicamente
int * criarVetor(int tam){
    if(tam <= 0){
        printf("> Tamanho invalido!\n");// Caso tamanho seja 0 ele é inválido
        exit(1);
    }

    int *vetor = malloc(tam * sizeof(int)); // Faz a alocação dinâmica

    if(vetor == NULL){
        printf("> Erro ao alocar memoria!\n"); // Verifica se foi alocado certo
        exit(1);
    }
    return vetor; // Caso a alocação e o tamanho seja válido ele retorna o ponteiro do meu vetor
}

// Função pra preencher o vetor com valores aleatórios de 0 a 100
int * preencherVetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        vetor[i] = rand() % 101;
    }
    return vetor;
}

void exibirVetor(int *vetor, int tam){
    for(int i = 0; i < tam; i++){
        printf("| %d ", vetor[i]);
    }
    printf("|\n");
}

// Função Selection Sort
void selectionSort(int *vetor, int tam){
    for(int i = 0; i < tam - 1; i++){
        int aux = i; // Inicia com o auxiliar dizendo que é o menor valor
        for(int j = i + 1; j < tam; j++){
            if(vetor[j] < vetor[aux]){ // Faz a seunda interação pra passar por todos os valores do vetor e comparar se o atual é menor ou maior
                aux = j; // Se for menro faz a troca
            }
        }
        if(aux != i){ // Caso o menor valor esteja em outra possição diferente de da vetor[i]
            int temp = vetor[i];
            vetor[i] = vetor[aux];
            vetor[aux] = temp; // Fazemos a troca deles
        }
    }
    exibirVetor(vetor, tam);
}

void copiarVetorInicial(int *vetorInicial, int *vetorOrdenado, int tam){
    for(int i = 0; i < tam; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
}

// Funçaão para fazer um vetor reverso
void inverterVetor(int *vetorOrdenado, int *vetorReverso, int tam){
    int j = 0;
    for(int i = tam -1;i >= 0;i--){
        vetorReverso[j] = vetorOrdenado[i];
        j++;
    }
    exibirVetor(vetorReverso, tam); // Teste
}

void ordenarTrecho(int *vetor, int inicio, int fim){
    for(int i = inicio; i < fim; i++){
        int aux = i;
        for(int j = i + 1; j < fim; j++){
            if(vetor[j] < vetor[aux]){
                aux = j;
            }
        }
        if(aux != i){
            int temp = vetor[i];
            vetor[i] = vetor[aux];
            vetor[aux] = temp;
        }
    }
}

void ordenarMetadeInicial(int *vetor, int metade, int tam){
    ordenarTrecho(vetor, 0, metade);
    exibirVetor(vetor, tam);
}

void ordenarMetadeFinal(int *vetor, int metade, int tam){
    ordenarTrecho(vetor, metade, tam);
    exibirVetor(vetor, tam);
}

void exibirTempo(double t1, double t2, double t3, double t4, double t5){
    printf("\n\t> Tempos de execucao:\n");
    printf(" > Ordenar vetor: %lf segundos\n", t1);
    printf(" > Ordenar vetor ordenado: %lf segundos\n", t2);
    printf(" > Ordenar o vetor reverso: %lf segundos\n", t3);
    printf(" > Ordenar do inicio ate a metade: %lf segundos\n", t4);
    printf(" > Ordenar da metade ate o final: %lf segundos\n", t5);
}
