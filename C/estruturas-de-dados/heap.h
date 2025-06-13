#ifndef HEAP_INT_H_
#define HEAP_INT_H_

// childLeft(i) = 2i +1
// parent(i) = (i - 1) /2

typedef struct Heap
{
  int  size;
  int  *array;
} Heap;

Heap* InitHeap(int size);

int IsHeap(int* heapArray);

void HeapifyDown(Heap* heap, int index);
void HeapifyUp(Heap* heap, int index);
void Heapify_r(Heap* heap, int index);
void Heapify(Heap* heap);

void HeapInsert(Heap* heap, int key);

void HeapDeleteElem(Heap* heap, int key);
void HeapExtractMin(Heap* heap);

/*
 * Imprime árvore que representa a heap passada, de forma recursiva. Primeiro
 * calcula os espaços necessários e depois imprime a árvore a partir da raíz
 * (reverse=1 faz imprimir primeiro as folhas).
 */
void HeapPrintTree(Heap* heap, int reverse);
void HeapPrintArray(Heap* heap, int reverse);
void HeapPrintDetails(Heap* heap);

#endif
