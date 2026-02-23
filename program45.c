#include<stdio.h>
#include<stdlib.h>

typedef struct compartment
{
    int s;
    struct compartment *next, *prev;
} compartment;

compartment *head = NULL;
compartment *tail = NULL;

void af(int a)
{
    compartment *newnode = (compartment*)malloc(sizeof(compartment));
    newnode->s = a;
    newnode->next = head;
    newnode->prev = NULL;

    if(head != NULL)
        head->prev = newnode;
    else
        tail = newnode;

    head = newnode;
}

void ae(int e)
{
    compartment *newMode = (compartment*)malloc(sizeof(compartment));
    newMode->s = e;
    newMode->next = NULL;
    newMode->prev = tail;

    if (tail != NULL)
        tail->next = newMode;
    else
        head = newMode;

    tail = newMode;
}

void re(int p)
{
    if(head == NULL) return;

    compartment* temp = head;
    int i = 1;

    while (temp != NULL && i < p) {
        temp = temp->next;
        i++;
    }

    if (temp == NULL) return;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    free(temp);
}

void df()
{
    compartment* temp = head;
    printf("Forward: ");
    while (temp != NULL) {
        printf("%d ", temp->s);
        temp = temp->next;
    }
    printf("\n");
}

void db()
{
    compartment* temp = tail;
    printf("Backward: ");
    while (temp != NULL) {
        printf("%d ", temp->s);
        temp = temp->prev;
    }
    printf("\n");
}

int main()
{
    af(60);
    ae(72);
    af(50);
    ae(80);

    df();
    db();

    re(2);

    df();
    db();

    return 0;
}