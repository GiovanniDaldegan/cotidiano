#ifndef STACK_INT_H
#define STACK_INT_H

#include "node.h"

typedef struct Stack
{
  int size;
  Node* top;
} Stack;

/*
  Aloca espaço para uma nova pilha, inicializa-a e como vazia e retorna seu
  endereço.
*/
Stack* InitStack();

/*
  Instancia um novo nó, atribui seu valor e o insere no topo da pilha.
  - chamadas: InitNode()
*/
void Push(Stack*, int);
/*
  Remove o nó do topo da pilha e libera sua memória.
*/
void Pop(Stack*);

/*
  Checa se a pilha está vazia (se size = 0).
*/
int IsEmptyStack(Stack*);
/*
  Checa se o valor está na pilha.
  - chamadas: IsEmptyStack()
 */
int IsInStack(Stack*, int);

/*
  Remove todos os nós da pilha a partir do topo.
*/
void ClearStack(Stack*);
/*
  Remove todos os nós da pilha e libera sua memória.
  - chamadas: ClearStack()
*/
void DeleteStack(Stack*);

/*
  Imprime a sequência da pilha de cima pra baixo no formato "top -> <top>
  <top-1> ..." (reverse = 1 inverte a ordem).
  - chamadas: PrintNode_r()
*/
void PrintStack(Stack*, int);

#endif
