#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* Strcpy(char str[])
{
    int len = strlen(str);
    char *s = (char *)malloc(len + 1);
    for(int i = 0; i < len; i++)
        s[i] = str[i];
    s[len] = '\0';
    return s;
}

int main()
{
    char a[10], *b;
    scanf("%9s", a);
    b = Strcpy(a);
    printf("Copied string: %s", b);
    free(b);   
    return 0;
}
