#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isOnlyDigits(string str) {
    regex pattern("^[0-9]+$");
    return regex_match(str, pattern);
}

int main() {
    cout << "=== Validate String Contains Only Digits ===" << endl << endl;
    
    string testCases[] = {
        "12345",
        "abc123",
        "000999",
        "12.34",
        "123-456",
        "9876543210",
        "0",
        "",
        "123 456",
        "-123"
    };
    
    for (string test : testCases) {
        cout << "\"" << test << "\" -> " << (isOnlyDigits(test) ? "Valid" : "Invalid") << endl;
    }
    
    return 0;
}
