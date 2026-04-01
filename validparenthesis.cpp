#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
    string s = "({[]})";
    stack<char> st;

    for(char c : s)
    {
        if(c=='(' || c=='{' || c=='[')
        {
            st.push(c);
        }
        else
        {
            if(st.empty())
            {
                cout << "Not valid";
                return 0;
            }

            if((c==')' && st.top()!='(') ||
               (c==']' && st.top()!='[') ||
               (c=='}' && st.top()!='{'))
            {
                cout << "Not valid";
                return 0;
            }
            st.pop();
        }
    }

    if(st.empty()) cout << "Valid";
    else cout << "Not valid";

    return 0;
}
