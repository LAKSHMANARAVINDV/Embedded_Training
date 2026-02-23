#include<stdio.h>
#include<stdlib.h>

void sort(int arr[], int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int main()
{
    FILE *fptr1,*fptr2;
    fptr1 = fopen("file1.txt","r");
    fptr2 = fopen("file2.txt","w");
    if(fptr1 == NULL) {printf("File error");return 1;}
    if(fptr2 == NULL) {printf("File error");return 1;}
    int arr[100],n=0;
    while(fscanf(fptr1,"%d",&arr[n]) != EOF) n++;
    fclose(fptr1);
    sort(arr,n);
     for (int i = 0; i < n; i++)
    {
        fprintf(fptr2, "%d ", arr[i]);
    }    
    fclose(fptr2);
    return 0;

}