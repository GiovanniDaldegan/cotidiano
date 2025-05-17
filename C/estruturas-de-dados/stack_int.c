#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"


struct Stack* InitStack()
{
  struct Stack* stack = malloc(sizeof(struct Stack));

  stack->size = 0;
  stack->top = NULL;

  return stack;
}


void Push(struct Stack* stack,
          int value)
{
  struct Node* newNode = InitNode(INT, &value, stack->top);

  stack->top = newNode;
  stack->size++;
}

void Pop(struct Stack* stack)
{
  struct Node* free_ptr = stack->top;

  stack->top = stack->top->link;
  free(free_ptr);

  stack->size--;
}

inline int IsEmptyStack(struct Stack* stack)
{ return stack->size == 0; }

int IsInStack(struct Stack* stack,
              int value)
{
  if (IsEmptyStack(stack))
    return 0;

  struct Node* temp = stack->top;

  while (temp != NULL)
  {
    if (*((int*) temp->value) == value)
      return 1;

    temp = temp->link;
  }

  return 0;
}

void ClearStack(struct Stack* stack)
{
  while (!IsEmptyStack(stack))
    Pop(stack);
}

void DeleteStack(struct Stack* stack)
{
  ClearStack(stack);
  free(stack);
}

void PrintNode_r(struct Node* node,
               int reverse)
{
  if (node == NULL)
    return;

  if (!reverse)
  {
    printf(" ");
    node->PrintValue(node);
  }
    //printf(" %d", *((int*) link->value));

  PrintNode_r(node->link, reverse);

  if (reverse)
  {
    node->PrintValue(node);
    printf(" ");
  }
    //printf("%d ", *((int*) link->value));
}

void RecursivePrintStack(struct Stack* stack,
                int reverse)
{
  if (IsEmptyStack(stack))
  {
    printf("stack vazia\n");
    return;
  }

  if (!reverse)
    printf("top ->");

  PrintNode_r(stack->top, reverse);

  if (reverse)
    printf("<- top");

  printf("\n");
}

