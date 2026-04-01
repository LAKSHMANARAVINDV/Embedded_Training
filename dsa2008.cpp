#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void sortByLength(vector<string>& strs) {
    sort(strs.begin(), strs.end(), [](const string& a, const string& b) {
        return a.length() < b.length();
    });
}

int main() {
    vector<string> strs = {"apple", "a", "banana", "hi", "code"};
    
    sortByLength(strs);
    
    for (const string& s : strs) {
        cout << s << " ";
    }
    cout << endl;
    
    return 0;
}
