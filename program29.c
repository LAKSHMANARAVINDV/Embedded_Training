#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int id, price;
    char name[20];
} Item;

void add(Item** A, int* capacity, int* count)
{
    int new_size = *capacity + *count;

    Item *temp = (Item*)malloc(new_size * sizeof(Item));
    if (temp == NULL) {
        printf("Allocation failed\n");
        return;
    }

    for (int i = 0; i < *capacity; i++)
        temp[i] = (*A)[i];   // corrected

    for (int i = *capacity; i < new_size; i++) {
        printf("Enter Details (id price name): ");
        scanf("%d %d %s",
              &temp[i].id,
              &temp[i].price,
              temp[i].name);   // removed &
    }

    free(*A);
    *A = temp;
    *capacity = new_size;
}

void delete(Item** A, int *capacity, int element)
{
    if (*capacity == 0) {
        printf("Array is empty\n");
        return;
    }

    Item *temp = (Item*)malloc(*capacity * sizeof(Item));
    if (temp == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    int k = 0;  
    for (int i = 0; i < *capacity; i++) {
        if ((*A)[i].id != element) {
            temp[k++] = (*A)[i];   
        }
    }

    free(*A);      
    *A = temp;      
    *capacity = k;
}

int main()
{
    int size, addCount;

    printf("Enter initial size: ");
    scanf("%d", &size);

    Item *A = (Item*)malloc(size * sizeof(Item));
    if (A == NULL) return 1;

    for (int i = 0; i < size; i++) {
        printf("Enter id price name: ");
        scanf("%d %d %s",
              &A[i].id,
              &A[i].price,
              A[i].name);
    }

    printf("How many new items to add: ");
    scanf("%d", &addCount);

    add(&A, &size, &addCount);

    printf("\nAll Items:\n");
    for (int i = 0; i < size; i++)
        printf("%d %d %s\n",
               A[i].id,
               A[i].price,
               A[i].name);
               delete(&A,&size,2);
 printf("\nAll Items:\n");
    for (int i = 0; i < size; i++)
        printf("%d %d %s\n",
               A[i].id,
               A[i].price,
               A[i].name);
    free(A);
    return 0;
}

