#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

vector<int> sortByFreq(vector<int>& arr) {
    unordered_map<int, int> freq;
    
    for (int num : arr) freq[num]++;
    
    sort(arr.begin(), arr.end(), [&freq](int a, int b) {
        if (freq[a] != freq[b]) return freq[a] > freq[b];
        return a > b;
    });
    
    return arr;
}

int main() {
    vector<int> arr = {1, 1, 1, 2, 2, 3};
    
    sortByFreq(arr);
    
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}
