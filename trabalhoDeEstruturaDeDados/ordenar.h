#ifndef ORDENAR_H_INCLUDED
#define ORDENAR_H_INCLUDED

#define TAM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *criarVetor();
void exibir(int *vetor);
void exibirTempo(double tempo1, double tempo2, double tempo3, double tempo4, double tempo5);
int *selectionSort(int *vetor);
void preencher(int *vetor);
int *inverterVetor(int *vetor);
int *criarVetorEsp1(int *vetorCresc, int *vetorDecre);
int *criarVetorEsp2(int *vetorCresc, int *vetorDecre);

#endif