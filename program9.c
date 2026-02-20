#include<stdio.h>
#include<limits.h>

int main()
{
    int n,revn=0;
    scanf("%d",&n);
    while(n!=0)
    {
        revn=(revn*10)+(n%10);
        if(revn> INT_MAX || revn< INT_MIN) {printf("Overflow");return 0;}
        n/=10;
    }printf("%d",revn);
}