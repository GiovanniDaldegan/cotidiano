#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas-de-dados/node.c"
#include "estruturas-de-dados/stack_int.c"
#include "estruturas-de-dados/linked_list_int.c"

#define INVALID_VALUE       1
#define INVALID_EXPRESSION  2


inline int IsNumeric(char c)
{ return c >= 48 && c <= 57; }

inline int IsOperator(LinkedList* operators, char name)
{ return IsInLinkedList(operators, name); }

inline int IsVariable(LinkedList* variables, char name)
{ return IsInLinkedList(variables, name); }

int IsBlockSymbol(char symbol)
{
  return symbol == '(' || symbol == ')'
      || symbol == '[' || symbol == ']'
      || symbol == '{' || symbol == '}';
}

int IsValidExpression(char* exp)
{}

int InfixExpressionValue(char* expression)
{
  struct Stack* blockStack = InitStack();

  int count = 0;
  char lastSymbol; // D: digito, V: variavel, O: operador, B: block
  while (expression[count] != '\0')
  {
    // if ()
    // check: value, variable, operator, block
    count++;
  }
}

int AddToBlockStack(Stack* blockStack,
                    char blockStart)
{
}


int CreateOperator(char name,
                   char* operation)
{
  if (!IsValidExpression(operation))
    return 1;

  return 0;
}

int CreateVariable(LinkedList* variables,
                   char name,
                   int value)
{
  if (IsInLinkedList(variables, value))
    return 1;

  return 0;
}


void ClearConsole()
{ printf("\e[1;1H\e[2J"); }

// NOTE: adicionar limite de caracteres por linha
void PrintMenu(char* title,
               char* symbols,
               char* description,
               char** options,
               int padding,
               int lines)
{
  ClearConsole();

  int title_size = strlen(title) -1;
  int header_size = title_size + 2 + 2 * padding;

  char header_line[header_size];
  char title_line[header_size];
  
  for (int i = 0; i < header_size; i++)
      header_line[i] = symbols[0];      // strlen() > header_size??
                                        // 4 ou 5 caracteres inválidos a mais??

  for (int i = 0; i < 2+2*padding; i++)     // eu <3 overkilling
  {          // começo/fim     pulo do título    preencher entre título e borda
    int index = (i > padding) * (title_size + 1 + padding) + (i % (padding +1));

    if (i % (2 * padding +1) == 0)      // os índices depois do título tão com
                                        // um offset -1
    {
      title_line[index] = symbols[1];
    }
    else
      title_line[index] = ' ';
  }

  memcpy(&title_line[padding+1], title, title_size +1);

  printf("%s\n", header_line);
  printf("%s\n", title_line);
  printf("%s\n", header_line);
}

int PrintHeader(char* title, char* description)
{}

int PrintOptions(char** options)
{}


void MenuVariables(LinkedList* variables)
{
  int option = -1;

  char* title = "Menu de variáveis";
  char* symbols = "=|";
  char* options[] = { "Retornar", "Adicionar variável" };

  while (option != 0)
  {
    ClearConsole();
    /*
    printf("=======================\n"
           "|  Menu de variáveis  |\n"
           "=======================\n");
    printf("Escolha uma opção:\n"
           " 0 - Retornar\n"
           " 1 - Adicionar variável\n"
           "\n");
    */
    PrintMenu(title, symbols, NULL, options, 3, 1);

    scanf("%d", &option);
  }


}


void MenuOperators(LinkedList* operators)
{
  ClearConsole();
}


int main()
{
  LinkedList* operators = InitLinkedList();
  LinkedList* variables = InitLinkedList();

  int option = -1;
  
  while (option != 0)
  {
    ClearConsole();

    printf("\n=============================\n"
             "|  Interpretador Algébrico  |\n"
             "=============================\n");
    printf("\nEscolha uma opção:\n"
             " 0 - Terminar o programa\n"
             " 1 - Gerenciar variáveis\n"
             " 2 - Gerenciar operadores\n"
             " 3 - Inserir expressão\n");

    scanf("%d", &option);

    switch (option)
    {
      case 1:
        MenuVariables(variables);
        break;

      case 2:
        MenuOperators(operators);
        break;

      case 3:
        break;
    }
  }

  printf("\e[1;1H\e[2J");

  return 0;
}
