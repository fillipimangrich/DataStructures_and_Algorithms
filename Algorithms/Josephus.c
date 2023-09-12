#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../DataStructures/CircularLinkedList/CircularLinkedList.h"

int main ( int argc, char *argv[] ){

    if (argc > 3){
        printf("too many arguments\n");
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

    int sword_position = 0;
    while (list.size > 1)
    {
        int to_dead_position = (sword_position+k)%list.size;
        remove_by_position(&list, to_dead_position);        
        printf("removed: %d\n", to_dead_position);
        printf("--------------\n");
        sword_position = (sword_position+k)%list.size;
    }
    
    printf("Suvivor: %d\n", list.head->content);

    return 0;
}
