#include <iostream>
using namespace std;

class MyException {};

int main() {
    try {
        int salary;
        cin >> salary;

        if (salary < 0)
            throw MyException();

        cout << "Salary: " << salary;
    }
    catch (MyException) {
        cout << "Negative salary error";
    }
}