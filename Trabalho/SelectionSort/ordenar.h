#ifndef ORDENAR_H_INCLUDED
#define ORDENAR_H_INCLUDED
#define TAM 10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int *criarVetor(int tam);
int *preencherVetor(int *vetor, int tam);
void exibirVetor(int *vetor, int tam);
void selectionSort(int *vetor, int tam);
void copiarVetorInicial(int *vetorInicial, int *vetorOrdenado, int tam);
void inverterVetor(int *vetorOrdenado, int *vetorReverso, int tam);
void ordenarTrecho(int *vetor, int inicio, int fim);
void criarVetorComMetade(int *vetorOrdenado, int *vetorOrdenadoReverso, int *novoVetor,int tam);
void ordenarMetadeInicial(int *vetor, int metade, int tam);
void ordenarMetadeFinal(int *vetor, int metade, int tam);
void exibirTempo(double t1, double t2, double t3, double t4, double t5);

#endif