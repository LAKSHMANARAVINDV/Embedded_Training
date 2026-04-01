#include <iostream>
#include <vector>
using namespace std;

int maxSubarray(vector<int>& arr, int k) {
    int maxSum = 0;
    int currSum = 0;
    
    for (int i = 0; i < k; i++) {
        currSum += arr[i];
    }
    
    maxSum = currSum;
    
    for (int i = k; i < arr.size(); i++) {
        currSum = currSum - arr[i - k] + arr[i];
        maxSum = max(maxSum, currSum);
    }
    
    return maxSum;
}

int main() {
    vector<int> arr = {1, 4, 2, 10, 2, 3, 1, 0, 20};
    int k = 4;
    
    cout << maxSubarray(arr, k) << endl;
    
    return 0;
}
