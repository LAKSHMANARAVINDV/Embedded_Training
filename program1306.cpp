#include <iostream>
#include <regex>
#include <string>
using namespace std;

string formatPhoneNumber(string phone) {
    regex pattern("([0-9]{3})([0-9]{3})([0-9]{4})");
    return regex_replace(phone, pattern, "($1) $2-$3");
}

int main() {
    cout << "=== Convert Phone Number Format ===" << endl << endl;
    
    string phoneNumbers[] = {
        "1234567890",
        "9876543210",
        "5551234567",
        "4155552671",
        "2025551234",
        "1111111111",
        "0000000000",
        "2129876543"
    };
    
    for (string phone : phoneNumbers) {
        cout << "Original: " << phone << " -> Formatted: " << formatPhoneNumber(phone) << endl;
    }
    
    return 0;
}
