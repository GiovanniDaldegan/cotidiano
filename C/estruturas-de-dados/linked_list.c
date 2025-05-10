#include <stdio.h>
#include <stdlib.h>

struct LinkedList_Int32 {
  struct Node_Int32* head;
};

struct Node_Int32 {
  int data;
  struct Node_Int32* next;
};

void InsertAtLinkedList_Int32(struct LinkedList_Int32 linkedList, int data, int index) {
  if (index == 0) {
    struct Node_Int32* newNode = (struct Node_Int32*) malloc(sizeof(struct Node_Int32));

    newNode->data = data;
    newNode->next = linkedList.head;

    linkedList.head = newNode;
  }
}

int main() {
  struct LinkedList_Int32 list;

  InsertAtLinkedList_Int32(list, 2, 0);

  printf("%d", list.head->data);

  return 0;
}
