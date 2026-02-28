#include<iostream>
#include<string.h>
using namespace std;

bool checkPalindrome(string &n)
{
    int l=n.length()-1,i=0;
    while(i < l) 
    {
        if(n[i]!=n[l]) return false;
        i++,l--;
    }
    return true;
}

int main()
{
    string c;
    cin>>c;
    checkPalindrome(c)?cout<<"Palindrome":cout<<"Not Palindrome";
    return 0;
}