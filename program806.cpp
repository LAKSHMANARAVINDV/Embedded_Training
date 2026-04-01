#include <iostream>
using namespace std;

class Test {
public:
    int id;
    Test(int i) : id(i) {
        cout << "Construct " << id << endl;
    }
    ~Test() {
        cout << "Destruct " << id << endl;
    }
};

int main() {
    try {
        Test t1(1);
        {
            Test t2(2);
            {
                Test t3(3);
                throw 10;
            }
        }
    }
    catch (int) {
        cout << "Exception caught";
    }
}