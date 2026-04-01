#include <iostream>
#include <vector>
using namespace std;

int findPeak(vector<int>& arr) {
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] > arr[mid + 1]) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    
    return left;
}

int main() {
    vector<int> arr = {1, 2, 3, 1};
    cout << findPeak(arr) << endl;
    
    vector<int> arr2 = {1, 2, 1, 3, 5, 4, 10, 7, 5};
    cout << findPeak(arr2) << endl;
    
    return 0;
}
