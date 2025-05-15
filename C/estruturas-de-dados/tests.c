#include <stdio.h>
#include "linked_list_int.c"
#include "stack_int.c"

int TestLinkedList() {
  struct LinkedList_Int32* list = InitLinkedList_Int32();

  InsertAtLinkedList_Int32(list, 2, 0);
  InsertAtLinkedList_Int32(list, 4, 1);
  InsertAtLinkedList_Int32(list, 1, 0);
  InsertAtLinkedList_Int32(list, 3, -2);
  InsertAtLinkedList_Int32(list, 0, 0);
  InsertAtLinkedList_Int32(list, 3, -7);
  InsertAtLinkedList_Int32(list, 3, 37);
  InsertAtLinkedList_Int32(list, 5, -1);
  InsertAtLinkedList_Int32(list, 6, -1);

  RemoveAtLinkedList_Int32(list, -1);
  RemoveAtLinkedList_Int32(list, -2);
  RemoveAtLinkedList_Int32(list, -3);
  RemoveAtLinkedList_Int32(list, -4);
  RemoveAtLinkedList_Int32(list, -5);

  printf("Linked list: \n");
  PrintLinkedList_Int32(list);

  printf("\nValue at position -2: \n");
  printf("%d", GetNodeAtLinkedList_Int32(list, -2)->data);

  printf("\nLinked list recursive print: \n");
  RecursivePrintLinkedList_Int32(list, 0);

  printf("\nLinked list recursive print (reverse):\n");
  RecursivePrintLinkedList_Int32(list, 1);
  
  ClearLinkedList(list);
  printf("\nCleared list:\n");
  PrintLinkedList_Int32(list);

  printf("\n");
  

  DeleteLinkedList_Int32(list);

  return 0;
}

int TestStack()
{
  struct Stack* stack = InitStack();

  Push(stack, 0);
  Push(stack, 1);
  Push(stack, 2);
  Push(stack, 3);
  PrintStack(stack, 0);

  Pop(stack);
  PrintStack(stack, 1);

  Push(stack, 3);
  PrintStack(stack, 1);

  ClearStack(stack);
  PrintStack(stack, 0);

  DeleteStack(stack);

  return 0;
}

int main()
{
  TestLinkedList();
  TestStack();
}

