#include<stdio.h>
#include<string.h>

void To_upper(char a[])
{
    int len = strlen(a);
    for(int i = 0; i < len; i++)
    {
        if(a[i] >= 'a' && a[i] <= 'z')
            a[i] -= 32;
    }
}

int main()
{
    char c[100];
    scanf("%s", c);
    To_upper(c);
    printf("%s", c);
    return 0;
}
