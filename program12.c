#include<stdio.h>

int main()
{
    char C[1000],c;int i=0,j=0;
    scanf("%s\n%c",&C,&c);
    while(C[i]!='\0')
    {
        if(C[i]!=c)
        {
            C[j]=C[i];j++;
        }
        i++;
    }
    C[j]='\0';
    printf("%s",C);
    return 0;
}