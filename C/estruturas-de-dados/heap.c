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

void HeapifyUp(Heap *heap, int index)
{
  if (index > heap->size || index < 0)
    return;

  int i_parent = (index - 1) / 2;
  if (&(heap->array[index]) != heap->array)
  {
    if (heap->array[i_parent] > heap->array[index])
    {
      int parent = heap->array[i_parent];
      heap->array[i_parent] = heap->array[index];
      heap->array[index] = parent;

      printf("Troca elemento #%d (%d) com #%d (%d)\n",
             i_parent, parent, index, heap->array[i_parent]);
    }
  }
}


int main ()
{
  Heap *heap = InitHeap(10);

  for (int i = 0; i < 10; i++)
    heap->array[i] = 11 - i;

  HeapifyUp(heap, 1);
  HeapifyUp(heap, 9);

  return 0;
}
