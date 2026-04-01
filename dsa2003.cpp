#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(vector<int>& arr, int k) {
    vector<int> result;
    deque<int> dq;
    
    for (int i = 0; i < arr.size(); i++) {
        if (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }
        
        while (!dq.empty() && arr[dq.back()] <= arr[i]) {
            dq.pop_back();
        }
        
        dq.push_back(i);
        
        if (i >= k - 1) {
            result.push_back(arr[dq.front()]);
        }
    }
    
    return result;
}

int main() {
    vector<int> arr = {1, 3, 1, 2, 0, 5};
    int k = 3;
    
    vector<int> res = slidingWindowMax(arr, k);
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
