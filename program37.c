#include<stdio.h>
#include<stdlib.h>

int linear_S(int **arr, int size, int key)
{
    for(int i = 0; i < size; i++)
    {
        if((*arr)[i] == key)
            return i;
    }
    return -1;
}
int main()
{
    int *arr = (int *)malloc(10 * sizeof(int));

    for(int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nIndex: %d", linear_S(&arr, 10, 8));

    free(arr);
    return 0;
}