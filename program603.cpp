#include <iostream>
using namespace std;

int add(int a,int b){ return a+b; }
int sub(int a,int b){ return a-b; }
int mul(int a,int b){ return a*b; }
int divide(int a,int b){ return a/b; }

int main(){
    int (*fp)(int,int);
    int ch,a,b;

    cout<<"1.Add 2.Sub 3.Mul 4.Div\n";
    cin>>ch;
    cin>>a>>b;

    switch(ch){
        case 1: fp=add; break;
        case 2: fp=sub; break;
        case 3: fp=mul; break;
        case 4: fp=divide; break;
        default: return 0;
    }

    cout<<"Result = "<<fp(a,b);
}