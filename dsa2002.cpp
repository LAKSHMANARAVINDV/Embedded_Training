#include <iostream>
#include <deque>
#include <string>
using namespace std;

class Editor {
    string text;
    deque<string> undo, redo;
public:
    void insert(char c) {
        undo.push_back(text);
        text += c;
        redo.clear();
    }
    
    void remove() {
        if (!text.empty()) {
            undo.push_back(text);
            text.pop_back();
            redo.clear();
        }
    }
    
    void undoOp() {
        if (!undo.empty()) {
            redo.push_back(text);
            text = undo.back();
            undo.pop_back();
        }
    }
    
    void redoOp() {
        if (!redo.empty()) {
            undo.push_back(text);
            text = redo.back();
            redo.pop_back();
        }
    }
    
    void display() {
        cout << text << endl;
    }
};

int main() {
    Editor ed;
    ed.insert('H');
    ed.insert('i');
    ed.display();
    
    ed.undoOp();
    ed.display();
    
    ed.redoOp();
    ed.display();
    
    return 0;
}
