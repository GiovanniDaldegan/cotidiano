#include <stdio.h>

#include "node.c"
#include "stack_int.c"
#include "linked_list_int.c"

int TestLinkedList() {
  LinkedList* list = InitLinkedList();

  InsertAtLinkedList(list, 2, 0);
  InsertAtLinkedList(list, 4, 1);
  InsertAtLinkedList(list, 1, 0);
  InsertAtLinkedList(list, 3, -2);
  InsertAtLinkedList(list, 0, 0);
  InsertAtLinkedList(list, 3, -7);
  InsertAtLinkedList(list, 3, 37);
  InsertAtLinkedList(list, 5, -1);
  InsertAtLinkedList(list, 6, -1);

  RemoveAtLinkedList(list, -1);
  RemoveAtLinkedList(list, -2);
  RemoveAtLinkedList(list, -3);
  RemoveAtLinkedList(list, -4);
  RemoveAtLinkedList(list, -5);

  printf("Lista encadeada:\n");
  PrintLinkedList(list);

  printf("\nValor na posição -2:\n");
  PrintValueAtLinkedList(list, -2);

  printf("\nImpressão recursiva da lista encadeada:\n");
  PrintRecursiveLinkedList(list, 0);

  printf("\nImpressão recursiva da lista encadeada:\n");
  PrintRecursiveLinkedList(list, 1);

  printf("\n3 está na lista encadeada:\n%d", IsInLinkedList(list, 3));
  
  ClearLinkedList(list);
  printf("\nLista limpa:\n");
  PrintLinkedList(list);

  printf("\n");
  

  DeleteLinkedList(list);

  return 0;
}

int TestStack()
{
  Stack* stack = InitStack();

  Push(stack, 0);
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  RecursivePrintStack(stack, 0);

  Pop(stack);
  RecursivePrintStack(stack, 1);

  Push(stack, 3);
  RecursivePrintStack(stack, 1);

  printf("3 está na pilha? %d\n", IsInStack(stack, 3));
  printf("6 está na pilha? %d\n", IsInStack(stack, 6));

  ClearStack(stack);
  RecursivePrintStack(stack, 0);

  printf("3 está na pilha? %d\n", IsInStack(stack, 3));

  DeleteStack(stack);

  return 0;
}

int main()
{
  printf("> Testes da lista encadeada\n");
  TestLinkedList();
  printf("\n> Testes da pilha\n");
  TestStack();
}

