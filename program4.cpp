#include<iostream>
using namespace  std;

class seed
{
public:
seed()
{
cout<<"Seed class created"<<endl;
}
~seed()
{
cout<<"seed class destroyed"<<endl;
}
};

class tree
{
public:
seed e;
tree()
{
cout<<"tree class created"<<endl;
}
~tree()
{
cout<<"tree class destroyed"<<endl;
}
};

int main()
{
tree m;
return 0;
}
