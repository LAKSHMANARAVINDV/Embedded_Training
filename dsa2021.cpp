#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>> twoSum(vector<int>& arr, int target) {
    vector<pair<int, int>> result;
    int left = 0, right = arr.size() - 1;
    
    while (left < right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            result.push_back({arr[left], arr[right]});
            left++;
            right--;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {2, 3, 4, 5, 7};
    int target = 9;
    
    vector<pair<int, int>> res = twoSum(arr, target);
    
    for (auto p : res) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    return 0;
}
