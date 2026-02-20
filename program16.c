#include<stdio.h>
#include<string.h>
#include<stdbool.h>
int find_substring(char st[],char sub[])
{
    int len1=strlen(st), len2=strlen(sub);bool a;
    for(int i=0;i<len1;i++)
    {
        if(st[i]==sub[0])
        {
            a =true;
            for(int j=0;j<len2;j++)
            {
                if(st[j+i]!=sub[j]) a=false;
            }
        } 
        if(a == true) return i;
    } return -1;
}

int main()
{

    char a[10],b[9];
    scanf("%s %s",&a,&b);
    int ind = find_substring(a,b);
    printf("%d",ind);
    return 0;
}