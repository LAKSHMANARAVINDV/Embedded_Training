#include <iostream>
#include <vector>
using namespace std;

pair<int, int> findPosition(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int start = -1, end = -1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            start = mid;
            right = mid - 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    left = 0;
    right = arr.size() - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) {
            end = mid;
            left = mid + 1;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return {start, end};
}

int main() {
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    
    auto [start, end] = findPosition(arr, 8);
    cout << start << " " << end << endl;
    
    return 0;
}
