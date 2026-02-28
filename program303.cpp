#include<iostream>
using namespace std;
class Device{public:Device(){cout<<"Device class called\n";}};
class Mobile:public Device{public:Mobile(){cout<<"Device class called\n";}};
class Smartphone:public Mobile{public:Smartphone(){cout<<"Smartphone class called\n";}};

int main()
{
    Smartphone();
}