#include <stdio.h>
#include <stdlib.h>
#include "stack_int.h"


struct Node
{
  int value;
  struct Node* lower;
};

struct Stack
{
  int size;
  struct Node* top;
};

struct Stack* InitStack()
{
  struct Stack* stack = malloc(sizeof(struct Stack));

  stack->size = 0;
  stack->top = NULL;

  return stack;
}

struct Node* InitNode(int value,
                      struct Node* lower)
{
  struct Node* node = malloc(sizeof(struct Node));

  node->value = value;
  node->lower = lower;

  return node;
}


void Push(struct Stack* stack,
          int value)
{
  struct Node* newNode = InitNode(value, stack->top);

  stack->top = newNode;
  stack->size++;
}

void Pop(struct Stack* stack)
{
  struct Node* free_ptr = stack->top;

  stack->top = stack->top->lower;
  free(free_ptr);

  stack->size--;
}

int IsEmptyStack(struct Stack* stack)
{
  return stack->size == 0;
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

void PrintNode(struct Node* lower,
                    int reverse)
{
  if (lower == NULL)
    return;

  if (!reverse)
    printf(" %d", lower->value);

  PrintNode(lower->lower, reverse);

  if (reverse)
    printf("%d ", lower->value);
}

void PrintStack(struct Stack* stack,
                int reverse)
{
  if (IsEmptyStack(stack))
  {
    printf("stack vazia\n");
    return;
  }

  if (!reverse)
    printf("top ->");

  PrintNode(stack->top, reverse);

  if (reverse)
    printf("<- top");

  printf("\n");
}

