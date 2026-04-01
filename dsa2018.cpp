#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

string minWindow(string s, string t) {
    if (t.length() > s.length()) return "";
    
    unordered_map<char, int> need, window;
    
    for (char c : t) need[c]++;
    
    int left = 0, minLen = INT_MAX, minStart = 0;
    int formed = 0;
    
    for (int right = 0; right < s.length(); right++) {
        char c = s[right];
        window[c]++;
        
        if (need.count(c) && window[c] == need[c]) {
            formed++;
        }
        
        while (left <= right && formed == need.size()) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }
            
            char lc = s[left];
            window[lc]--;
            if (need.count(lc) && window[lc] < need[lc]) {
                formed--;
            }
            left++;
        }
    }
    
    return minLen == INT_MAX ? "" : s.substr(minStart, minLen);
}

int main() {
    cout << minWindow("ADOBECODEBANC", "ABC") << endl;
    cout << minWindow("a", "a") << endl;
    cout << minWindow("a", "aa") << endl;
    
    return 0;
}
