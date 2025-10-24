#include "ordenar.h"
#include <time.h>

int main(void) {
	srand(time(NULL));

	int *vetor, *vetorDecr, *vetorEspecial1, *vetorEspecial2;
	clock_t inicio, fim;
	double tempo1, tempo2, tempo3, tempo4, tempo5;
    
    vetor = criarVetor();
    preencher(vetor);

	printf("\t> Ordernar array aleatorio\n");
	exibir(vetor);
	inicio = clock();
	selectionSort(vetor);
	fim = clock();
	tempo1 = (double)(fim - inicio)/ CLOCKS_PER_SEC;

	printf("\t> Ordernar array ordenado\n");
	exibir(vetor);
	inicio = clock();
	selectionSort(vetor);
	fim = clock();
	tempo2 = (double)(fim - inicio)/ CLOCKS_PER_SEC;

	vetorDecr = inverterVetor(vetor);
	
	printf("\t> Ordernar array decrescente\n");
	exibir(vetorDecr);
	inicio = clock();
	selectionSort(vetorDecr);
	fim = clock();
	tempo3 = (double)(fim - inicio)/ CLOCKS_PER_SEC;
	
	vetorDecr = inverterVetor(vetor);
	vetorEspecial1 = criarVetorEsp1(vetor, vetorDecr);
	
	printf("\t> Ordernar array primeira metade cresc. e segunda metade decre.:\n");
	exibir(vetorEspecial1);
	inicio = clock();
	selectionSort(vetorEspecial1);
	fim = clock();
	tempo4 = (double)(fim - inicio)/ CLOCKS_PER_SEC;

	vetorDecr = inverterVetor(vetor);
	vetorEspecial2 = criarVetorEsp2(vetor, vetorDecr);

	printf("\t> Ordernar array primeira metade decre. e segunda metade cresc.:\n");
	exibir(vetorEspecial2);
	inicio = clock();
	selectionSort(vetorEspecial2);
	fim = clock();
	tempo5 = (double)(fim - inicio)/ CLOCKS_PER_SEC;

	exibirTempo(tempo1, tempo2, tempo3, tempo4, tempo5);

	free(vetor);
	free(vetorDecr);
	free(vetorEspecial1);
	return 0;
}

