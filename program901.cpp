#include <iostream>
using namespace std;

// Wrong macro (no parentheses)
#define BAD_SQR(x) x * x

// Correct macro
#define SQR(x) ((x) * (x))

// Inline function
inline int sqr_inline(int x) {
    return x * x;
}

int main() {
    int a = 2, b = 3;

    cout << "BAD_SQR(a + b): " << BAD_SQR(a + b) << endl; // wrong
    cout << "SQR(a + b): " << SQR(a + b) << endl;         // correct
    cout << "Inline: " << sqr_inline(a + b) << endl;      // correct

    // Unit test comparison
    if (SQR(a + b) == sqr_inline(a + b))
        cout << "Test Passed";
    else
        cout << "Test Failed";
}