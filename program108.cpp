#include<iostream>
#include<string.h>
using namespace std;

typedef struct 
{
    char name[20];int id;     
}Customer;

typedef struct 
{
    Customer c;
    int num;char name[15];
    void get();
    void show();
}Order;

void Order::get()
{
    int id,num;string name,ord;
    cout<<"Enter Details: cust id,cust name,order id,order nm";
    cin>>id>>name>>num>>ord;
    c.id=id;
    strcpy(c.name,name.c_str());
    this->num=num;
    strcpy(this->name,ord.c_str());
}

void Order::show()
{
    cout<<"Customer name :"<< c.name<<endl;
    cout<<"Customer id   :"<<c.id<<endl;
    cout<<"Oder id       :"<<num<<endl;
    cout<<"Order Name    :"<<name<<endl;
}
int main()
{
    Order c;
    c.get();
    c.show();

}



