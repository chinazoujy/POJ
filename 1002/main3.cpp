#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define TREE_WIDTH 10

int HAS_RESULT = 0;

struct node {
    int count;
    int pass;
    struct node *next[TREE_WIDTH];
};

int insert(struct node *root, int values[], int length)
{
    struct node *curr = root;
    struct node *new_node;
    for (int i=0; i < length; i++) {
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

// dfs 打印
int print(struct node *curr, int num[], int count)
{
    if (curr->count > 1) {
        HAS_RESULT = 1;
        for (int i=0; i < count; i++) {
            std::cout << num[i];
            if (i==2) {
                std::cout << "-";
            }
        }
        std::cout << " " << curr->count << std::endl;
    }
    for (int i=0; i < TREE_WIDTH; i++) {
        if (curr->next[i] == NULL) { continue; }
        num[count++] = i;
        print (curr->next[i], num, count);
        count --;
    }
}

void preprocessing(std::string s, int numbers[])
{
    std::string new_s = "";
    int count = 0;
    for (int i=0; i < s.length(); i++) {
        if (s[i] == '-') {
            continue;
        }else if(s[i] >= 'A' && s[i] <= 'Z') {
            int number;
            if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C') {
                number = 2;
            }else if(s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
                number = 3;
            }else if(s[i] == 'G' || s[i] == 'H' || s[i] == 'I') {
                number = 4;
            }else if(s[i] == 'J' || s[i] == 'K' || s[i] == 'L') {
                number = 5;
            }else if(s[i] == 'M' || s[i] == 'N' || s[i] == 'O') {
                number = 6;
            }else if(s[i] == 'P' || s[i] == 'R' || s[i] == 'S') {
                number = 7;
            }else if(s[i] == 'T' || s[i] == 'U' || s[i] == 'V') {
                number = 8;
            }else if(s[i] == 'W' || s[i] == 'X' || s[i] == 'Y') {
                number = 9;
            }
            numbers[count++] = number;
        }else {
            numbers[count++] = (int)(s[i]-'0');
        }
    }
}

int main()
{
    struct node root = {0, 0, {NULL}};
    int n;
    int stringLen = 7;
    int nums[stringLen];

    std::cin >> n;
    for (int i=0; i < n; i++) {
        std::string temp;
        std::cin >> temp;
        preprocessing(temp, nums);
        insert(&root, nums, stringLen);
    }

    int p_numbers[7];
    print(&root, p_numbers, 0);

    if (HAS_RESULT == 0) {
        std::cout << "No duplicates." << std::endl;
    }
    return 0;
}












