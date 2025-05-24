#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "estruturas-de-dados/node.c"
#include "estruturas-de-dados/stack_int.c"
#include "estruturas-de-dados/linked_list_int.c"
#include "algebric_interpreter.h"

#define INVALID_VALUE       1
#define INVALID_EXPRESSION  2


int IsNumeric(char c)
{ return c >= 48 && c <= 57; }

int IsOperator(LinkedList* operators, char name)
{ return IsInLinkedList(operators, name); }

int IsVariable(LinkedList* variables, char name)
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
{} //printf("\e[1;1H\e[2J"); }

// TODO: adicionar suporte para caracteres não ASCII no título
int PrintHeader(char* title,
                char* description,
                char* symbols,
                int padding,
                int lines)
{
  int title_size = strlen(title);
  int header_size = title_size + 2 + 2 * padding;

  char header_line[header_size+1];
  
  // formatação das linhas superior e inferior
  for (int i = 0; i < header_size+1; i++)
      header_line[i] = symbols[0];
  header_line[header_size] = '\0';

  printf("%s\n", header_line); // linha superior
  for (int i = 0; i < header_size; i++)
  {
    if (i % (header_size-1) == 0) // bordas
      printf("%c", symbols[1]);
    else if  (i <= padding || i >= padding + title_size +1) // padding
      printf(" ");
    else
      printf("%c", title[i-padding-1]); // título
  }
  printf("\n%s\n", header_line); // linha inferior
}

int PrintOptions(char** options)
{
  int count = 0;
  while (options[count] != NULL)
  {
    printf(" %d - %s\n", count, options[count]);
    count++;
  }
}

// TODO: adicionar limite de caracteres por linha
void PrintMenu(char* title,
               char* description,
               char** options,
               char* symbols,
               int padding,
               int lines)
{
  PrintHeader(title, description, symbols, padding, lines);
  PrintOptions(options);
}


int GetChoice()
{
  char input[3];

  fgets(input, sizeof(input), stdin);

  // TODO: corrigir a checagem pro buffer de fato ser limpo
  if (strlen(input) > sizeof(input) - 1)
  {
    int ch;
    while ((ch = getchar()) != EOF && ch != '\n'); // descarta tudo no buffer até
                                                   // o próximo \n
  }

  printf("%s %ld", input, strlen(input));

  if (strlen(input) == 1 && IsNumeric(input[0]))
    return input[0] - '0';
  else
    return -1;
}

// TODO: função de seleção de opção? (com while e switch)

void MenuVariables(LinkedList* variables)
{
  char* title = "Menu de variaveis";
  char* symbols = "=|";
  char* options[] = { "Retornar", "Adicionar variável", NULL };

  int choice = -1;
  while (choice != 0)
  {
    ClearConsole();
    PrintMenu(title, NULL, options, symbols, 4, 1);
    
    choice = GetChoice();

    switch(choice)
    {
      default:
        printf("\nOpção inválida.\n");
        break;
    }
  }


}

void MenuOperators(LinkedList* operators)
{
  ClearConsole();
}


void MainMenu()
{
  LinkedList* operators = InitLinkedList();
  LinkedList* variables = InitLinkedList();

  char* title = "Interpretador Algebrico";
  char* symbols = "=|";
  char* options[] = {"Terminar o programa", "Menu de variáveis",
                     "Menu de Operadores", "Inserir expressão", NULL};

  int choice = -1;
  while (choice != 0)
  {
    ClearConsole();
    PrintMenu(title, NULL, options, symbols, 3, 1);

    choice = GetChoice();
    
    switch (choice)
    {
      case 1:
        MenuVariables(variables);
        break;

      case 2:
        MenuOperators(operators);
        break;

      default:
        printf("\nOpção inválida.\n");
        break;
    }
  }
  ClearConsole();
}


int main()
{
  MainMenu();
  return 0;
}
