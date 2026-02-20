#include<iostream>
using namespace  std;

// Overloading << and >> operator

class Number
{
public:
int n;
Number(int num=0): n(num) {};
friend istream& operator>>(istream& in, Number& a1);
friend ostream& operator<<(ostream& out, Number& a2); 
};


istream& operator>>(istream& in, Number& a1)
{
in>>a1.n;
return in;
}

ostream& operator<<(ostream& out, Number& a1)
{
out<<a1.n;
return out;
}

int main()
{
Number a(5),b;
cin>>b;
cout<<b<<endl;
cout<<a;
return 0;
}