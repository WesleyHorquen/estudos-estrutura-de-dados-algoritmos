#include "ordenar.h"

int *criarVetor(){
    int *vetor = malloc(TAM * sizeof(int));
    return vetor;  
}

void exibir(int *vetor){
	for(int i=0; i < TAM; i++) {
		printf(" %d |", *vetor);
		vetor++;
	}
    printf("\n");
}

void exibirTempo(double tempo1, double tempo2, double tempo3, double tempo4, double tempo5){
    printf("\n\t> Tempos de execucao\n");
    printf("Tempo de ordernar uma array aleatorio: %f sec\n", tempo1);
    printf("Tempo de ordernar uma array ordenado: %f sec\n", tempo2);
    printf("Tempo de ordernar uma array decrescente: %f sec\n", tempo3);
    printf("Tempo de ordernar uma primeira metade cresc. e segunda metade decre.: %f sec\n", tempo4);
    printf("Tempo de ordernar uma primeira metade decre. e segunda metade cresc.: %f sec\n", tempo5);
}

int *selectionSort(int *vetor){
    int i, j, indiceMenor, temp;

    for (i = 0; i < TAM - 1; i++) {
        indiceMenor = i;

        for (j = i + 1; j < TAM; j++) {
            if (vetor[j] < vetor[indiceMenor]) {
                indiceMenor = j;
            }
        }
        if (indiceMenor != i) {
            temp = vetor[i];
            vetor[i] = vetor[indiceMenor];
            vetor[indiceMenor] = temp;
        }
    }
    return vetor;
}

void preencher(int *vetor){
	for(int i = 0; i < TAM; i++)
        vetor[i] = rand()% (TAM+1);
}

int *inverterVetor(int *vetor){
    int *vetorDecrescente = criarVetor(), j = 0;
    for(int i = TAM-1; i >= 0; i--){
        vetorDecrescente[j] = vetor[i];
        j++;
    }
    return vetorDecrescente;
}

// 1 2 3 4 5 6 7 8 9 10

// 1 2 3 4 5 10 9 8 7 6
// 5 4 3 2 1 10 9 8 7 6

int *criarVetorEsp1(int *vetorCresc, int *vetorDecre){
    int *novoVetor = criarVetor();
    int c = 0;
    for(int i = 0; i < TAM/2; i++){
        novoVetor[i] = vetorCresc[i];
    }
    
    for(int i = TAM/2; i < TAM; i++){
        novoVetor[i] = vetorDecre[c];
        c++;
    }

    return novoVetor;
}

int *criarVetorEsp2(int *vetorCresc, int *vetorDecre){
    int *novoVetor = criarVetor();
    int c = TAM/2 - 1;
    for(int i = 0; i < TAM/2; i++){
        novoVetor[i] = vetorCresc[c];
        c--;
    }
    c = TAM/2 - 1;
    for(int i = TAM/2; i < TAM; i++){
        novoVetor[i] = vetorDecre[c];
        c--;
        
    }
    return novoVetor;
}