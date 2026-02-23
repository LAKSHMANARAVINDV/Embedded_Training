#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* create(int val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int height(Node* root)
{
    if(root == NULL)
        return 0;

    return 1 + max(height(root->left), height(root->right));
}

int isBalanced(Node* root)
{
    if(root == NULL)
        return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(lh - rh) <= 1 && 
       isBalanced(root->left) && 
       isBalanced(root->right))
        return 1;

    return 0;
}

int main()
{
    Node* root = create(1);
    root->left = create(2);
   // root->right = create(3);
    root->left->left = create(4);
   // root->left->right = create(5);

    printf("Height of tree: %d\n", height(root));

    if(isBalanced(root))
        printf("Tree is height-balanced\n");
    else
        printf("Tree is not height-balanced\n");

    return 0;
}