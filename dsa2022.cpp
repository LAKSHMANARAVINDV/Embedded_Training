#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    
    int i = 0;
    
    for (int j = 1; j < arr.size(); j++) {
        if (arr[j] != arr[i]) {
            i++;
            arr[i] = arr[j];
        }
    }
    
    return i + 1;
}

int main() {
    vector<int> arr = {1, 1, 2, 2, 3};
    
    int len = removeDuplicates(arr);
    
    cout << len << " ";
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}
