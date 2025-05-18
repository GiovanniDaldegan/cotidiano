#include <stdio.h>
#include <stdlib.h>
#include "stack_int.c"
#include "linked_list_int.c"

struct Variable
{
  char name;
  int value;
};

struct Operator
{
  char name;
  char* operation;
};

int InfixExpressionValue(char* expression)
{
  struct Stack* blockStack = InitStack();

  int count = 0;
  while (expression[count] != "\0")
  {
    // check: value, variable, operator, block
    count++;
  }
}

int IsValue()
{}

int IsOperator()
{}

int IsVariable()
{}

int IsBlockChar()
{}

int AddToBlockStack(struct Stack* blockStack,
                    char blockStart)
{}

int main()
{
  

  return 0;
}
