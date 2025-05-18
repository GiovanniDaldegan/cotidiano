#ifndef LINKED_LIST_INT_H
#define LINKED_LIST_INT_H

#include "node.h"

typedef struct LinkedList
{
  int size;
  Node *head;
} LinkedList;


/*
  Aloca memória para uma nova lista encadeada, inicializa-a como vazia e retorna
  seu endereço.
*/
LinkedList *InitLinkedList();

/*
  Aloca memória para um novo nó, atribui a ele o valor passado e o insere na
  lista no índice especificado.
  - chamadas: node.h : InitNode()
  - retorna
    -1 se o índice estiver fora do limite;
     0 se a inserção ocorrer;
*/
int InsertAtLinkedList(LinkedList*, int, int);
/*
  Remove o nó da lista e libera sua memória.
  - retorna:
     0 se a remoção ocorrer;
    -1 se o índice estiver fora do limite.
*/
int RemoveAtLinkedList(LinkedList*, int);

/*
  Checa se a lista está vazia (se size = 0).
*/
int IsEmptyLinkedList(LinkedList*);
/*
  Percorre a lista iterativamente e checa se o valor está presente nela.
  - retorna:
    -1 se o índice estiver fora do limite;
     0 se a lista não estiver vazia;
     1 se a lista estiver vazia.
*/
int IsInLinkedList(LinkedList*, int);

/*
  Limpa a lista iterativamente a partir do início, liberando a memória de cada
  nó.
  - chamadas: RemoveAt()
*/
void ClearLinkedList(LinkedList*);
/*
  Limpa a lista e libera sua memória.
  - chamadas: ClearLinkedList()
*/
void DeleteLinkedList(LinkedList*);

/*
  Percorre a lista iterativamente e imprime seus valores no formato [<valor0>,
  <valor1>, ...].
*/
void PrintLinkedList(LinkedList*);
/*
  Imprime a lista recursivamente.
  - chamadas: PrintFromNodeLinkedList()
*/
void RecursivePrintLinkedList(LinkedList*, int);

#endif
