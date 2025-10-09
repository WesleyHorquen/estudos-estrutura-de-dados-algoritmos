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
    int *vetorInicioFim = criarVetor(tam);
    int *vetorFimInicio = criarVetor(tam);

    vetorInicial = preencherVetor(vetorInicial, tam); // Preencher com valores aleatorio de 0 - 100
    copiarVetorInicial(vetorInicial, vetorCopiado, tam); //  Criamos uma copia para o vetor ainda nao ordenado
    inverterVetor(vetorCopiado, vetorReverso, tam);
    
    ordenarMetadeInicial(vetorInicial, metade, tam);
    ordenarMetadeFinal(vetorInicial, metade, tam);

    
    start = clock();
    printf("\n\t> Vetor Ordenado:\n");
    selectionSort(vetorCopiado, tam);
    end = clock();
    double tempo1 = ((double)(end - start)) / CLOCKS_PER_SEC;
    exibirVetor(vetorInicial, tam);
    
    
    start = clock();
    printf("\n\t> Ordenar Novamente o Vetor:\n");
    selectionSort(vetorCopiado, tam);
    end = clock();
    double tempo2 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    printf("\n\t> Ordenar o vetor reverso:\n");
    selectionSort(vetorReverso, tam);
    end = clock();
    double tempo3 = ((double)(end-start))/ CLOCKS_PER_SEC;

    start = clock();
    printf("\n\t> Ordenar do inicio ate a metade:\n");
    end = clock();
    double tempo4 = ((double)(end - start)) / CLOCKS_PER_SEC;
    
    start = clock();
    printf("\n\t> Ordenar da metade ate o final:\n");
    end = clock();
    double tempo5 = ((double)(end - start)) / CLOCKS_PER_SEC;


    exibirTempo(tempo1, tempo2, tempo3, tempo4, tempo5);

    free(vetorInicial);
    free(vetorCopiado);
    free(vetorReverso);
    free(vetorInicioFim);
    free(vetorFimInicio);
    return 0;
}