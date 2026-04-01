#include<iostream>
using namespace std;
void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
  
      cout<<endl;
}
void selection(int arr[],int n)
{
    int m=1;
    for(int i=0 ; i < n-1;i++)
    {
        int sel=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[sel])sel=j;
        }
        int temp=arr[sel];
        arr[sel]=arr[i];
        arr[i]=temp;
        cout<<"pass "<<m++<<endl;
        display(arr,5);
    }
}

int main()
{
    int arr[5]={2,5,1,2,3};
    selection(arr,5);
}
