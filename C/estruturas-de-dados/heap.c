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

/*
int IsHeap(int* index, int elementsLeft)
{
  if (elementsLeft == 0)
    return;
}
*/

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

    printf("Troca elemento #%d (%d) com #%d (%d)\n",
           i_parent + 1, parent, index + 1, heap->array[i_parent]);
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
  else
  {
    int child = heap->array[i_child];
    heap->array[i_child] = heap->array[index];
    heap->array[index] = child;

    printf("Troca elemento #%d (%d) com #%d (%d)\n",
           index + 1, heap->array[i_child], i_child + 1, child);
 }

  HeapifyDown(heap, i_child);
}

void Heapify_r(Heap *heap, int index)
{
  for (int i = 0; i < (index+1) / 2; i++)
    printf(" ");
  printf("index: %d\n", index);
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
  printf("heap com %d elementos, com profundidade floor(log(%d))\n", heap->size, heap->size);
  Heapify_r(heap, 0);
  /*
  while (heap->array[0] > heap->array[1] ||
         heap->array[0] > heap->array[2])
    HeapifyDown(heap, 0);
  */
}

void HeapPrintArray(Heap *heap, int reverse)
{
  printf("heap");
  if (reverse)
    printf(" (invertida)");
  else
    reverse = -1;
  printf(": ");
  
  for (int i = 0; i < heap->size; i++)
    printf("%d ", heap->array[i]);
    //printf("%d ", heap->array[heap->size * reverse + (-reverse) * i]);
  printf("\n");
}

int main ()
{
  Heap *heap = InitHeap(11);

  for (int i = 0; i < 11; i++)
    heap->array[i] = 11 - i;

  /*
  printf("Heapify up:\n");
  HeapifyUp(heap, 9);

  printf("Heapify down:\n");
  HeapifyDown(heap, 1);
  */

  Heapify(heap);
  HeapPrintArray(heap, 0);

  return 0;
}
