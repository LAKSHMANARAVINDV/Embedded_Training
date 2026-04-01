#include <iostream>
#include <fstream>
using namespace std;

void openFile() {
    ifstream file("test.txt");
    if (!file)
        throw string("File cannot be opened");
}

int main() {
    try {
        openFile();
    }
    catch (string msg) {
        cout << msg;
    }
}