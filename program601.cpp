#include<iostream>
using namespace std;

int main()
{
    string *n=new string[3];
    n[0]="hello";
    n[1]="world";
    n[2]="using C";
    for(int i=0;i<3;i++) cout<<*(n+i)<<endl;
    return 0;
}