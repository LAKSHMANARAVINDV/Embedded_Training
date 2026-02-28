#include<iostream>

using namespace std;

int factorial(int n)
{
    if(n==1||n==0) return 1;
    return n*factorial(n-1);
}

int main()
{
    for(int i=1;i<9;i++) cout<<factorial(i)<<" ";
    return 0;
}
