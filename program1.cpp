#include<iostream>
#include<thread>

using namespace  std;
// Overloading subscript operator[] to access array members
class Array
{
public:
int l;
int arr[100];
Array(int n=0):l(n)
{
for(int i=0; i<l; i++) cin>>arr[i];
}
int operator[] (int);
};

int Array::operator[] (int I)
{
if(I>l) return 1;
return arr[I];
}

int main()
{
Array a(3);
cout<<a[2]<<endl;
cout<<"hello world";
return 0;
}