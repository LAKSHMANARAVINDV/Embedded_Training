#include <iostream>
using namespace std;

class MyClass {
private:
    const int value;  // const member variable
    
public:
    // Constructor
    MyClass(int val) : value(val) {}
    
    // Getter for const member
    int getValue() const {
        return value;
    }
    
    // Incorrect method using const_cast to modify const member
    // This is undefined behavior and should be avoided!
    void setValue(int newValue) {
        // Removing const-ness using const_cast (BAD PRACTICE!)
        const_cast<int&>(value) = newValue;
    }
    
    // Correct way would be using mutable keyword
    // mutable int value; // allows modification in const functions
};

int main() {
    MyClass obj(42);
    
    cout << "Initial value: " << obj.getValue() << endl;
    
    // Using const_cast to modify const member (UNSAFE!)
    obj.setValue(100);
    
    cout << "After using const_cast to modify: " << obj.getValue() << endl;
    
    cout << "\n*** WARNING: This approach is undefined behavior! ***" << endl;
    cout << "const_cast should only be used to remove const qualifiers" << endl;
    cout << "when the underlying object is actually not const." << endl;
    cout << "Modifying a const member is undefined behavior!" << endl;
    
    return 0;
}
