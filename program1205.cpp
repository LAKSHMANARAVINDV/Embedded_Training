#include <iostream>
using namespace std;

int computeXORChecksum(int arr[], int size) {
    int checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum ^= arr[i];
    }
    return checksum;
}

int main() {
    cout << "=== XOR Checksum for Array of Integers ===" << endl << endl;
    
    int arr1[] = {5, 10, 15, 20};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "Array 1: ";
    for (int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    int checksum1 = computeXORChecksum(arr1, size1);
    cout << "XOR Checksum: " << checksum1 << endl;
    
    cout << "Calculation: 5 ^ 10 ^ 15 ^ 20 = " << checksum1 << endl << endl;
    
    cout << string(50, '-') << endl;
    
    int arr2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "\nArray 2: ";
    for (int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    
    int checksum2 = computeXORChecksum(arr2, size2);
    cout << "XOR Checksum: " << checksum2 << endl << endl;
    
    cout << string(50, '-') << endl;
    
    int arr3[] = {100, 200, 50, 150, 75};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    
    cout << "\nArray 3: ";
    for (int i = 0; i < size3; i++) {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    int checksum3 = computeXORChecksum(arr3, size3);
    cout << "XOR Checksum: " << checksum3 << endl << endl;
    
    cout << string(50, '-') << endl;
    cout << "\nVerify Checksum Property:" << endl;
    
    int testArr[] = {7, 14, 21, 28};
    int testSize = 4;
    cout << "Array: ";
    for (int x : testArr) cout << x << " ";
    cout << endl;
    
    int result = computeXORChecksum(testArr, testSize);
    cout << "Checksum: " << result << endl;
    cout << "Checksum ^ Checksum = " << (result ^ result) << " (always 0)" << endl;
    cout << "If array XOR'd again: " << (computeXORChecksum(testArr, testSize) ^ testArr[0]) << endl;
    
    cout << "\n" << string(50, '-') << endl;
    cout << "\nDetect Single Bit Flip:" << endl;
    
    int original[] = {10, 20, 30, 40};
    int origChecksum = computeXORChecksum(original, 4);
    cout << "Original array checksum: " << origChecksum << endl;
    
    int modified[] = {10, 20, 35, 40};
    int modChecksum = computeXORChecksum(modified, 4);
    cout << "Modified array checksum: " << modChecksum << endl;
    cout << "Checksums match: " << (origChecksum == modChecksum ? "Yes" : "No") << endl;
    
    return 0;
}
