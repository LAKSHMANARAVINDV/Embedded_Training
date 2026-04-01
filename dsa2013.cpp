#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> findDuplicates(const vector<int>& ids) {
    unordered_map<int, int> freq;
    vector<int> result;
    
    for (int id : ids) freq[id]++;
    
    for (const auto& [id, count] : freq) {
        if (count > 1) result.push_back(id);
    }
    
    return result;
}

int main() {
    vector<int> ids = {101, 102, 101, 103, 102, 104};
    
    vector<int> res = findDuplicates(ids);
    
    for (int id : res) cout << id << " ";
    cout << endl;
    
    return 0;
}
