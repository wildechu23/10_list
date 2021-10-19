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
struct profile * remove_node(struct profile *, char *, int, int);
