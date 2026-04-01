#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    fstream file;
    file.open("sample.txt", ios::in);

    int count = 0;
    string line;

    while(getline(file,line))
    {
        count++;
    }
    file.close();

    file.open("sample.txt", ios::app);
    file<<"\nTotal Lines: "<<count;
    file.close();

    cout<<"Total Lines counted and appended successfully\n";

    return 0;
}