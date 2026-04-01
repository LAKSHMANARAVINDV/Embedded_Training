#include<iostream>
using namespace std;

void display(int arr[], int n);

void Bubblesort(int arr[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        display(arr,n);
    }
}

void display(int arr[], int n)
{
    for(int i=0;i<n;i++)
       cout<<arr[i]<<" ";
  
      cout<<endl;
}

int main()
{
    int a[7]={2,1,4,2,6,7,4};
    Bubblesort(a,7);
    return 0;
}