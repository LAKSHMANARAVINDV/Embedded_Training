#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isValidEmail(const string& email) {
    regex pattern("^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\\.[a-zA-Z]{2,}$");
    return regex_match(email, pattern);
}

bool isValidInvoice(const string& inv) {
    regex pattern("^INV-\\d{4}-\\d{2}-\\d{6}$");
    return regex_match(inv, pattern);
}

int main() {
    cout << (isValidEmail("john@example.com") ? "Valid" : "Invalid") << endl;
    cout << (isValidEmail("invalid.email@") ? "Valid" : "Invalid") << endl;
    
    cout << (isValidInvoice("INV-2025-01-000123") ? "Valid" : "Invalid") << endl;
    cout << (isValidInvoice("inv-2025-01-000123") ? "Valid" : "Invalid") << endl;
    
    return 0;
}
