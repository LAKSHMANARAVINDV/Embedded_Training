#include <iostream>
#include <vector>
using namespace std;

int longestSubarray(vector<int>& arr, int k) {
    int maxLen = 0;
    int left = 0, currSum = 0;
    
    for (int right = 0; right < arr.size(); right++) {
        currSum += arr[right];
        
        while (currSum > k && left <= right) {
            currSum -= arr[left];
            left++;
        }
        
        maxLen = max(maxLen, right - left + 1);
    }
    
    return maxLen;
}

int main() {
    vector<int> arr = {1, 1, 1, 5, 1, 1, 1, 1};
    int k = 5;
    
    cout << longestSubarray(arr, k) << endl;
    
    return 0;
}
