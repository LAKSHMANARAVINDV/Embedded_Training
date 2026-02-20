#include<stdio.h>
/*int main()
{
    int n;
    scanf("%d",&n);
    if(n==0)
    {
        putchar('0');
        return 0;
    }
    int a=0,b=1,c=0;
    for(int i=1;i<n;i++)
    {
        printf("%d ",a);
        c=a+b;
        a=b;
        b=c;
    }
    return 0;
}*/

int Finonacci(int n)
{
    if(n==0) return 0;
    if(n==1) return 1;
    return Finonacci(n-1)+Finonacci(n-2);
}

int main()
{
    for(int i = 0; i < 9; i++)
    {
        printf("%d ", Finonacci(i));
    }
    return 0;
}
