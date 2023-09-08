#include <stdio.h>
#include <stdlib.h>

typedef struct{
  struct Node * head;
  struct Node * tail;
  int size;
}LinkedList;


typedef struct Node{
  struct Node * next;
  struct Node * previous;
  int content;
}Node;


void push(LinkedList* list, int value){
  Node * node = malloc(sizeof(Node));
  node->next = NULL;
  node->previous = NULL;
  node->content = value;
  if(list->head==NULL){
    list->head = node;  
    list->tail = node;
  }else{
    list->tail->next = node;
    node->previous = list->tail;
    list->tail = node;
  }
  list->size += 1;
}


int pop(LinkedList* list){
  if (list->size == 0){
    printf("Empty list, nothing to return");
    return -1;
  }

  if (list->size == 1){
    Node * node = list->head;
    list->head = NULL;
    list->tail = NULL;
    list->size -= 1;
    return node->content;
  }

  if (list->size == 2){
    int value = list->tail->content;
    free(list->tail);
    list->tail = list->head;
    list->head->next = NULL;
    list->size -= 1;
    return value;
  }


  Node * node = list->tail;
  int value = node->content;
  list->tail = node->previous;
  node->previous->next = NULL;
  list->tail = node->previous;
  free(node);
  list->size -= 1;
  return value;
}

void insert(LinkedList* list, int position, int value){

  if(position > list->size-1){
    printf("Invalid position\n");
    return;
  }

  if (position == 0){
    Node * node = malloc(sizeof(Node));
    node->next = list->head;
    node->previous = NULL;
    node->content = value;

    list->head->previous = node;
    list->head = node;
    list->size += 1; 
    return;
  }

  if (position == list->size-1){
    Node * node = malloc(sizeof(Node));
    node->next = NULL;
    node->previous = list->tail;
    node->content = value;

    list->tail->next = node;
    list->tail= node;
    list->size += 1; 
    return;
  }
 
  Node * current = list->head->next;

  for(int i = 1; i < list->size; i++){
    if(i == position){
      Node * node = malloc(sizeof(Node));
      
      node->next = current;
      node->previous = current->previous;
      node->content = value;

      node->previous->next = node;
      current->previous = node;

      list->size += 1;
      return;
    }
    current = current->next;
  }
}

void remove_by_element(LinkedList* list, int value){
  printf("here\n");
  Node * current = list->head;
  for(int i = 0; i <= list->size; i++){
    if(current->content == value){
      printf("%d\n",i);
      printf("value: %d\n", value);
      printf("value: %d\n", current->content);
      current->previous->next = current->next;
      current->next->previous = current->previous;
      free(current);
      list->size -= 1;
      return;
    }
    current = current->next;
  }
}

void remove_by_position(LinkedList * list, int position){
  Node * current = list->head;
  for(int i = 0; i <= list->size; i++){
    if(i == position){
      current->previous->next = current->next;
      current->next->previous = current->previous;
      free(current);
      list->size -= 1;
      return;
    }
    current = current->next;
  }
}

void print_list(LinkedList * list){
  if (list->head == NULL){
    printf("Empty list \n");
  }else{
    Node * current = list->head;
    printf("Head: %d\n", list->head->content);
    printf("Tail: %d\n", list->tail->content);
    printf("Size: %d\n", list->size);
    while(current != list->tail){
      printf("Value: %d\n", current->content);
      current = current->next;
    }
  }
}

void print_list_inverse(LinkedList * list){
  if (list->head == NULL){
    printf("Empty list \n");
  }else{
    Node * current = list->tail;
    printf("Head: %d\n", list->head->content);
    printf("Tail: %d\n", list->tail->content);
    printf("Size: %d\n", list->size);
    while(current != list->head){
      printf("Value: %d\n", current->content);
      current = current->previous;
    }
  }
}

int main(){
  LinkedList list = {.head = NULL, .tail = NULL, .size = 0};

  push(&list, 0);
  push(&list, 1);
  push(&list, 2);
  push(&list, 3);
  push(&list, 4);
  push(&list, 5);
  insert(&list, 2, 20);
  insert(&list, 0, 10);

  print_list(&list);
  print_list_inverse(&list);

  int node = pop(&list);

  print_list(&list);

  remove_by_position(&list, 2);

  print_list(&list);
  return 0;
}


