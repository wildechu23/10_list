#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "list.h"

void print_profile(struct profile *p) {
    printf("%s has %d wins and %d losses.\n", p->name, p->wins,p->losses);
}

struct profile * make_profile(char *nm, int sz, int w, int l, struct profile *nxt) {
    struct profile *n = malloc(sizeof(struct profile));

    strncpy(n->name, nm, sz);
    n->wins = w;
    n->losses = l;
    n->next = nxt;

    return n;
}

void print_list(struct profile *p) {
    print_profile(p);
    if(p->next) {
        print_list(p->next);
    }
}

struct profile * insert_front(struct profile *list, char *nm, int sz, int w, int l) {
    return make_profile(nm, sz, w, l, list);
}

struct profile * free_list(struct profile *list) {
    struct profile *next = list->next;
    free(list);
    if(next) {
        free_list(next);
    } else {
        return next;
    }
}

struct profile * remove_node(struct profile *front, char *nm, int w, int l) {
    if(strcmp(front->name, nm) == 0 && front->wins == w && front->losses == l) {
        struct profile *temp = front;
        front = front->next;
        free(temp);
        return front;
    }

    struct profile *current = front->next;
    struct profile *prev = front;
    while (current != NULL && prev != NULL) {
        if(strcmp(current->name, nm) == 0 && current->wins == w && current->losses == l) {
            struct profile *temp = current;
            prev->next = current->next;
            free(temp);
            return front;
        }
        current = current->next;
        prev = prev->next;
    }
    return front;
}
