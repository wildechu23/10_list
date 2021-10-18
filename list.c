#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

struct profile {
    char name[16];
    int wins;
    int losses;
    struct profile *next;
};

void print_profile(struct profile *);
struct profile * make_profile(char *, int, int, int, struct profile *);
void print_list(struct profile *);
struct profile * insert_front(struct profile *, char *, int, int, int);
struct profile * free_list(struct profile *);

int main() {
    struct profile * list = insert_front(NULL, "bob", 3, 3, 5);
    list = insert_front(list, "joe", 3, 4, 2);
    list  = insert_front(list, "emma", 4, 2, 7);

    print_list(list);
    if(free_list(list) == NULL) {
        printf("success\n");
    }

    return 0;
}

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
