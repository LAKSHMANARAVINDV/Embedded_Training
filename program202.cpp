#include<iostream>
using namespace std;

class Rectangle
{
    private:
    int l,w;
    public:
    Rectangle(int,int);
    ~Rectangle();
    static int count;
};
int Rectangle::count=0; 
Rectangle::Rectangle(int a,int b):l(a),w(b){
    count++;
    if(l<0||w<0) {cout<<count<<" Illegal Parameters\n";}
    else cout<<count<<" Rectangle Object created\n";
} 
Rectangle::~Rectangle(){cout<<count<<" Rectangle Object destroyed\n";count--;};

int main()
{
    Rectangle a(10,4),b(-1,100);

}