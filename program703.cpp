#include<iostream>
#include<fstream>
using namespace std;

class Employee
{
public:
    int id;
    char name[30];
    float salary;

    void getData()
    {
        cout<<"Enter ID: ";
        cin>>id;
        cout<<"Enter Name: ";
        cin>>name;
        cout<<"Enter Salary: ";
        cin>>salary;
    }

    void display()
    {
        cout<<"ID: "<<id<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<endl;
        cout<<"-------------------\n";
    }
};

int main()
{
    Employee e;

    ofstream fout("employee.dat", ios::binary);
    e.getData();
    fout.write((char*)&e, sizeof(e));
    fout.close();

    ifstream fin("employee.dat", ios::binary);
    Employee e2;

    cout<<"\nReading from file:\n";
    while(fin.read((char*)&e2, sizeof(e2)))
    {
        e2.display();
    }
    fin.close();

    return 0;
}