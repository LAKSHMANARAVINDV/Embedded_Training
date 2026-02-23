#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node* create(int val)
{
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node *n, int val)
{
    if(n == NULL)
        return create(val);

    if(val > n->data)
        n->right = insert(n->right, val);
    else if(val < n->data)
        n->left = insert(n->left, val);

    return n;
}

Node* search(Node *n, int val)
{
    if(n == NULL || n->data == val)
        return n;

    if(val < n->data)
        return search(n->left, val);
    else
        return search(n->right, val);
}

void inorder(Node* r)
{
    if(r != NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

int main()
{
    Node* root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder Traversal: ");
    inorder(root);

    int key = 40;
    Node* result = search(root, key);

    if(result != NULL)
        printf("\n%d found in BST\n", key);
    else
        printf("\n%d not found in BST\n", key);

    return 0;
}