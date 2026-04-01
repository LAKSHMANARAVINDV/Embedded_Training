#include <iostream>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.length() != s2.length()) return false;
    
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    
    return s1 == s2;
}

bool isAnagramFreq(const string& s1, const string& s2) {
    if (s1.length() != s2.length()) return false;
    
    unordered_map<char, int> freq;
    for (char c : s1) freq[c]++;
    
    for (char c : s2) {
        if (freq[c] == 0) return false;
        freq[c]--;
    }
    
    return true;
}

int main() {
    cout << (isAnagram("listen", "silent") ? "Anagram" : "Not") << endl;
    cout << (isAnagram("hello", "world") ? "Anagram" : "Not") << endl;
    
    cout << (isAnagramFreq("listen", "silent") ? "Anagram" : "Not") << endl;
    cout << (isAnagramFreq("abc", "def") ? "Anagram" : "Not") << endl;
    
    return 0;
}
