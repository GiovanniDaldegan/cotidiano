#include <stdio.h>
#include <stdlib.h>

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

struct Node
{
  int value;
  struct Node* lower;
};

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

void PrintLowerNode(struct Node* lower,
                    int reverse)
{
  if (lower == NULL)
    return;

  if (!reverse)
    printf(" %d", lower->value);

  PrintLowerNode(lower->lower, reverse);

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

  PrintLowerNode(stack->top, reverse);

  if (reverse)
    printf("<- top");

  printf("\n");
}


int main()
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
}
