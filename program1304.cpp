#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isValidURL(string url) {
    regex pattern("^https?://[a-zA-Z0-9]([a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?(\\.[a-zA-Z0-9]([a-zA-Z0-9-]{0,61}[a-zA-Z0-9])?)*(/[^\\s]*)?$");
    return regex_match(url, pattern);
}

int main() {
    cout << "=== Validate HTTP/HTTPS URL ===" << endl << endl;
    
    string testCases[] = {
        "http://www.google.com",
        "https://www.google.com",
        "https://github.com",
        "http://example.com/page",
        "https://example.com/path/to/page",
        "https://subdomain.example.com",
        "http://192.168.1.1",
        "ftp://example.com",
        "www.google.com",
        "htp://example.com",
        "https://",
        "https://.com",
        "https://example",
        "https://example.com.invalid.path/",
        "https://my-domain.co.uk/page"
    };
    
    for (string test : testCases) {
        cout << "\"" << test << "\" -> " 
             << (isValidURL(test) ? "Valid" : "Invalid") << endl;
    }
    
    return 0;
}
