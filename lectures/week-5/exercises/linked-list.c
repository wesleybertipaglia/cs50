#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int number;
    struct Node *next;

} Node;

int main(int argc, char *argv[])
{
    Node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]);

        Node *n = malloc(sizeof(Node));
        if (n == NULL)
        {
            return 1;
        }

        n->number = number; // same as (*n).number = number;
        n->next = list;
        list = n;
    }

    Node *ptr = list; // point to the first element of the list

    while (ptr != NULL)
    {
        printf("%d\n", ptr->number);
        ptr = ptr->next;
    }
}