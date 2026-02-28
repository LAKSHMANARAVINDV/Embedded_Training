#include <iostream>
using namespace std;

typedef struct {
    int id;
    string name;
    float salary;
} Employee;

int main()
{
    Employee e1;

    e1.id = 101;
    e1.name = "Aravind";
    e1.salary = 55000.5;

    cout << "Employee ID: " << e1.id << endl;
    cout << "Employee Name: " << e1.name << endl;
    cout << "Employee Salary: " << e1.salary << endl;

    return 0;
}