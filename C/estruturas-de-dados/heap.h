/*
 * Referência: Algorithm Design - Jon Kleinber, Éva Tardos
 * mt obg pela sugestão de leitura, Nirva <3
 *
 * Explicação:
 *  Uma heap é uma estrutura de dados que representa, conceitualmente, uma
 *  árvore binária balanceada na qual o valor de um nó sempre é menor que o
 *  valor de seus nós filhos.
 *
 *  Nessa implementação, a heap é representada por um array iniciado em 0, em
 *  que o índice do pai de um nó de índice i é dado por (i - 1) / 2, e o índice
 *  de seus filhos são 2 * i + 1 e 2 * i + 2, respectivamente.
 */

#ifndef HEAP_INT_H_
#define HEAP_INT_H_

typedef struct Heap
{
  int  size;
  int  *array;
} Heap;

Heap* InitHeap(int size);

int IsHeap(int* heapArray);

/*
 * Propaga o valor do índice passado na direção da raiz recursivamente, até que
 * ocupe o lugar correto no array. Se o array for quase uma heap, a menos que o
 * valor do índice passado seja pequeno demais para sua posição, o resultado
 * final é uma heap.
 */
void HeapifyUp(Heap* heap, int index);
/*
 * Propaga o valor do índice passado na direção das folhas recursivamente, até
 * que  * ocupe o lugar correto no array. Se o array for quase uma heap, a
 * menos que o valor do índice passado seja grande demais para sua posição, o
 * resultado final é uma heap.
 */
void HeapifyDown(Heap* heap, int index);

/*
 * Ordena o array a partir do índice passado para que cumpra os requisitos de
 * uma heap ao chamar HeapifyUp no índice passado e agir recursivamente nos
 * índices dos nós filhos do nó do índice passado.
 */
void Heapify_r(Heap* heap, int index);
/*
 * Chama Heapify_r, passando o índice 0 (ordena toda a heap).
 */
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
/*
 * Imprime o array da heap de forma iterativa.
 */
void HeapPrintArray(Heap* heap, int reverse);
/*
 * Imprime detalhes da heap, como o número total de elementos e a profundidade
 * da árvore que ela representa.
 */
void HeapPrintDetails(Heap* heap);

#endif
