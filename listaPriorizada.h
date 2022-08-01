#define SIZE 100

struct estruturaDoHeap {
    int* heaparray;
    int capacity;
    int size;
};
typedef struct estruturaDoHeap EstruturaDoHeap;

EstruturaDoHeap* inicializarHeap();
void rotearFuncoes(EstruturaDoHeap* h, int repostaUsuario);
void inserirNoHeap(EstruturaDoHeap* h, int newNum);
void ordenarHeap(EstruturaDoHeap* h, int i);
void trocarElementos(int *a, int *b);
void removerElementoDoHeap(EstruturaDoHeap* h, int num);
void imprimirHeap(EstruturaDoHeap* h);