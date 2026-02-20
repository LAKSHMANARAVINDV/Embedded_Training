#include<stdio.h>
#include <stdlib.h>
/*void push(int *p,int len,int element)
{
    int *new = (int *)malloc((len+1)*sizeof(int));
    if(p == NULL) 
    {
        *p=element;
        return;
    }
    for(int i=0;i<len;i++) {*(new+i)=*(p+i);}
    *(new+len)=element;
    p=new;
    free(new);
    return;
}

void pop(int *p,int len)
{
    int *new = (int *)malloc((len-1)*sizeof(int));
    if(p==NULL) return;
    for(int i=0;i<len-1;i++)
    {
        *(new+i)=*(p+i);
        *(p+i)=NULL;
    }
    *(p+len)=NULL;
    p=new;
    free(new);
    return;
}*/

void push(int **p,int *len,int element)
{
    int *n = (int *)malloc((*len+1)*sizeof(int));
    if(n ==NULL) return;
    for(int i=0;i<*len;i++) n[i]=(*p)[i];
    n[*len]=element;
    free(*p);
    *p=n;  
    (*len)++;
    return;
}

void pop(int **p,int *len)
{
    if(*len==0) return;
    int *ne = NULL;
    if(*len-1>0)
    {
        ne = (int *)malloc((*len-1)*(sizeof(int)));
        if(ne==NULL) return;
        for(int i=0;i<*len-1;i++) ne[i]=(*p)[i];
    }
    free(*p);
    *p=ne;
    (*len)--;
    return;
}

void resize(int **p,int *size,int new_capacity)
{
    if((*size)==new_capacity) return;
    if((*size) < new_capacity)
    {
        int *new_arr = (int *)malloc(new_capacity*sizeof(int));
        if(new_arr == NULL) return;
        for(int i=0;i<(*size);i++)
        {
            new_arr[i] = (*p)[i];
        }
        for(int i=*size;i<new_capacity;i++)
        {
            new_arr[i]=0;
        }
        free(*p);
        *p=new_arr;
        *size=new_capacity;
        return;
    }
    else
    {
        int *new_arr = (int *)malloc(new_capacity*sizeof(int));
        if(new_arr == NULL) return;
        for(int i=0;i<new_capacity;i++)
        {
            new_arr[i] = (*p)[i];
        }
        free(*p);
        *p=new_arr;
        *size=new_capacity;
        return;

    }
}
int main()
{
    int *arr = NULL;
    int size = 0;

    push(&arr, &size, 10);
    push(&arr, &size, 20);
    push(&arr, &size, 30);

    printf("After push:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    pop(&arr, &size);

    printf("After pop:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    resize(&arr, &size, 5);

    printf("After resize to 5:\n");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    free(arr);
    return 0;
} 