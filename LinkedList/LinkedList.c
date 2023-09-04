#include <stdio.h>


typedef struct{
  struct Node * head;
  struct Node * tail;
  int size;
}LinkedList;


typedef struct Node{
  struct Node * next;
  int content;
}Node;


void push(LinkedList* list, int value){
  Node node = {.next = NULL, .content = value};
  if(list->head==NULL){
    list->head = &node;  
    list->tail = &node;
    
  }else{
    list->tail->next = &node;
    list->tail = &node;
  }
  list->size += 1;
}


int pop(LinkedList* list){
  if (list->size == 0){
    printf("Empty list, nothing to return");
    return -1;
  }

  Node current = *list->head;
  Node previous;

  if (current.next == NULL){
    list->head = NULL;
    list->size -= 1;
    return current.content;
  }

  while(current.next != NULL){
    printf("aqui\n");
    printf("%d\n",current.content);
    previous = current;
    current = *current.next;
  }

  previous.next = NULL;
  list->tail = &previous;
  list->size -= 1;
  return current.content;
}

void insert(LinkedList* list, int position){

}

void remove_by_element(LinkedList* list, Node node){

}

void remove_by_position(LinkedList * list, int position){

}

void print_list(LinkedList * list){
  if (list->head == NULL){
    printf("Empty list \n");
  }else{
    Node current = *list->head;
    while(current.next != NULL){
      printf("Value: %d\n", current.content);
      current = *current.next;
    }
  }
}

int main(){
  LinkedList list = {.head = NULL, .tail = NULL, .size = 0};

  push(&list, 25);
  push(&list, 10);
  push(&list, 10);
  push(&list, 10);
  push(&list, 11);
  push(&list, 12);


  printf("Value: %d \n", list.head->content);
  printf("Size: %d \n", list.size);

  int node = pop(&list);

  printf("Value: %d \n", node);
  printf("Size: %d \n", list.size);

  print_list(&list);
  return 0;
}


