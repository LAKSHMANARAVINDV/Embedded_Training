#include<iostream>
using namespace std;

void swap(int *a,int *b)
{
    *a = *a ^ *b;
    *b = *a ^ *b;
    *a = *a ^ *b;
}

void print(int &a,int &b) {cout<<"\nA: "<<a<<"\nB: "<<b<<endl;}

int main()
{
    int a=5,b=10;
    print(a,b);
    swap(&a,&b);
    print(a,b);
    return 0;
}


