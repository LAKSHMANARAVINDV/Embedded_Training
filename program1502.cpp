#include<iostream>
using namespace std;

namespace Company
{
    namespace HR
    {
        void policy()
        {
            cout<<"Joining period : 3 months"<<endl;
        }
    };
};

int main()
{
    Company::HR::policy();
    return 0;
}