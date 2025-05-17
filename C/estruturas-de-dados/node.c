#ifndef NODE_C
#define NODE_C

#include <stdio.h>
#include <stdlib.h>
#include "node.h"


void* PrintValue(Node *self)
{
  switch (self->type)
  {
    case 0:
      printf("%d", *((int*) self->value));
      break;

    case 1:
      printf("%f", *((float*) self->value));
      break;
  }
}

struct Node* InitNode(DataType type,
                      void* value,
                      struct Node* link)
{
  struct Node *node = malloc(sizeof(struct Node));

  switch (type)
  {
    case 0:
      node->value = malloc(sizeof(int));
      *((int*) node->value) = *((int*) value);
      break;

    case 1:
      node->value = malloc(sizeof(float));
      *((float*) node->value) = *((float*) value);
      break;

    default:
      free(node);
      return NULL;
  }

  node->type = type;
  node->link = link;
  node->PrintValue = PrintValue;

  return node;
}

#endif
