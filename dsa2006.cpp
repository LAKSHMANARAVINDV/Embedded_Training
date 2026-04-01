#include <iostream>
#include <vector>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(nullptr), prev(nullptr) {}
};

vector<pair<int, int>> findPairs(Node* head, int target) {
    vector<pair<int, int>> pairs;
    
    Node* left = head;
    Node* right = head;
    while (right->next) right = right->next;
    
    while (left && right && left != right && left->prev != right) {
        int sum = left->data + right->data;
        if (sum == target) {
            pairs.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } else if (sum < target) {
            left = left->next;
        } else {
            right = right->prev;
        }
    }
    
    return pairs;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    
    vector<pair<int, int>> res = findPairs(head, 5);
    
    for (auto p : res) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
    
    return 0;
}
