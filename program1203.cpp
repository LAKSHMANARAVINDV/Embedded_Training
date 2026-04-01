#include <iostream>
using namespace std;

int toggleBit(int num, int bitPosition) {
    return num ^ (1 << bitPosition);
}

void displayBinary(int num) {
    cout << "Binary: ";
    for (int i = 7; i >= 0; i--) {
        cout << ((num >> i) & 1);
    }
    cout << " (Decimal: " << num << ")" << endl;
}

int main() {
    cout << "=== Toggle the 4th Bit using XOR ===" << endl << endl;
    
    int number = 10;
    cout << "Original number: " << number << endl;
    displayBinary(number);
    
    int bitPosition = 4;
    int result = toggleBit(number, bitPosition);
    
    cout << "\nAfter toggling the " << bitPosition << "th bit:" << endl;
    cout << "Result: " << result << endl;
    displayBinary(result);
    
    cout << "\nToggling again:" << endl;
    int toggled2 = toggleBit(result, bitPosition);
    cout << "Result: " << toggled2 << endl;
    displayBinary(toggled2);
    
    cout << "\n" << string(50, '-') << endl;
    cout << "\nMore Examples:" << endl;
    
    int test[] = {0, 5, 10, 15, 31, 63, 127, 255};
    
    for (int num : test) {
        cout << "\nOriginal: " << num << " -> ";
        displayBinary(num);
        
        int toggled = toggleBit(num, 4);
        cout << "Toggled bit 4: " << toggled << " -> ";
        displayBinary(toggled);
    }
    
    cout << "\n" << string(50, '-') << endl;
    cout << "\nXOR Toggle Explanation:" << endl;
    cout << "1. Create mask: 1 << 4 = 00010000 (16 in decimal)" << endl;
    cout << "2. XOR with original: num ^ (1 << 4)" << endl;
    cout << "3. If bit was 0 -> becomes 1" << endl;
    cout << "4. If bit was 1 -> becomes 0" << endl;
    
    return 0;
}
