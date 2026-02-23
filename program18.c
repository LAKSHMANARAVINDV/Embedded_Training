#include<stdio.h>

void merge(int a[],int n1,int b[],int n2,int c[])
{
    int i=0,j=0,k=0;
    while(i<n1 && j<n2)
    {
        if(a[i]<b[j]) c[k++]=a[i++];
        else c[k++]=b[j++];
    }
    while(i<n1) c[k++]=a[i++];
    while(j<n2) c[k++]=b[j++];
}

int main()
{
    int a[]={1,2,3,5,7,8},b[]={4,5,8,19,21},c[11];
    merge(a,6,b,5,c);
    for(int i=0;i<11;i++) printf("%d ",c[i]);
    return 0;
}