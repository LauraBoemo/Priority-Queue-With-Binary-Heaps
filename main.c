#include <stdio.h>
#include "listaPriorizada.h"

int main() {
  EstruturaDoHeap* h;
  h = inicializarHeap();

  inserirNoHeap(h, 3);
  inserirNoHeap(h, 4);
  inserirNoHeap(h, 9);
  inserirNoHeap(h, 5);
  inserirNoHeap(h, 2);

  printf("Max-Heap: ");
  imprimirHeap(h);

  removerElementoDoHeap(h, 4);
  printf("Deletando um elemento: ");
  imprimirHeap(h);
}