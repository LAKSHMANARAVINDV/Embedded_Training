#include <iostream>
#include <stack>
#include <vector>
using namespace std;

vector<int> nextGreaterCircular(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;
    
    for (int i = 2 * n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i % n]) {
            st.pop();
        }
        if (!st.empty()) {
            result[i % n] = st.top();
        }
        st.push(arr[i % n]);
    }
    return result;
}

int main() {
    vector<int> arr = {1, 2, 1};
    vector<int> res = nextGreaterCircular(arr);
    
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
