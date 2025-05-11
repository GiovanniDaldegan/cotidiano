#include <stdio.h>
#include <stdlib.h>

#define INVALID_OPERATION 1

struct Node_Int32 {
  int data;
  struct Node_Int32* next;
};

struct Node_Int32* InitNode_Int32(int data,
                                  struct Node_Int32* next) {
  struct Node_Int32* temp =
    (struct Node_Int32*) malloc(sizeof(struct Node_Int32));

  temp->data = data;
  temp->next = next;

  return temp;
}


struct LinkedList_Int32 {
  int size;
  struct Node_Int32* head;
};

struct LinkedList_Int32 InitLinkedList_Int32() {
  struct LinkedList_Int32 list;
  list.size = 0;
  list.head = NULL;

  return list;
}

int InsertAtLinkedList_Int32(struct LinkedList_Int32* list,
                              int data,
                              int index) {
  struct Node_Int32* newNode = InitNode_Int32(data, NULL);

  if (index > list->size + 1 || index < -list->size)
    return INVALID_OPERATION;

  if (index == 0 || list->size == 0) {
    newNode->next = list->head;
    list->head = newNode;
  }
  else {
    struct Node_Int32* temp = list->head;
    int count = 0;

    if (index > 0) {
       while (temp->next != NULL && count != index-1) {
        temp = temp->next;
        count++;
      }
    }
    else {
      while (count != list->size + index) {
        temp = temp->next;
        count++;
      }
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  list->size++;
  return 0;
}

int RemoveAtLinkedList_Int32(struct LinkedList_Int32* list,
                              int index) {
  if (index > list->size - 1 || index < -list->size)
    return INVALID_OPERATION;

  struct Node_Int32* prt_free = NULL;

  if (index == 0 || index == -list->size) {
    prt_free = list->head;
    list->head = list->head->next;
    free(prt_free);
  }
  else {
    struct Node_Int32* temp1 = list->head;
    int count = 0;

    if (index > 0) {
      while (temp1->next == NULL || count != index - 1) {
        temp1 = temp1->next;
        count++;
      }
    }
    else {
      while (count != list->size + index -1) {
        temp1 = temp1->next;
        count++;
      }
    }
    
    prt_free = temp1->next;
    temp1->next = temp1->next->next;
    free(prt_free);
  }

  list->size--;
  return 0;
}


void PrintLinkedList_Int32(struct LinkedList_Int32 list) {
  struct Node_Int32* temp = list.head;

  printf("[");
  while (temp != NULL) {
    printf("%d", temp->data);
    if (temp->next != NULL)
      printf(", ");

    temp = temp->next;
  }
  printf("]\n");
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

  RemoveAtLinkedList_Int32(&list, -1);
  RemoveAtLinkedList_Int32(&list, -2);
  RemoveAtLinkedList_Int32(&list, -3);

  PrintLinkedList_Int32(list);

  return 0;
}
