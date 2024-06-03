#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALPHABET_SIZE 26

struct TrieNode
{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNode(void)
{
    struct TrieNode *node = (struct TrieNode *)malloc(sizeof(struct TrieNode));
    node->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        node->children[i] = NULL;

    return node;
}

void insert(struct TrieNode *root, const char *key)
{
    struct TrieNode *pCrawl = root;

    while (*key)
    {
        int index = *key - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
        key++;
    }

    // Mark last node as leaf
    pCrawl->isEndOfWord = true;
}

bool search(struct TrieNode *root, const char *key)
{
    struct TrieNode *pCrawl = root;

    while (*key)
    {
        int index = *key - 'a';
        if (!pCrawl->children[index])
            return false;
        pCrawl = pCrawl->children[index];
        key++;
    }

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}

int main()
{
    char keys[][8] = {"the", "a", "there", "answer", "any", "by", "bye", "their"};

    struct TrieNode *root = getNode();

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++)
        insert(root, keys[i]);

    printf("%s --- %s\n", "the", search(root, "the") ? "Present in trie" : "Not present in trie");
    printf("%s --- %s\n", "these", search(root, "these") ? "Present in trie" : "Not present in trie");
    printf("%s --- %s\n", "their", search(root, "their") ? "Present in trie" : "Not present in trie");
    printf("%s --- %s\n", "thaw", search(root, "thaw") ? "Present in trie" : "Not present in trie");

    return 0;
}
