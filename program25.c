#include<stdio.h>
/*void checker(int arr[9][9])
{
    int ar[10]={0};
    for(int i=0;i<9;i++)
    {
        for(int j=0;j<9;j++)
        {
            ar[arr[i][j]]++;
        }
    }
    for(int i=1;i<10;i++) if(ar[i]!=9) {printf("Test case failed");return;}
    printf("Test case pased");return;

}*/

// chatgpt version

void checker(int array[9][9])
{
    int freq[10]={0};
    for(int i=0;i<9;i++)
    {
        for(int k=1;k<=9;k++) freq[k]=0;
        for(int j=0;j<9;j++) freq[array[i][j]]++;
        for(int k=1;k<=9;k++) if(freq[k]!=1) {printf("Faliure");return;}
    }
     for(int i=0;i<9;i++)
    {
        for(int k=1;k<=9;k++) freq[k]=0;
        for(int j=0;j<9;j++) freq[array[j][i]]++;
        for(int k=1;k<=9;k++) if(freq[k]!=1) {printf("Faliure");return;}
    }
    printf("Passed");return;
}

int main() {
    int sudoku[9][9] = {
        {5,3,4,6,7,8,9,1,2},
        {6,7,2,1,9,5,3,4,8},
        {1,9,8,3,4,2,5,6,7},
        {8,5,9,7,6,1,4,2,3},
        {4,2,6,8,5,3,7,9,1},
        {7,1,3,9,2,4,8,5,6},
        {9,6,1,5,3,7,2,8,4},
        {2,8,7,4,1,9,6,3,5},
        {3,4,5,2,8,6,1,7,9}
    };

    checker(sudoku);

    return 0;
}