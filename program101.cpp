#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    string pass;
    cin>>pass;
    pass.length()>8 ? cout<<"Valid password" : cout<<"Invalid password";
    return 0;
}