#include <iostream>
#include <string>
using namespace std;

char toLowerBitwise(char c) {
    return c | 32;
}

char toUpperBitwise(char c) {
    return c & ~32;
}

int main() {
    cout << "=== Convert Lowercase to Uppercase using Bitwise Operations ===" << endl << endl;
    
    cout << "ASCII Difference:" << endl;
    cout << "'A' (uppercase): " << (int)'A' << " = " << bitset<8>((int)'A') << endl;
    cout << "'a' (lowercase): " << (int)'a' << " = " << bitset<8>((int)'a') << endl;
    cout << "Difference: " << ((int)'a' - (int)'A') << " (bit 5)" << endl << endl;
    
    string lowercase = "hello world";
    cout << "Original string: " << lowercase << endl;
    cout << "Converted to UPPERCASE:" << endl;
    
    for (char c : lowercase) {
        if (c >= 'a' && c <= 'z') {
            cout << toUpperBitwise(c);
        } else {
            cout << c;
        }
    }
    cout << endl << endl;
    
    cout << string(50, '-') << endl;
    cout << "\nSingle Characters:" << endl;
    
    char testChars[] = {'a', 'b', 'z', 'A', 'B', 'Z', '1', '5', '9'};
    
    for (char c : testChars) {
        cout << "Char: " << c << " (ASCII: " << (int)c << ") -> ";
        if (c >= 'a' && c <= 'z') {
            char upper = toUpperBitwise(c);
            cout << upper << " (ASCII: " << (int)upper << ")" << endl;
        } else if (c >= 'A' && c <= 'Z') {
            char lower = toLowerBitwise(c);
            cout << lower << " (ASCII: " << (int)lower << ")" << endl;
        } else {
            cout << c << " (Not a letter, unchanged)" << endl;
        }
    }
    
    cout << "\n" << string(50, '-') << endl;
    cout << "\nString Conversion Examples:" << endl;
    
    string testStrings[] = {
        "hello world",
        "The Quick Brown Fox",
        "ALREADY UPPERCASE",
        "MixedCaseString"
    };
    
    for (string str : testStrings) {
        cout << "\nOriginal: " << str << endl;
        cout << "Uppercase: ";
        for (char c : str) {
            if (c >= 'a' && c <= 'z') {
                cout << toUpperBitwise(c);
            } else {
                cout << c;
            }
        }
        cout << endl;
    }
    
    return 0;
}
