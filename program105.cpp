#include<iostream>
using namespace std;

void binOpr(int a,int b)
{
    cout<<"And operation: "<<(a&b);
    cout<<"\nOr operation: "<<(a|b);
    cout<<"\nExor operation: "<<(a^b);
}

int main()
{
    binOpr(1,10);
    return 0;
}