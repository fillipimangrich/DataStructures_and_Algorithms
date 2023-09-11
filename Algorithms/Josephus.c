#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../DataStructures/CircularLinkedList/CircularLinkedList.h"

int main ( int argc, char *argv[] ){

    if (argc > 3){
        printf("to many arguments\n");
        return 0;
    }

    int n = atoi(argv[1]);
    int k = atoi(argv[2]);

    CircularLinkedList list = {.head = NULL, .tail = NULL, .size = 0};

    printf("K = %d\n", k);
    for (int i=0; i<n; i++){
        push(&list, i);
    }

    print_list(&list);


    return 0;
}
