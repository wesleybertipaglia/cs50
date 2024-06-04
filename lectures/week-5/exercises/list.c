#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char phrase[50];
    struct node *next;
} node;

node *create(const char *phrase);
void insert(node **list, const char *phrase);
void display(const node *list);
void free_list(node *list);

int main(void)
{
    node *list = NULL;

    // create nodes
    insert(&list, "Hello");
    insert(&list, "World");
    insert(&list, "This");

    display(list);
    free_list(list);
}

node *create(const char *phrase)
{
    node *n = malloc(sizeof(node));

    if (n == NULL)
    {
        return NULL;
    }

    strncpy(n->phrase, phrase, sizeof(n->phrase) - 1);
    n->phrase[sizeof(n->phrase) - 1] = '\0'; // Ensure null termination
    n->next = NULL;
    return n;
}

void insert(node **list, const char *phrase)
{
    node *n = create(phrase);
    if (n != NULL)
    {
        n->next = *list;
        *list = n;
    }
}

void display(const node *list)
{
    const node *n = list;
    while (n != NULL)
    {
        printf("%s\n", n->phrase);
        n = n->next;
    }
}

void free_list(node *list)
{
    node *n = list;
    while (n != NULL)
    {
        node *tmp = n->next;
        free(n);
        n = tmp;
    }
}
