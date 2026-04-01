#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ofstream fout;
    fout.open("sample.txt");

    if(fout.is_open())
    {
        cout<<"File opened successfully for writing\n";
        fout<<"Hello World\n";
        fout<<"C++ File Handling Example\n";
        fout.close();
        cout<<"File closed after writing\n";
    }
    else
    {
        cout<<"File opening failed\n";
        return 0;
    }

    ifstream fin;
    fin.open("sample.txt");

    if(fin.is_open())
    {
        cout<<"\nReading File Content:\n";
        string line;
        while(getline(fin,line))
        {
            cout<<line<<endl;
        }
        fin.close();
    }
    else
    {
        cout<<"File opening failed for reading\n";
    }

    return 0;
}