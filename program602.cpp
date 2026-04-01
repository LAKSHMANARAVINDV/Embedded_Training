#include <iostream>
using namespace std;

int main() {
    int x = 10;
    int* p = &x;
    int** pp = &p;

    **pp = 50;   

    cout << "Value of x = " << x << endl;
}