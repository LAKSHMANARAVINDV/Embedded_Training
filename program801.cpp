#include <iostream>
#include <fstream>
using namespace std;

int main() {
    try {
        ifstream file("data.txt");
        if (!file)
            throw "File Error";

        int a, b;
        file >> a >> b;

        if (b == 0)
            throw "Division by Zero";

        cout << "Result: " << a / b;
    }
    catch (const char* msg) {
        cout << msg;
    }
}