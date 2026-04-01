#include <iostream>
using namespace std;

int main() {
    try {
        int n;
        cin >> n;

        if (n < 0)
            throw n;

        cout << "Number: " << n;
    }
    catch (int) {
        cout << "Negative number error";
    }
}