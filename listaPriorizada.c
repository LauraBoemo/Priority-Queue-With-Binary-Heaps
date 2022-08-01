#include <stdio.h>
#include <stdlib.h>
#include "listaPriorizada.h"

int size = 0;

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
    for (int i = h->size; i >= 0; i--) {
      ordenarHeap(h, i);
    }
  }
  
  h->heaparray[h->size] = newNum;
  h->size += 1;
}

void removerElementoDoHeap(EstruturaDoHeap* h, int num) {
  int i;
  for (int i = 0; i < h->size; i++) {
    if (num == h->heaparray[i])
      break;
  }

  trocarElementos(&h->heaparray[i], &h->heaparray[size - 1]);
  h->size -= 1;
  for (int i = h->size; i >= 0; i--) {
    ordenarHeap(h, i);
  }
}


void imprimirHeap(EstruturaDoHeap* h) {
  for (int i = 0; i < h->size; ++i)
    printf("%d ", h->heaparray[i]);
  printf("\n");
}