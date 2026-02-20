// Dependency realationship bw 2 classes 
#include<iostream>
#include<string>
using namespace std;

class Document
{
private:
string text;
public:
Document(string t=""):text(t) {};
string get_text() const;
};

class Printer
{
public:
void print_doc(const Document&);
};

string Document::get_text() const
{
return text;
}

void Printer::print_doc(const Document& doc)
{
cout<<"The document's content are:\n"<<doc.get_text();
}

int main()
{
Document doc("Embedded Emgineering and Testing Services");
Printer P;
P.print_doc(doc);
return 0;
}
