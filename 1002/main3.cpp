#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TREE_WIDTH 10

struct node {
    int count;
    int pass;
    struct node *next[TREE_WIDTH];
};

int insert(struct node *root, int values[])
{
    struct node *curr = root, *new_node;
    for (int i=0; i < sizeof(values)/sizeof(int); i++) {
        curr->pass ++;
        if (curr->next[values[i]] == NULL) {
            new_node = (struct node*)malloc(sizeof(struct node));
            memset(new_node, 0, sizeof(struct node));
            curr->next[values[i]] = new_node;
        }
        curr = curr->next[values[i]];
    }
    curr->count ++;
    return 0;
}

int print(struct node *root)
{
    struct node *curr = root;
    while (1) {
        std::cout << curr->count << curr->pass << std::endl;
        for (int i=0; i < TREE_WIDTH; i++) {
            if (curr->next[i] == NULL) { continue; }

        }
    }
}

int main()
{
    struct node root = {0, 0, {NULL}};
    int num[] = {1,2,3,4,5};
    int r = insert(&root, num);
    std::cout << r << std::endl;
    return 0;
}
