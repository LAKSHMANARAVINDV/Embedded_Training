#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int convert(string s) {
    for (char c : s)
        if (!isdigit(c))
            throw invalid_argument("Non-numeric string");

    return stoi(s);
}

int main() {
    try {
        cout << convert("12a3");
    }
    catch (invalid_argument &e) {
        cout << e.what();
    }
}