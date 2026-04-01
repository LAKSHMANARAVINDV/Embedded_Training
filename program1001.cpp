#include <iostream>
using namespace std;

// Define enum Color
enum Color { RED, GREEN, BLUE };

int main() {
    // Create Color enum variables
    Color color1 = RED;
    Color color2 = GREEN;
    Color color3 = BLUE;
    
    // Convert Color to int using static_cast
    int colorValue1 = static_cast<int>(color1);
    int colorValue2 = static_cast<int>(color2);
    int colorValue3 = static_cast<int>(color3);
    
    cout << "Color to int conversion using static_cast:" << endl;
    cout << "RED as int: " << colorValue1 << endl;
    cout << "GREEN as int: " << colorValue2 << endl;
    cout << "BLUE as int: " << colorValue3 << endl;
    
    // Convert int back to Color using static_cast
    int intValue = 1;
    Color convertedColor = static_cast<Color>(intValue);
    cout << "\nInt value 1 converted to Color: " << convertedColor << " (should be GREEN)" << endl;
    
    return 0;
}
