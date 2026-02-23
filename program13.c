#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>

bool check_palindrome(char a[])
{
    int left=0,right=strlen(a)-1;
    while(left<right)
    {
        while(left<right && !isalnum(a[left])) left++;
        while(left<right && !isalnum(a[right])) right--;
        if(tolower(a[left])!=tolower(a[right])) return 0;
        left++,right--;
    }
    return 1;
}
int main()
{
     char str[100];
    fgets(str, sizeof(str), stdin);

    if(check_palindrome(str))
        printf("Palindrome");
    else
        printf("Not Palindrome");

    return 0;
}
