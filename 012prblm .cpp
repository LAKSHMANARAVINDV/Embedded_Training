#include<iostream>
using namespace std;
int main()
{
    int a[] = {1,2,1,0,2,1,2,0,2,1,0,2,0,0,0,1,1,1,2,1,0,1};
    int zero = 0,one = 0,two = (sizeof(a)/sizeof(a[0]))-1;
    while(one<=two)
    {
        if(a[one]==0){
            swap(a[one],a[zero]);
            zero++,one++;
        }
        else if(a[one]==1) one++;
        else{
            swap(a[two],a[one]);
            two--;
        }
    }
    for(int i:a) cout<<i<<endl;
    return 0;

}