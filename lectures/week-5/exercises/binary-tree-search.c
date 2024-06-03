#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
    int number;
    struct Node *left;
    struct Node *right;
} Node;

bool search(Node *tree, int number);

int main(void)
{
    Node n1, n2, n3, n4, n5;
    n1.number = 1;
    n2.number = 2;
    n3.number = 3;

    n1.left = &n2;
    n1.right = &n3;
    n2.left = &n4;
    n2.right = &n5;
    n3.left = NULL;
    n3.right = NULL;

    printf("%i\n", search(&n1, 2));
}

bool search(Node *tree, int number)
{
    if (tree == NULL)
    {
        return false;
    }
    else if (tree->number > number)
    {
        return search(tree->left, number);
    }
    else if (tree->number < number)
    {
        return search(tree->right, number);
    }
    else if (tree->number == number)
    {
        return true;
    }
}