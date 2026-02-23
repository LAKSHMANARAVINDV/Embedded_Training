#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    if(n==0||n==1) puts("1");
    int res=1;
    while(n>0)
    {
        res*=n--;        
    }
    printf("%d",res);

}