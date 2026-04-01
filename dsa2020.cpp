#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> anagramIndices(string s, string p) {
    vector<int> result;
    if (p.length() > s.length()) return result;
    
    unordered_map<char, int> pCount, sCount;
    
    for (char c : p) pCount[c]++;
    
    int matches = 0;
    for (char c : pCount) matches = 0;
    
    for (int i = 0; i < s.length(); i++) {
        sCount[s[i]]++;
        
        if (i >= p.length()) {
            sCount[s[i - p.length()]]--;
            if (sCount[s[i - p.length()]] == 0) {
                sCount.erase(s[i - p.length()]);
            }
        }
        
        if (sCount == pCount) {
            result.push_back(i - p.length() + 1);
        }
    }
    
    return result;
}

int main() {
    vector<int> res = anagramIndices("cbaebabacd", "abc");
    
    for (int idx : res) cout << idx << " ";
    cout << endl;
    
    return 0;
}
