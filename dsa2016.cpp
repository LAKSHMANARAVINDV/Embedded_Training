#include <iostream>
#include <vector>
using namespace std;

bool canCut(vector<int>& ropes, int k, int maxLen) {
    int pieces = 0;
    for (int rope : ropes) {
        pieces += rope / maxLen;
    }
    return pieces >= k;
}

int maxRopeLength(vector<int>& ropes, int k) {
    int left = 1, right = 0;
    
    for (int rope : ropes) right = max(right, rope);
    
    int result = 0;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canCut(ropes, k, mid)) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    
    return result;
}

int main() {
    vector<int> ropes = {8, 7, 6, 5, 30, 20, 15};
    int k = 4;
    
    cout << maxRopeLength(ropes, k) << endl;
    
    return 0;
}
