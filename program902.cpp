#include <iostream>
using namespace std;

#define LOG(msg) cout << __FILE__ << ":" << __LINE__ << " [" << __func__ << "] " << msg << endl;

void funcA() {
    LOG("Inside funcA");
}

void funcB() {
    LOG("Inside funcB");
}

int main() {
    LOG("Start main");
    funcA();
    funcB();
    LOG("End main");
}