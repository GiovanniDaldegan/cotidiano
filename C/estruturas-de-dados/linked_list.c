#include <stdio.h>
#include <stdlib.h>

#define INDEX_OUT_OF_BOUNDS -1

struct Node_Int32
{
  int data;
  struct Node_Int32* next;
};

struct Node_Int32* InitNode_Int32(int data,
                                  struct Node_Int32* next)
{
  struct Node_Int32* temp =
    (struct Node_Int32*) malloc(sizeof(struct Node_Int32));

  temp->data = data;
  temp->next = next;

  return temp;
}


struct LinkedList_Int32
{
  int size;
  struct Node_Int32* head;
};

struct LinkedList_Int32 InitLinkedList_Int32()
{
  struct LinkedList_Int32 list;
  list.size = 0;
  list.head = NULL;

  return list;
}

struct Node_Int32* GetNodeAtLinkedList_Int32(struct LinkedList_Int32* list,
                                 int index)
{
  if (index > list->size -1 || index < -list->size)
    return NULL;

  if (index == 0 || index == -list->size)
  {
    return list->head;
  }
  else
  {
    struct Node_Int32* temp = list->head;
    int count = 0;

    while (count != index-1 && count != list->size + index -1)
    {
      temp = temp->next;
      count++;
    }

    return temp->next;
  }
}

int InsertAtLinkedList_Int32(struct LinkedList_Int32* list,
                             int data,
                             int index) {
  if (index > list->size + 1 || index < -list->size)
    return INDEX_OUT_OF_BOUNDS;

  struct Node_Int32* newNode = InitNode_Int32(data, NULL);

  if (index == 0 || list->size == 0)
  {
    newNode->next = list->head;
    list->head = newNode;
  }
  else
  {
    struct Node_Int32* temp = list->head;
    int count = 0;

    while (count != index -1 && count != list->size + index)
    {
      temp = temp->next;
      count++;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  list->size++;
  return 0;
}

int RemoveAtLinkedList_Int32(struct LinkedList_Int32* list,
                             int index)
{
  if (index > list->size -1 || index < -list->size)
    return INDEX_OUT_OF_BOUNDS;

  struct Node_Int32* prt_free = NULL;

  if (index == 0 || index == -list->size)
  {
    prt_free = list->head;
    list->head = list->head->next;
    free(prt_free);
  }
  else
  {
    struct Node_Int32* temp = list->head;
    int count = 0;

    while (count != index -1 && count != list->size + index -1)
    {
      temp = temp->next;
      count++;
    }
    
    prt_free = temp->next;
    temp->next = temp->next->next;
    free(prt_free);
  }

  list->size--;
  return 0;
}

void PrintLinkedList_Int32(struct LinkedList_Int32* list)
{
  struct Node_Int32* temp = list->head;

  printf("[");
  while (temp != NULL)
  {
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(", ");

    temp = temp->next;
  }
  printf("]");
}

void PrintNextLinkedList_Int32(struct Node_Int32* node,
                               int reverse)
{
  if (node == NULL)
    return;

  if (!reverse)
  {
    printf("%d", node->data);
    if (node->next != NULL)
      printf(", ");
  }

  PrintNextLinkedList_Int32(node->next, reverse);
  
  if (reverse)
  {
    if (node->next != NULL)
      printf(", ");
    printf("%d", node->data);
  }
}

void RecursivePrintLinkedList_Int32(struct LinkedList_Int32* list,
                                    int reverse)
{
  struct Node_Int32* temp = list->head;

  printf("[");
  PrintNextLinkedList_Int32(temp, reverse);
  printf("]");
}

int main() {
  struct LinkedList_Int32 list = InitLinkedList_Int32();

  InsertAtLinkedList_Int32(&list, 2, 0);
  InsertAtLinkedList_Int32(&list, 4, 1);
  InsertAtLinkedList_Int32(&list, 1, 0);
  InsertAtLinkedList_Int32(&list, 3, -2);
  InsertAtLinkedList_Int32(&list, 0, 0);
  InsertAtLinkedList_Int32(&list, 3, -7);
  InsertAtLinkedList_Int32(&list, 3, 37);
  InsertAtLinkedList_Int32(&list, 5, -1);
  InsertAtLinkedList_Int32(&list, 6, -1);

  RemoveAtLinkedList_Int32(&list, -1);
  RemoveAtLinkedList_Int32(&list, -2);
  RemoveAtLinkedList_Int32(&list, -3);
  RemoveAtLinkedList_Int32(&list, -4);
  RemoveAtLinkedList_Int32(&list, -5);

  printf("Linked list: \n");
  PrintLinkedList_Int32(&list);

  printf("\nValue at position -2: \n");
  printf("%d", GetNodeAtLinkedList_Int32(&list, -2)->data);

  printf("\nLinked list recursive print: \n");
  RecursivePrintLinkedList_Int32(&list, 0);

  printf("\nLinked list recursive print (reverse):\n");
  RecursivePrintLinkedList_Int32(&list, 1);
  
  printf("\n");
  return 0;
}
