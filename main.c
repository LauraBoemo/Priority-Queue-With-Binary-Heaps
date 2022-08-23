#include <stdio.h>
#include <stdlib.h>
#include "listaPriorizada.h"

int main() {
    EstruturaDoHeap* h;
    h = inicializarHeap();
    
    int repostaUsuario = 1;
  
    while (repostaUsuario != 4) {
        printf("O que desejas fazer?\n\n1. Inserir valor no Heap.\n2. Remover valor do Heap.\n3. Imprimir o Heap\n4. Sair do Programa\n\nDigite o numero desejado: ");
        scanf("%i", &repostaUsuario);
        rotearFuncoes(h, repostaUsuario);
    }  
    
    free(h);
    system("PAUSE");
    return 1;
}
