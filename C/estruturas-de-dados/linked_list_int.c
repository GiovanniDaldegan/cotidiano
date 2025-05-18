#include <stdio.h>
#include <stdlib.h>

#include "linked_list_int.h"

#define INDEX_OUT_OF_BOUNDS -1


LinkedList* InitLinkedList()
{
  LinkedList *list = malloc(sizeof(LinkedList));

  list->size = 0;
  list->head = NULL;

  return list;
}


int InsertAtLinkedList(LinkedList *list,
                       int value,
                       int index) {
  if (index > list->size + 1 || index < -list->size)
    return INDEX_OUT_OF_BOUNDS;

  Node *newNode = InitNode(INT, &value, NULL);

  if (index == 0 || list->size == 0)
  {
    newNode->link = list->head;
    list->head = newNode;
  }
  else
  {
    Node *temp = list->head;
    int count = 0;

    while (count != index -1 && count != list->size + index)
    {
      temp = temp->link;
      count++;
    }

    newNode->link = temp->link;
    temp->link = newNode;
  }

  list->size++;
  return 0;
}

int RemoveAtLinkedList(LinkedList *list,
                       int index)
{
  if (index > list->size -1 || index < -list->size)
    return INDEX_OUT_OF_BOUNDS;

  Node *prt_free = NULL;

  if (index == 0 || index == -list->size)
  {
    prt_free = list->head;
    list->head = list->head->link;
    free(prt_free);
  }
  else
  {
    Node *temp = list->head;
    int count = 0;

    while (count != index -1 && count != list->size + index -1)
    {
      temp = temp->link;
      count++;
    }
    
    prt_free = temp->link;
    temp->link = temp->link->link;
    free(prt_free);
  }

  list->size--;
  return 0;
}


int IsEmptyLinkedList(LinkedList *list)
{ return list->size == 0; }

int IsInLinkedList(LinkedList *list,
                   int value)
{
  Node *temp = list->head;

  while (temp != NULL)
  {
    if (*((int*) temp->value) == value)
      return 1;
    temp = temp->link;
  }

  return 0;
}


void ClearLinkedList(LinkedList *list)
{
  while (!IsEmptyLinkedList(list))
    RemoveAtLinkedList(list, 0);
}

void DeleteLinkedList(LinkedList *list)
{
  ClearLinkedList(list);
  free(list);
}


void PrintValueAtLinkedList(LinkedList *list,
                            int index)
{
  if (index > list->size -1 || index < -list->size)
    return;

  Node *temp = list->head;
  int count = 0;
  while (count != index && count != list->size + index)
  {
    temp = temp->link;
    count++;
  }

  temp->PrintValue(temp);
}

void PrintLinkedList(LinkedList *list)
{
  Node *temp = list->head;

  printf("[");
  while (temp != NULL)
  {
    temp->PrintValue(temp);
    if (temp->link != NULL)
      printf(", ");

    temp = temp->link;
  }
  printf("]");
}

void PrintRecursiveLinkedList_r(Node *node,
                                int reverse)
{
  if (node == NULL)
    return;

  if (!reverse)
  {
    node->PrintValue(node);
    if (node->link != NULL)
      printf(", ");
  }

  PrintRecursiveLinkedList_r(node->link, reverse);

  if (reverse)
  {
    if (node->link != NULL)
      printf(", ");
    node->PrintValue(node);
  }
}

void PrintRecursiveLinkedList(LinkedList *list,
                              int reverse)
{
  Node *temp = list->head;

  printf("[");
  PrintRecursiveLinkedList_r(temp, reverse);
  printf("]");
}

