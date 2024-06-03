#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

struct Node
{
    char key[256];
    int value;
    struct Node *next;
};

struct Node *hashTable[TABLE_SIZE];

unsigned int hash(const char *key)
{
    unsigned int hashValue = 0;
    while (*key)
        hashValue += *key++;
    return hashValue % TABLE_SIZE;
}

void insert(const char *key, int value)
{
    unsigned int index = hash(key);
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
}

int search(const char *key)
{
    unsigned int index = hash(key);
    struct Node *node = hashTable[index];
    while (node)
    {
        if (strcmp(node->key, key) == 0)
            return node->value;
        node = node->next;
    }
    return -1;
}

void display()
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        printf("Bucket %d: ", i);
        struct Node *node = hashTable[i];
        while (node)
        {
            printf("(%s, %d) -> ", node->key, node->value);
            node = node->next;
        }
        printf("None\n");
    }
}

int main()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    insert("apple", 10);
    insert("banana", 20);
    insert("grape", 30);
    insert("orange", 40);
    insert("lemon", 50);

    display();

    printf("Search for key 'apple': %d\n", search("apple"));
    printf("Search for key 'banana': %d\n", search("banana"));
    printf("Search for key 'mango': %d\n", search("mango")); // Should return -1 (not found)

    return 0;
}
