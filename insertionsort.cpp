#include<iostream>
using namespace std;

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
  
      cout<<endl;
}

void insertionsort(int arr[],int n)
{
    int m=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(arr[i]<arr[j])
            {
                int temp=arr[i];arr[i]=arr[j];arr[j]=temp;
            }
        }
        cout<<"pass"<<m++<<endl;
        display(arr,n);
    }
}

int main()
{
    int arr[5]={2,4,1,2,3};
    insertionsort(arr,5);
    return 0;
}
