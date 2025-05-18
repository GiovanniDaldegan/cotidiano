#include <stdio.h>
#include <stdlib.h>
#include "node.h"


static void* PrintValue(Node *self)
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

Node* InitNode(DataType type,
               void* value,
               Node* link)
{
  Node *node = malloc(sizeof(Node));

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

