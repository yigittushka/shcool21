#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
    int id;

    struct list *next;
} Node;

Node *init(int a) {
    Node *tmp = (Node *)malloc(sizeof(Node));

    tmp->id = a;

    tmp->next = NULL;

    return tmp;
}

void push(Node *list, int number) { Node *new_el = creat_node(number); }

int main() {
    Node *list = creat_node(0, "Name1");

    push(&list, 0);
    push(&list, 1);
    push(&list, 2);
    push(&list, 3);

    while (list != NULL) {
        printf("id = %d", list->id);
        list = list->next;
    }
    return 0;
}
