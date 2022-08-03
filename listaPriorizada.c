#include <stdio.h>
#include <stdlib.h>
#include "listaPriorizada.h"

void rotearFuncoes(EstruturaDoHeap* h, int repostaUsuario) {
    int valor = 0;
    
    switch(repostaUsuario) {
        case 1:
            printf("\nInforme o valor que desejas inserir: ");
            scanf("%i", &valor);
            inserirNoHeap(h, valor);
            printf("\n\n");
            break;
        case 2: 
            printf("\nInforme o valor que desejas remover: ");
            scanf("%i", &valor);
            removerElementoDoHeap(h, valor);
            printf("\n\n");
            break;
        case 3: 
            printf("\nImprimindo a Lista Priorizada dos valores...\n\n");
            imprimirArray(h);
            printf("\n\nImprimindo a Lista Priorizada em formato de Heap...\n\n");
            imprimirHeap(h);
            printf("\n\n");
            break;
        case 4: 
            printf("\nO programa foi encerrado.");
            break;
        default:
            printf("\nInsira um valor valido!\n\n");
            break;
    }
}

EstruturaDoHeap* inicializarHeap() {
    EstruturaDoHeap* h = (EstruturaDoHeap*) malloc(sizeof(EstruturaDoHeap));
    h->capacity = SIZE;
    h->heaparray = (int*)malloc(sizeof(int)*(SIZE+1));
    h->size = 0;
}

void trocarElementos(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void ordenarHeap(EstruturaDoHeap* h, int i) {
    if (h->size > 1) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        
        if (l < h->size && h->heaparray[l] > h->heaparray[largest])
            largest = l;
        if (r < h->size && h->heaparray[r] > h->heaparray[largest])
            largest = r;
        
        if (largest != i) {
            trocarElementos(&h->heaparray[i], &h->heaparray[largest]);
            ordenarHeap(h, largest);
        }
    }
}

void inserirNoHeap(EstruturaDoHeap* h, int newNum) {
    if (h->size != 0) {
        for (int i = (((h->size)/2) - 1); i >= 0; i--) {
            ordenarHeap(h, i);
        }
    }

    h->heaparray[h->size] = newNum;
    h->size += 1;
    
    for (int i = (((h->size)/2) - 1); i >= 0; i--) {
        ordenarHeap(h, i);
    }
}

void removerElementoDoHeap(EstruturaDoHeap* h, int num) {
    int i;
    for (i = 0; i < h->size; i++) {
        if (num == h->heaparray[i])
            break;
    }
    
    trocarElementos(&h->heaparray[i], &h->heaparray[h->size - 1]);
    h->size -= 1;
    
    for (int i = (((h->size)/2) - 1); i >= 0; i--) {
        ordenarHeap(h, i);
    }
}

void imprimirArray(EstruturaDoHeap* h) {
    for (int i = 0; i < h->size; ++i) {
        printf("%d ", h->heaparray[i]);
    }
}

void imprimirHeap(EstruturaDoHeap* h) {
    int contadorLinhas = 2, auxContador = 0;
    
    for (int i = 0; i < h->size; ++i) {
        if(i == 0) {
            printf("%d\n\n", h->heaparray[i]);
        } else {
            printf("%d ", h->heaparray[i]);
            auxContador += 1;
        }
        
        if(auxContador == contadorLinhas) {
            printf("\n\n");
            contadorLinhas = contadorLinhas * 2 + contadorLinhas;
        }
    }
    
    printf("\n");
}
