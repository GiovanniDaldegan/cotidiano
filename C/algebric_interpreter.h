#ifdef ALGEBRIC_READER_H
#define ALGEBRIC_READER_H

#include "estruturas-de-dados/node.h"
#include "estruturas-de-dados/linked_list_int.h"
#include "estruturas-de-dados/stack_int.h"

typedef struct Variable
{
  char name;
  int value;
} Variable;

typedef struct Operator
{
  char name;
  char* operation;
} Operator;

inline int IsNumeric(char);
inline int IsOperator(LinkedList*, char);
inline int IsVariable(variables, char);
int IsBlockSymbol(char);
int IsValidExpression(char*);
int InfixExpressionValue();

int CreateOperator();
int CreateVariable();

void ClearConsole();
void PrintMenu();
void PrintHeader();
void PrintOptions();



void MainMenu();
void MenuVariables();
void MenuOperators();

#endif
