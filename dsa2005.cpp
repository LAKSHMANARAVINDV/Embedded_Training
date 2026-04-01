#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(nullptr) {}
};

pair<Node*, Node*> splitCircular(Node* head) {
    if (!head) return {nullptr, nullptr};
    
    Node* slow = head, *fast = head, *prev = nullptr;
    
    while (fast && fast->next && fast->next != head) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (fast->next == head) fast = fast->next;
    
    if (prev) prev->next = slow;
    
    Node* temp = slow;
    while (temp->next != head) temp = temp->next;
    temp->next = slow;
    
    return {head, slow};
}

void display(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head;
    
    auto [h1, h2] = splitCircular(head);
    display(h1);
    display(h2);
    
    return 0;
}
