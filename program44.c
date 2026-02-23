#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
    char name[100];
    struct Node *next;
} Node;

Node* head = NULL;

void add(char name[])
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);

    if(head == NULL)
    {
        head = newNode;
        head->next = head;
    }
    else
    {
        Node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

void removeSong(char name[])
{
    if(head == NULL) return;

    Node *temp = head, *prev = NULL;

    
    if(strcmp(head->name, name) == 0)
    {
        if(head->next == head)
        {
            free(head);
            head = NULL;
            return;
        }

        Node *last = head;
        while(last->next != head)
            last = last->next;

        Node *del = head;
        head = head->next;
        last->next = head;
        free(del);
        return;
    }

    do
    {
        prev = temp;
        temp = temp->next;

        if(strcmp(temp->name, name) == 0)
        {
            prev->next = temp->next;
            free(temp);
            return;
        }

    } while(temp != head);
}

void play(int k)
{
    if(head == NULL) return;

    Node *temp = head;

    for(int i = 0; i < k; i++)
    {
        printf("%s\n", temp->name);
        temp = temp->next;
    }
}

int main()
{
    add("Believer");
    add("Shape of You");
    add("Blinding Lights");
    add("Perfect");
    add("Faded");

    printf("Playlist for 10 iterations:\n");
    play(10);

    printf("\nRemoving 'Perfect'\n");
    removeSong("Perfect");

    printf("\nPlaylist after removal:\n");
    play(10);

    return 0;
}