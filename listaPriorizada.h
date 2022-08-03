#define SIZE 100

struct estruturaDoHeap {
    int* heaparray;
    int capacity;
    int size;
};
typedef struct estruturaDoHeap EstruturaDoHeap;

EstruturaDoHeap* inicializarHeap();

void rotearFuncoes(EstruturaDoHeap* h, int repostaUsuario);

void trocarElementos(int *a, int *b);

void ordenarHeap(EstruturaDoHeap* h, int i);
void inserirNoHeap(EstruturaDoHeap* h, int newNum);
void removerElementoDoHeap(EstruturaDoHeap* h, int num);

void imprimirArray(EstruturaDoHeap* h);
void imprimirHeap(EstruturaDoHeap* h);
