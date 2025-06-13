#ifndef HEAP_INT_H_
#define HEAP_INT_H_

// childLeft(i) = 2i + 1
// parent(i) = (i - 1) /2

typedef struct Heap
{
  int  size;
  int  *array;
} Heap;

Heap* InitHeap(int);

void InsertHeap(Heap*, int);
void HeapifyDown(Heap*, int);
void HeapifyUp(Heap*, int);

void HeapDeleteElem(Heap*, int);
void HeapExtractMin(Heap*);

/*
 * Imprime árvore que representa a heap passada, de forma recursiva. Primeiro
 * calcula os espaços necessários e depois imprime a árvore a partir da raíz
 * (reverse faz imprimir primeiro as folhas).
 */
void HeapPrintTree(Heap*, int reverse);

#endif
