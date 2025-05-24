#ifdef ALGEBRIC_READER_H
#define ALGEBRIC_READER_H

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


int AddToBlockStack(char);
int ExpressionValue(char*);

#endif
