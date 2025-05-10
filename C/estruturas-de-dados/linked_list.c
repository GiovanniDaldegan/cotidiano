#include <stdio.h>
#include <stdlib.h>

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

void InsertAtLinkedList_Int32(struct LinkedList_Int32* list,
                              int data,
                              int index) {
  struct Node_Int32* newNode = InitNode_Int32(data, NULL);

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
     if (list->size + index < 0)
        return;

      while (temp->next != NULL && count < list->size + index) {
        temp = temp->next;
        count++;
      }
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  list->size++;
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

  InsertAtLinkedList_Int32(&list, 0, 0);  // 0
  InsertAtLinkedList_Int32(&list, 2, 0);  // 2 0
  InsertAtLinkedList_Int32(&list, 3, 1);  // 2 3 0
  InsertAtLinkedList_Int32(&list, 123, 1); // 2 123 1 3 0
  InsertAtLinkedList_Int32(&list, 1, -2); // 2 3 1 0
  PrintLinkedList_Int32(list);

  return 0;
}
