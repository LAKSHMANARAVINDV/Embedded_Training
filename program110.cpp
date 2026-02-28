#include<iostream>
using namespace std;

static int cnt = 0;

int main()
{
    int cap,val;cin>>cap;
    int *arr = new int[cap];
    while(cin>>val)
    {
        if(cnt == cap)
        {
            cap*=2;
            int * temp=new int[cap];
            for(int i=0;i<cnt;i++) temp[i]=arr[i];
            delete[] arr;
            arr=temp;
        }
        arr[cnt++]=val;
    }
   cout << "Elements:\n";
    for(int i = 0; i < cnt; i++)
        cout << arr[i] << " ";
    cout<<"\nSize of array: "<<cap;
    delete[] arr;
    arr=NULL;
    return 0;

}