/*
 * Referências:
 *  Algorithm Design - Jon Kleinber, Éva Tardos
 *  Heap (data structure) - Wikipedia
 *
 * mt obg pela sugestão de leitura, Nirva <3
 *
 * Explicação:
 *  Uma heap é uma estrutura de dados que representa, conceitualmente, uma
 *  árvore binária balanceada, podendo ser de dois tipos:
 *   - heap mínima, em que os valores dos nós são sempre menores que os valores
 *     de seus nós filhos (a raiz guarda o menor valor);
 *   - heap máxima, em que os valores dos nós são sempre maiores que os valores
 *     de seus nós filhos (a raiz guarda o maior valor);
 *
 *  Essa implementação leva em conta uma heap mínima que consiste em um vetor
 *  iniciado em 0, no qual o um nó de índice i tem seu nó pai com índice
 *  (i - 1) / 2, e os índices de seus filhos são 2i +1 e 2i +2, respectivamente.
 */

#ifndef HEAP_INT_H_
#define HEAP_INT_H_

typedef struct Heap
{
  int  size;
  int  *array;
} Heap;

Heap* InitHeap(int size);

/*
 * Retorna o tamanho da heap.
 */
int HeapSize(Heap *heap);

/*
 * Retorna a profundidade máxima da heap (no caso, a profundidade da folha mais
 * à esquerda).
 */
int HeapMaxDepth(Heap *heap);

/*
 * Percorre um vetor de heap iterativamente contando quantos nós tem valor maior
 * que seu nó pai e retorna o resultado da contagem. Se retornar 0, o vetor é
 * uma heap; se retornar um inteiro maior que 0, este inteiro representa o
 * número de nós que violam a ordem da heap.
 */
int HeapMisplacedKeys(int *heapArray, int size);


/*
 * Propaga o valor do índice passado na direção da raiz recursivamente, até que
 * ocupe a posição correta no vetor. Se o vetor for quase uma heap, com apenas o
 * valor do índice passado sendo pequeno demais para sua posição (dessa forma,
 * violando a ordem), o resultado final é uma heap.
 */
void HeapifyUp(Heap *heap, int index);

/*
 * Propaga o valor do índice passado na direção das folhas recursivamente, até
 * que ocupe a posição correta no vetor. Se o vetor for quase uma heap, com
 * apenas o valor do índice passado sendo grande demais para sua posição, o
 * resultado final é uma heap.
 */
void HeapifyDown(Heap *heap, int index);


/*
 * Ordena o vetor partindo do índice passado até as folhas chamando HeapifyUp no
 * índice passado e nos seus nós filhos recursivamente.
 */
void Heapify_r(Heap *heap, int index);

/*
 * Chama Heapify_r, passando o índice 0 (ordena toda a heap).
 */
void Heapify(Heap *heap);


/*
 * Insere um dado valor na última posição do vetor e chama HeapifyUp passando o
 * seu índice para garantir a ordem da heap. (considera que a heap está em
 * ordem)
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
 * Chama HeapPullUp passando o índice 0 e retorna o valor que ocupava a raiz.
 */
int HeapExtractMin(Heap *heap);


/*
 * Imprime detalhes da heap, como o número total de elementos e a profundidade
 * da árvore que ela representa.
 */
void HeapPrintDetails(Heap *heap);

/*
 * Imprime o vetor da heap de forma iterativa.
 */
void HeapPrintArray(Heap *heap, int reverse);

/*
 * Imprime árvore que representa a heap passada, de forma recursiva. Primeiro
 * calcula os espaços necessários e depois imprime a árvore a partir da raíz
 * (reverse=1 faz imprimir primeiro as folhas).
 */
void HeapPrintTree(Heap *heap, int reverse);

#endif  // HEAP_INT_H_
