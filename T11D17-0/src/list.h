#ifndef SRC_L
#define SRC_L

typedef struct s_list {
    int id;
    char *name;

    struct s_list *next;
} t_list;

t_list *creat_node(int set_id, char *set_name) {
    t_list *node = (t_list *)malloc(sizeof(t_list));

    node->id = set_id;
    node->name = set_name;

    node->next = NULL;

    return node;
}

struct door {
    int id;
    int status;
};

struct init {
    struct door *pNext;
};
struct node *add_door;
struct node *elem;
struct node *remove_door;
void destroy();

#endif