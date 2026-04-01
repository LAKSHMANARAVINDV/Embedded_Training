#include <iostream>
using namespace std;

class Student{
public:
    int id;
    string name;

    void input(){
        cin>>id>>name;
    }
    void display(){
        cout<<id<<" "<<name<<endl;
    }
};

int main(){
    int n;
    cin>>n;

    Student* s = new Student[n];

    for(int i=0;i<n;i++)
        s[i].input();

    for(int i=0;i<n;i++)
        s[i].display();

    delete[] s;
}