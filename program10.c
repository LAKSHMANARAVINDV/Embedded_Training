#include<stdio.h>
#include<stdbool.h>
#include<math.h>

bool check_prime_basic(int n)
{
    if(n<=1) return false;
if(n==2) return true;
    for(int i=3;i<n;i++)
    {
        if(n%i == 0) return false;
    }
    return true;
}

bool check_prime_optimized(int n)
{
    if(n<2 || n%2==0) return false;
    if(n==2) return true;
    for(int i=3; (i*i)<n; i++) {if(n%i==0) return false;}
    return true;
}

bool check_armstrong(int n)
{
    int dig=0,temp=n,sum=0;
    while(temp!=0){++dig;temp/=10;}
    temp=n;
    while(temp!=0)
    {
        sum += (int)pow(temp%10,dig);
        temp/=10;
    }
    return sum==n;
}

bool check_perfect(int n)
{
    if(n<1) return false;
    if(n==1) return true;
    int sum=1;
    for(int i=2;i<n;i++)
    {
        if(n%i==0) sum+=i;
    }
    return sum==n;
}

int main()
{
    printf("%d",check_prime_basic(13));
    printf("%d",check_prime_optimized(7));
    printf("%d",check_armstrong(153));
    printf("%d",check_perfect(6));
    
}