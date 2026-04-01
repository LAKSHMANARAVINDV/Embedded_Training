#include <iostream>
using namespace std;

int setBit(int num, int bitPosition) {
    return num | (1 << bitPosition);
}

void displayBinary(int num) {
    cout << "Binary: ";
    for (int i = 7; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << " (Decimal: " << num << ")" << endl;
}

int main() {
    cout << "=== Set the 3rd Bit using Bitwise OR ===" << endl << endl;
    
    int number = 5;
    cout << "Original number: " << number << endl;
    displayBinary(number);
    
    int bitPosition = 3;
    int result = setBit(number, bitPosition);
    
    cout << "\nAfter setting the " << bitPosition << "th bit:" << endl;
    cout << "Result: " << result << endl;
    displayBinary(result);
    
    cout << "\n" << string(50, '-') << endl;
    
    cout << "\nMore Examples:" << endl;
    int test[] = {0, 1, 7, 15, 31, 127, 255};
    
    for (int num : test) {
        cout << "\nNumber: " << num << " -> ";
        displayBinary(num);
        int newNum = setBit(num, 3);
        cout << "After setting bit 3: " << newNum << " -> ";
        displayBinary(newNum);
    }
    
    cout << "\n" << string(50, '-') << endl;
    cout << "\nBitwise OR Operation Explanation:" << endl;
    cout << "1. Create a mask: 1 << 3 = 00001000 (8 in decimal)" << endl;
    cout << "2. OR with original: num | (1 << 3)" << endl;
    cout << "3. Result: Sets the bit at position 3 to 1" << endl;
    
    return 0;
}
