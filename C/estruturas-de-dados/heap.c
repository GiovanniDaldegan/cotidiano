#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "./heap.h"


Heap* InitHeap(int size)
{
  Heap *h = malloc(sizeof(Heap));

  h->size = size;
  h->array = calloc(size, sizeof(int));

  return h;
}

int HeapSize(Heap *heap) {
  return heap->size;
}

int HeapMaxDepth(Heap *heap) {
  int i = 2, total = 1, count = 0;

  while (total < heap->size) {
    total += i;
    i *= 2;
    count++;
  }

  return count;
}

int HeapMisplacedKeys(int* array, int size)
{
  int misplacedKeys = array[0] > array[1] || array[0] > array[2];
  for (int i = 0; i < size; i++)
  {
    if (array[(i -1) /2] > array[i])
      misplacedKeys++;
  }

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
  // NOTE: realloc tem uma chance de falha quando lidando com concorrência?
  heap->array = realloc(heap->array, (heap->size +1) * sizeof(int));

  heap->array[heap->size] = key;
  heap->size++;

  HeapifyUp(heap, heap->size -1);
}

void HeapPullUp(Heap* heap, int index)
{
  int i_child = index * 2 +1;

  if (i_child > heap->size -1)
  {
    // se o nó não tiver filhos, puxar os próximos elementos do array
    if (index < heap->size -1)  
    {
      heap->array[index] = heap->array[index +1];
      HeapifyUp(heap, index);

      HeapPullUp(heap, index +1);
    }
    return;
  }

  if (i_child +1 > heap->size -1 ||
      heap->array[i_child] < heap->array[i_child +1])
  {
    heap->array[index] = heap->array[i_child];
    HeapPullUp(heap, i_child);
  }
  else
  {
    heap->array[index] = heap->array[i_child +1];
    HeapPullUp(heap, i_child +1);
  }
}

int HeapExtractKeyAt(Heap *heap, int index)
{
  int key = heap->array[index];
  HeapPullUp(heap, index);

  heap->size--;
  heap->array = realloc(heap->array, heap->size * sizeof(int));

  return key;
}

int HeapExtractMin(Heap *heap)
{
  return HeapExtractKeyAt(heap, 0);
}

void HeapPrintDetails(Heap* heap)
{
  int misplacedKeys = HeapMisplacedKeys(heap->array, heap->size);
  if (misplacedKeys > 0)
  {
    printf("\nO vetor não representa uma heap. Há %d valor(es) violando a "
           "ordem de heap.", misplacedKeys);
  }
  printf("\nVetor com %d elementos, representando uma árvore com profundidade "
         "%d", heap->size, HeapMaxDepth(heap));
}

void HeapPrintArray(Heap *heap, int reverse)
{
  printf("\nHeap");
  if (reverse)
    printf(" (invertida)");
  else
    reverse = -1;
  printf(": [");

  for (int i = 0; i < heap->size; i++)
  {
    printf("%d", heap->array[i]);
    if (i != heap->size -1)
      printf(" ");
  }
  printf("]");
}

void HeapPrintTree(Heap *heap, int reverse)
{
  int n_count = 0;

  for (int i = HeapMaxDepth(heap); i >= 0; i--)
  {
    // indentação
    for (int j = 0; j < indentation -1; j++)
      printf("      ");
    if (indentation > 0)
      printf("  ");

    int prev_count = n_count;
    while (n_count < heap->size && n_count - prev_count < i)
    {
      printf("%d", heap->array[n_count]);
      n_count++;

      // espaço entre números
      if (n_count - prev_count < i)
      {
        if ((n_count - prev_count) % 2 != 0 && indentation != 0) {
          for (int k = 0; k < indentation +1; k++)
          {
            printf("   ");
            if (k % 2 != 0)
              printf(" ");
          }
        }
        else
          printf("   ");
      }
    }

    indentation--;
    printf("\n");
  }
}

int main ()
{
  int size = 24;
  Heap *heap = InitHeap(size);

  for (int i = 0; i < size; i++)
    heap->array[i] = (size - i) / 10;


  HeapPrintArray(heap, 0);

  HeapPrintDetails(heap);

  Heapify(heap);

  printf("\n\nHeap ordenada.\n");
  HeapPrintArray(heap, 0);
  HeapPrintDetails(heap);

  printf("\n\nInserido 1 na heap.");
  HeapInsert(heap, 1);
  printf("\nInserido 0 na heap.");
  HeapInsert(heap, 0);
  printf("\nInserido 2 na heap.\n");
  HeapInsert(heap, 2);
  HeapPrintArray(heap, 0);
  HeapPrintDetails(heap);

  printf("\n\nRemovido #3 (%d)\n", HeapExtractKeyAt(heap, 2));
  printf("Removido #2 (%d)\n", HeapExtractKeyAt(heap, 1));
  printf("Removido #1 (%d)\n", HeapExtractKeyAt(heap, 0));
  HeapPrintArray(heap, 0);
  HeapPrintDetails(heap);

  printf("\n\nárvore da heap:\n");

  HeapPrintTree(heap, 0);

  Heap *a = InitHeap(15);
  printf("%d", HeapMaxDepth(a));

  return 0;
}
