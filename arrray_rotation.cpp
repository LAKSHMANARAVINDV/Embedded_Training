#include<iostream>
using namespace std;
int main()
{
    int a[]={1,2,3,4,5,6,7,8,9},k=3;
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<k;i++){
        int temp = a[n-1];
        for(int i=n-1;i>0;i--) a[i]=a[i-1];
        a[0]=temp;
    }
    for(int i:a) cout<<i<<" ";
    return 0;
}