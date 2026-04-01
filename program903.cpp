#include <iostream>
#include <cassert>
using namespace std;

#define ASSERT(cond) \
    if (!(cond)) { \
        cout << "Assertion failed at " << __FILE__ << ":" << __LINE__ << endl; \
        cout << "Compiler: " << __VERSION__ << endl; \
    }

int main() {
    cout << "Compiler Version: " << __VERSION__ << endl;

    int x = 5;
    ASSERT(x == 10); // will fail

    cout << "Program continues...";
}