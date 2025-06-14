#include <stdlib.h>
#include <stdio.h>

#include "./heap.h"


Heap* InitHeap(int size)
{
  Heap *h = malloc(sizeof(Heap));

  h->size = size;
  h->array = calloc(size, sizeof(int));

  return h;
}

int HeapMisplacedKeys(int* array, int size)
{
  int misplacedKeys = array[0] > array[1] || array[0] > array[2];
  for (int i = 0; i < size; i++)
  {
    if (array[(i -1) /2] > array[i])
    {
      printf("%d ",i);
      misplacedKeys++;
    }
  }
  printf("\n");

  return misplacedKeys;
}

void HeapifyUp(Heap *heap, int index)
{
  if (index > heap->size -1 || index < 1)
    return;

  int i_parent = (index - 1) / 2;
  if (heap->array[i_parent] > heap->array[index])
  {
    int parent = heap->array[i_parent];
    heap->array[i_parent] = heap->array[index];
    heap->array[index] = parent;
  }

  HeapifyUp(heap, i_parent);
}

void HeapifyDown(Heap *heap, int index)
{
  int i_child = index *2 +1;

  if (i_child > heap->size -1)
    return;

  if (!(heap->array[index] > heap->array[i_child]))
  {
    if (!(heap->array[index] > heap->array[i_child +1]))
      return; 

    i_child++;
  }

  int child = heap->array[i_child];
  heap->array[i_child] = heap->array[index];
  heap->array[index] = child;

  HeapifyDown(heap, i_child);
}

void Heapify_r(Heap *heap, int index)
{
  int i_child = index *2 +1;

  if (heap->size <= 1 || index < 0 || index > heap->size -1) {
    return;
  }

  HeapifyUp(heap, index);

  Heapify_r(heap, i_child);
  if (i_child +1 <= heap->size -1)
    Heapify_r(heap, i_child +1);
}

void Heapify(Heap *heap)
{
  Heapify_r(heap, 0);
}


void HeapInsert(Heap *heap, int key)
{

}

/*
void DeleteElem(Heap *heap, int index)
{}

int ExtractMin(Heap *heap, int index)
*/

void HeapPrintDetails(Heap* heap)
{
  int misplacedKeys = HeapMisplacedKeys(heap->array, heap->size);
  if (misplacedKeys > 0)
  {
    printf("O vetor não representa uma heap. Há %d valores que violam a ordem "
           "de uma heap.\n", misplacedKeys);
  }
  printf("Vetor com %d elementos, representando uma árvore com profundidade"
         "floor(log(%d))\n", heap->size, heap->size);
}

void HeapPrintArray(Heap *heap, int reverse)
{
  printf("Heap");
  if (reverse)
    printf(" (invertida)");
  else
    reverse = -1;
  printf(": ");

  for (int i = 0; i < heap->size; i++)
    printf("%d ", heap->array[i]);
  printf("\n");
}


int main ()
{
  int size = 24;
  Heap *heap = InitHeap(size);

  for (int i = 0; i < size; i++)
    heap->array[i] = size - i;

  heap->array[0] = 0;

  HeapPrintArray(heap, 0);
  printf("\n");

  HeapPrintDetails(heap);
  printf("\n");

  Heapify(heap);

  HeapPrintArray(heap, 0);
  printf("\n");

  HeapPrintDetails(heap);

  return 0;
}
