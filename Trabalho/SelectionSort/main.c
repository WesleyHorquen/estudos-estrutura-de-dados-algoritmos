#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int * criarVetor(int tam){
    if(tam <= 0){
        printf("> Tamanho invalido!\n");
        exit(1);
    }
    int *vetor = malloc(tam * sizeof(int));
    if(vetor == NULL){
        printf("> Erro ao alocar memoria!\n");
        exit(1);
    }
    return vetor;
}

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

void ordenarVetor(int *vetor, int tam){
    for(int i = 0; i < tam - 1; i++){
        int aux = i;
        for(int j = i + 1; j < tam; j++){
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
    exibirVetor(vetor, tam);
}


void copiarVetorInicial(int *vetorInicial, int *vetorOrdenado, int tam){
    for(int i = 0; i < tam; i++){
        vetorOrdenado[i] = vetorInicial[i];
    }
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

void exibirTempo(double t0, double t1, double t2, double t3, double t4, double t5){
    printf("\n\t> Tempos de execucao:\n");
    printf(" > Criar o vetor inicial: %lf segundos\n", t0);
    printf(" > Exibir vetor inicial: %lf segundos\n", t1);
    printf(" > Ordenar vetor: %lf segundos\n", t2);
    printf(" > Ordenar novamente o vetor: %lf segundos\n", t3);
    printf(" > Ordenar do inicio ate a metade: %lf segundos\n", t4);
    printf(" > Ordenar da metade ate o final: %lf segundos\n", t5);
}

int main(){
    srand(time(NULL));

    int tam;

    printf("\n> Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int metade = tam / 2;

    clock_t start, end;

    start = clock();
    int *vetorInicial = criarVetor(tam);
    end = clock();
    double tempo0 = ((double)(end - start)) / CLOCKS_PER_SEC;

    int *vetorCopiado = criarVetor(tam);
    vetorInicial = preencherVetor(vetorInicial, tam);

    start = clock();
    printf("\n\t> Vetor inicial:\n");
    exibirVetor(vetorInicial, tam);
    end = clock();
    double tempo1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    copiarVetorInicial(vetorInicial, vetorCopiado, tam);

    start = clock();
    printf("\n\t> Vetor Ordenado:\n");
    ordenarVetor(vetorCopiado, tam);
    end = clock();
    double tempo2 = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    printf("\n\t> Ordenar Novamente o Vetor:\n");
    ordenarVetor(vetorCopiado, tam);
    end = clock();
    double tempo3 = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    printf("\n\t> Ordenar do inicio ate a metade:\n");
    ordenarMetadeInicial(vetorInicial, metade, tam);
    end = clock();
    double tempo4 = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    printf("\n\t> Ordenar da metade ate o final:\n");
    ordenarMetadeFinal(vetorInicial, metade, tam);
    end = clock();
    double tempo5 = ((double)(end - start)) / CLOCKS_PER_SEC;

    exibirTempo(tempo0, tempo1, tempo2, tempo3, tempo4, tempo5);

    printf("\n");
    free(vetorInicial);
    free(vetorCopiado);
    return 0;
}