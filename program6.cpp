// Compare two Employee class using operator overloading 
#include<iostream>
#include<string>
using namespace std;

class Employee
{
private:
int emp_id;
string emp_name;
double salary;
public:
Employee(int i=0, string n="", double s=0): emp_id(i),emp_name(n),salary(s) {};
int operator<(Employee&);
int operator==(Employee&);
int operator>(Employee&);
};

int Employee::operator==(Employee& e)
{
return salary==e.salary;
}

int Employee::operator<(Employee& e)
{
return salary<e.salary;
}

int Employee::operator>(Employee& e)
{
return salary>e.salary;
}

int main()
{
Employee A(16,"Varun",13000) ,B(17,"Tharun",13001);
if(A==B) cout<<"Both are equal";
else if(A>B) cout<<"Employee 1 is higher";
else cout<<"Employee 2 is higher";
}