// Author: Gokul Raj, 235, R3A, CSE

#include <stdio.h>
#include <stdlib.h>

#define ARR_LEN 256

struct Node {
    char data;
    struct Node *lhs;
    struct Node *rhs;
};

char inputChar(){
    char c = getchar();
    while(c == '\n')
        c = getchar();
    if(c >= 'a' && c <= 'z')
        c -= 32;
    return c;
}

struct Node *makeTree(char name){
    struct Node *root = malloc(sizeof(struct Node));
    root->data = name;
    char c;
    printf("<< %c: ", name);
    c = inputChar();
    if(c != '0')
        root->lhs = makeTree(c);
    else
        root->lhs = NULL;
    printf("%c >>: ", name);
    c = inputChar();
    if(c != '0')
        root->rhs = makeTree(c);
    else
        root->rhs = NULL;
    return root;
}

char* preOrderTraverse(struct Node *root){
    putchar(root->data);
    if(root->lhs != NULL)
        preOrderTraverse(root->lhs);
    if(root->rhs != NULL)
        preOrderTraverse(root->rhs);
}

char* inOrderTraverse(struct Node *root){
    if(root->lhs != NULL)
        inOrderTraverse(root->lhs);
    putchar(root->data);
    if(root->rhs != NULL)
        inOrderTraverse(root->rhs);
}

char* postOrderTraverse(struct Node *root){
    if(root->lhs != NULL)
        postOrderTraverse(root->lhs);
    if(root->rhs != NULL)
        postOrderTraverse(root->rhs);
    putchar(root->data);
}

void main(){
    printf("Binary Tree Traversal\n---------------------\n");
    printf("Enter Name of Node if it exists.\nEnter '0' if No Node/None\n\n");
    printf("Enter Root Node: ");
    struct Node *tree = makeTree(inputChar());
    printf("Pre Order: ");
    preOrderTraverse(tree);
    putchar('\n');
    printf("In Order: ");
    inOrderTraverse(tree);
    putchar('\n');
    printf("Post Order: ");
    postOrderTraverse(tree);
    putchar('\n');
}