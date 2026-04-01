#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool isValidIPv4(string ip) {
    regex pattern("^(([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])\\.){3}([0-9]|[1-9][0-9]|1[0-9]{2}|2[0-4][0-9]|25[0-5])$");
    return regex_match(ip, pattern);
}

int main() {
    cout << "=== Validate IPv4 Address ===" << endl << endl;
    
    string testCases[] = {
        "192.168.1.1",
        "255.255.255.255",
        "0.0.0.0",
        "127.0.0.1",
        "10.0.0.1",
        "172.16.0.1",
        "256.168.1.1",
        "192.168.1",
        "192.168.1.1.1",
        "192.168.-1.1",
        "abc.def.ghi.jkl",
        "192.168.1.256",
        "1.1.1.1",
        "192.168.1.1.1.1",
        "999.999.999.999"
    };
    
    for (string test : testCases) {
        cout << "\"" << test << "\" -> " 
             << (isValidIPv4(test) ? "Valid" : "Invalid") << endl;
    }
    
    return 0;
}
