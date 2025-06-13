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
  
  int child = heap->array[i_child];
  heap->array[i_child] = heap->array[index];
  heap->array[index] = child;

  printf("Troca elemento #%d (%d) com #%d (%d)\n",
         index + 1, heap->array[i_child], i_child + 1, child);

  HeapifyDown(heap, i_child);
}

int main ()
{
  Heap *heap = InitHeap(10);

  for (int i = 0; i < 10; i++)
    heap->array[i] = 11 - i;

  //HeapifyUp(heap, 1);
  //printf("Heapify up:\n");
  //HeapifyUp(heap, 9);
  printf("Heapify down:\n");
  HeapifyDown(heap, 1);

  printf("heap:\n");
  for (int i = 0; i < heap->size; i++)
    printf("%d ", heap->array[i]);
  printf("\n");

  return 0;
}
