#include <iostream>
#include <string>
using namespace std;

string compress(const string& str) {
    if (str.empty()) return "";
    
    string result = "";
    int count = 1;
    
    for (int i = 0; i < str.length(); i++) {
        if (i + 1 < str.length() && str[i] == str[i + 1]) {
            count++;
        } else {
            result += str[i];
            if (count > 1) result += to_string(count);
            count = 1;
        }
    }
    
    return result;
}

int main() {
    cout << compress("aaabbbcccc") << endl;
    cout << compress("abcdef") << endl;
    cout << compress("aaaaaa") << endl;
    
    return 0;
}
