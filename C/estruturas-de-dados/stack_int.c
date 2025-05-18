#include <stdio.h>
#include <stdlib.h>

#include "stack_int.h"


Stack* InitStack()
{
  Stack* stack = malloc(sizeof(Stack));

  stack->size = 0;
  stack->top = NULL;

  return stack;
}


void Push(Stack* stack,
          int value)
{
  Node* newNode = InitNode(INT, &value, stack->top);

  stack->top = newNode;
  stack->size++;
}

void Pop(Stack* stack)
{
  Node* free_ptr = stack->top;

  stack->top = stack->top->link;
  free(free_ptr);

  stack->size--;
}

int IsEmptyStack(Stack* stack)
{ return stack->size == 0; }

int IsInStack(Stack* stack,
              int value)
{
  if (IsEmptyStack(stack))
    return 0;

  Node* temp = stack->top;

  while (temp != NULL)
  {
    if (*((int*) temp->value) == value)
      return 1;

    temp = temp->link;
  }

  return 0;
}

void ClearStack(Stack* stack)
{
  while (!IsEmptyStack(stack))
    Pop(stack);
}

void DeleteStack(Stack* stack)
{
  ClearStack(stack);
  free(stack);
}

void PrintNode_r(Node* node,
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

void RecursivePrintStack(Stack* stack,
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

