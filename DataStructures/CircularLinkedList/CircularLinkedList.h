#include <stdio.h>
#include <stdlib.h>

typedef struct{
  struct Node * head;
  struct Node * tail;
  int size;
}CircularLinkedList;

typedef struct Node{
  struct Node * next;
  struct Node * previous;
  int content;
}Node;

void push(CircularLinkedList* list, int value);

int pop(CircularLinkedList* list);

void insert(CircularLinkedList* list, int position, int value);

void remove_by_element(CircularLinkedList* list, int value);

void remove_by_position(CircularLinkedList * list, int position);

void print_list(CircularLinkedList * list);

void print_list_inverse(CircularLinkedList * list);
