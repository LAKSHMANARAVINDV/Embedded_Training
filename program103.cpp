#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n, maxVal = INT_MIN;
    cin >> n;

    int arr[n];

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        if(arr[i] > maxVal)
            maxVal = arr[i];
    }

    int freq[maxVal + 1] = {0};

    for(int i = 0; i < n; i++)
        freq[arr[i]]++;

    cout << "Duplicate elements:\n";

    for(int i = 0; i <= maxVal; i++)
        if(freq[i] > 1)
            cout << i << endl;

    return 0;
}