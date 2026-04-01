#include <iostream>
#include <cstdint>
using namespace std;

int main() {
    uintptr_t addr = 1000;   // arbitrary integer address

    int* ptr = reinterpret_cast<int*>(addr);

    cout << "Pointer value: " << ptr << endl;

    // Dangerous: dereferencing may crash
    // cout << *ptr; 

    return 0;
}