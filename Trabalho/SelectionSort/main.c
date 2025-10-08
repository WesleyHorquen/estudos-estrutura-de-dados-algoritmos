#include "ordenar.h"

int main(){
    srand(time(NULL));

    int tam;

    printf("\n> Digite o tamanho do vetor: ");
    scanf("%d", &tam);

    int metade = tam / 2;

    clock_t start, end;

    int *vetorInicial = criarVetor(tam); // Criacao do vetor inicial
    int *vetorCopiado = criarVetor(tam);
    int *vetorReverso = criarVetor(tam);

    vetorInicial = preencherVetor(vetorInicial, tam); // Preencher com valores aleatorio de 0 - 100
    copiarVetorInicial(vetorInicial, vetorCopiado, tam); //  Criamos uma copia para o vetor ainda nao ordenado
    
    start = clock(); // Processando sem alteracao, apenas exibindo
    printf("\n\t> Vetor inicial:\n");
    exibirVetor(vetorInicial, tam);
    end = clock();
    double tempo1 = ((double)(end - start)) / CLOCKS_PER_SEC;

    start = clock();
    printf("\n\t> Vetor Ordenado:\n");
    selectionSort(vetorCopiado, tam);
    end = clock();
    double tempo2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    
    start = clock();
    printf("\n\t> Ordenar Novamente o Vetor:\n");
    selectionSort(vetorCopiado, tam);
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

    start = clock();
    printf("\n\t> Vetor reverso\n");
    inverterVetor(vetorCopiado, vetorReverso, tam);
    end = clock();
    double tempo0 = ((double)(end-start))/ CLOCKS_PER_SEC;

    exibirTempo(tempo0, tempo1, tempo2, tempo3, tempo4, tempo5);

    free(vetorInicial);
    free(vetorCopiado);
    return 0;
}