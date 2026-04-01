#include <iostream>
#include <vector>
using namespace std;

void sort012(vector<int>& arr) {
    int left = 0, mid = 0, right = arr.size() - 1;
    
    while (mid <= right) {
        if (arr[mid] == 0) {
            swap(arr[left], arr[mid]);
            left++;
            mid++;
        } else if (arr[mid] == 1) {
            mid++;
        } else {
            swap(arr[mid], arr[right]);
            right--;
        }
    }
}

int main() {
    vector<int> arr = {0, 1, 2, 0, 1, 2, 1};
    
    sort012(arr);
    
    for (int x : arr) cout << x << " ";
    cout << endl;
    
    return 0;
}
