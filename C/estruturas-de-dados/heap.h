/*
 * Referência: Algorithm Design - Jon Kleinber, Éva Tardos
 * mt obg pela sugestão de leitura, Nirva <3
 *
 * Explicação:
 *  Uma heap é uma estrutura de dados que representa, conceitualmente, uma
 *  árvore binária balanceada na qual o valor de um nó sempre é menor que o
 *  valor de seus nós filhos.
 *
 *  Nessa implementação, a heap é representada por um vetor iniciado em 0, em
 *  que o índice do pai de um nó de índice i é dado por (i - 1) / 2, e o índice
 *  de seus filhos são 2 * i + 1 e 2 * i + 2, respectivamente.
 */

#ifndef HEAP_INT_H_
#define HEAP_INT_H_

typedef struct Heap
{
  int  size;
  int  *array;
  // TODO: int* Positions  ()
} Heap;

Heap* InitHeap(int size);


/*
 * Percorre um vetor iterativamente contando quantos nós tem valor maior que
 * seu nó pai e retorna o resultado da contagem. Se retornar 0, o vetor é uma
 * heap; se retornar um inteiro maior que 0, este inteiro representa o número
 * de nós que violam as regras da heap.
 */
int HeapMisplacedKeys(int *heapArray, int size);

/*
 * Propaga o valor do índice passado na direção da raiz recursivamente, até que
 * ocupe o lugar correto no vetor. Se o vetor for quase uma heap, a menos que o
 * valor do índice passado seja pequeno demais para sua posição, o resultado
 * final é uma heap.
 */
void HeapifyUp(Heap *heap, int index);
/*
 * Propaga o valor do índice passado na direção das folhas recursivamente, até
 * que  * ocupe o lugar correto no vetor. Se o vetor for quase uma heap, a
 * menos que o valor do índice passado seja grande demais para sua posição, o
 * resultado final é uma heap.
 */
void HeapifyDown(Heap *heap, int index);

/*
 * Ordena o vetor a partir do índice passado para que cumpra os requisitos de
 * uma heap ao chamar HeapifyUp no índice passado e agir recursivamente nos
 * índices dos nós filhos do nó do índice passado.
 */
void Heapify_r(Heap *heap, int index);
/*
 * Chama Heapify_r, passando o índice 0 (ordena toda a heap).
 */
void Heapify(Heap *heap);

/*
 * Insere um valor na heap.
 * Primeiro, insere ele na última posição e chama HeapifyUp passando o índice
 * desse valor para garantir a ordem da heap.
 */
void HeapInsert(Heap *heap, int key);

/*
 * É chamada quando há um espaço considerado vazio na heap, cujo índice é
 * passado à função para que seja preenchido.
 * A função puxa o nó filho de menor valor para ocupar o dado índice; se não
 * houver nó filho, puxa o próximo elemento do vetor da heap para mantê-la
 * balanceada.
 * Sempre que puxa um nó, chama HeapifyUp passando seu índice para garantir a
 * ordem da heap e, então, HeapPullUp passando seu índice, propagando
 * recursivamente a atualização da heap.
 */
void HeapPullUp(Heap *heap, int index);

/*
 * Extrai o valor da heap no índice passado.
 * Chama HeapPullUp no índice passado e retorna o valor que ocupava esse
 * índice.
 */
int HeapExtractKeyAt(Heap *heap, int index);

/*
 * Extrai o valor mínimo da heap.
 * Chama HeapPullUp passando o índice 0.
 */
int HeapExtractMin(Heap *heap);

/*
 * Imprime detalhes da heap, como o número total de elementos e a profundidade
 * da árvore que ela representa.
 */
void HeapPrintDetails(Heap *heap);
/*
 * Imprime árvore que representa a heap passada, de forma recursiva. Primeiro
 * calcula os espaços necessários e depois imprime a árvore a partir da raíz
 * (reverse=1 faz imprimir primeiro as folhas).
 */
void HeapPrintTree(Heap *heap, int reverse);
/*
 * Imprime o vetor da heap de forma iterativa.
 */
void HeapPrintArray(Heap *heap, int reverse);

#endif
