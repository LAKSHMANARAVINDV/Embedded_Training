#include<iostream>
#include<string.h>

using namespace std;

int main()
{
    string str;
    cin>>str;
    cout<<"Length of string : "<<str.length()<<endl;
    for(char &c:str)
    {
        if(c >= 97 && c<= 122) c=c-32;
    }
    cout<<str;
    return 0;
}