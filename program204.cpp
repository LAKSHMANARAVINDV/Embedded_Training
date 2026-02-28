#include <iostream>
using namespace std;

class CryptoBox
{
private:
    string privateKey;

public:
    CryptoBox(string key) : privateKey(key) {}

    friend void dumpForAudit(const CryptoBox&);
};

void dumpForAudit(const CryptoBox& cb)
{
    cout << "Audit Log - Private Key: " << cb.privateKey << endl;
}
/*void hackerFunction(const CryptoBox& cb)
{
    cout << cb.privateKey;  
}*/

int main()
{
    CryptoBox box("ABCD1234");

    dumpForAudit(box);     
   // hackerFunction(box); 
    return 0;
}
