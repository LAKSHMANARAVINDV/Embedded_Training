#include <iostream>
#include <regex>
#include <string>
using namespace std;

bool matchApple(string str) {
    regex pattern("apple", regex::icase);
    return regex_search(str, pattern);
}

int main() {
    cout << "=== Match 'apple' Regardless of Case ===" << endl << endl;
    
    string testCases[] = {
        "apple",
        "APPLE",
        "Apple",
        "aPpLe",
        "I like apple pie",
        "She bought an APPLE",
        "apples in the basket",
        "application",
        "pineapple",
        "The Apple company",
        "no fruit here",
        "BANANA and orange"
    };
    
    for (string test : testCases) {
        cout << "\"" << test << "\" -> " 
             << (matchApple(test) ? "Match" : "No Match") << endl;
    }
    
    return 0;
}
