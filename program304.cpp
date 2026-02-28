#include<iostream>
using namespace std;
class Teacher
{
    private: 
    string name;
    public:
    Teacher();
    Teacher(string);
    virtual void tshow();
};

Teacher::Teacher() {name="None";};
Teacher::Teacher(string s) {name=s;}
void Teacher::tshow() {cout<<"Teacher name :"<<name<<endl;}

class Researcher
{
    private:
    string dept;
    public:
    Researcher();
    Researcher(string);
    virtual void rshow();
};

Researcher::Researcher(){dept="None";}
Researcher::Researcher(string s){dept=s;}
void Researcher::rshow(){cout<<"Depeartment name :"<<dept<<endl;}

class Professor:public Teacher,public Researcher
{
    public:
    void tshow() override {cout<<"teacher overrided\n";}
    void rshow() override {cout<<"Researcher overrided\n";}
};
int main()
{
    Professor p;
    Teacher *t=&p;
    Researcher *r= &p;
    t->tshow();
    r->rshow();


}