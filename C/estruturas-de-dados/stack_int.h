#ifndef STACK_INT_H
#define STACK_INT_H

#include "node.c"

struct Stack
{
  int size;
  struct Node* top;
};

/*
  Aloca espaço para uma nova pilha, inicializa-a e como vazia e retorna seu
  endereço.
*/
struct Stack* InitStack();


/*
  Instancia um novo nó, atribui seu valor e o insere no topo da pilha.
  - chamadas: InitNode()
*/
void Push(struct Stack*, int value);
/*
  Remove o nó do topo da pilha e libera sua memória.
*/
void Pop(struct Stack*);

/*
  Checa se a pilha está vazia (se size = 0).
*/
int IsEmptyStack(struct Stack*);
/*
  Checa se o valor está na pilha.
  - chamadas: IsEmptyStack()
 */
int IsInStack(struct Stack*, int);

/*
  Remove todos os nós da pilha a partir do topo.
*/
void ClearStack(struct Stack*);
/*
  Remove todos os nós da pilha e libera sua memória.
  - chamadas: ClearStack()
*/
void DeleteStack(struct Stack*);

/*
  Imprime o valor do nó e chama PrintNode(lower) passando o ponteiro do nó
  abaixo na pilha (reverse = 1 inverte a ordem).
  - chamadas: PrintNode_r()
*/
void PrintNode_r(struct Node*, int);
/*
  Imprime a sequência da pilha de cima pra baixo no formato "top -> <top>
  <top-1> ..." (reverse = 1 inverte a ordem).
  - chamadas: PrintNode_r()
*/
void PrintStack(struct Stack*, int);

#endif
