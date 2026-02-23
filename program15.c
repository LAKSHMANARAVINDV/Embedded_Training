#include<stdio.h>
int main()
{
    int arr[5]={1,2,3,4,5}, avg=0;
    for(int i=0;i<5;i++) avg+=*(arr+i);
    printf("%.1f",(avg/5.00));
    return 0;
}