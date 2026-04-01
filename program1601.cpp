#include<iostream>
#include<string>
using namespace std;
template<class T>
T add(T a,T b){return a+b;}
template<class t2,class t3>
t2 mul(t2 a,t3 b){return a*b;}

int main()
{
    cout<<add(5,10)<<endl;
    string a="Lakshman",b="Aravind";
    cout<<mul(2,3.0);
}