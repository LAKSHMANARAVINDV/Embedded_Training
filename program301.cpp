#include<iostream>
#include<string.h>

using namespace std;

class Book
{
    private:
    int isbn;
    string title,author;
    public:
    Book();
    void setters(const string&,const string&);
    void print();
    void updateTitle(const string&);
};
Book::Book() {cout<<"Book created";};

void Book::print(){
    cout<<"Title :"<<title<<"\nAuthor :"<<author<<endl;
}

void Book::updateTitle(const string& s)
{
    title=s;
}

void Book::setters(const string& t,const string& a)
{
    title=t,author=a;
}

int main()
{
    Book s;
    s.setters("Narnia","Jk rowling");
    s.print();
    s.updateTitle("ssss");
    s.print();
}