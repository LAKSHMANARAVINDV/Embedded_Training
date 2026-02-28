#include<iostream>
#include<string.h>
using namespace std;

class Employee
{
    public:
    char name[20];
    float salary;
   
    Employee(string,int);
    
};

class Manager:public Employee
{
    private:
    char dept[10];
    public:
    Manager(string,int,string);
    void display();
};


Employee::Employee(string a,int b){salary=b;strcpy(name,a.c_str());}
Manager::Manager(string n,int s,string d):Employee(n,s){salary=s,strcpy(name,n.c_str()),strcpy(dept,d.c_str());}
void Manager::display(){cout<<salary<<name<<dept;}

int main()
{
     Manager m("Aravind", 50000, "HR");
    m.display();
    return 0;

}
