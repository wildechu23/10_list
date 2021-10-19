#include <stdio.h>
#include <stdlib.h>

#include "list.h"

int main() {
    struct profile * list = NULL;
    list = insert_front(list, "bob", 3, 3, 5);
    list = insert_front(list, "joe", 3, 4, 2);
    list  = insert_front(list, "emma", 4, 2, 7);

    print_list(list);
    // if(free_list(list) == NULL) {
    //     printf("freeing success\n");
    // }

    list = remove_node(list, "joe", 4, 2);

    print_list(list);

    return 0;
}