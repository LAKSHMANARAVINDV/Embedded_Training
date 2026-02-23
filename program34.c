#include<stdio.h>

typedef union
{
    long int x;
    int y;
    char c[100];
}str;

typedef struct
{
    long int x;
    int y;
    char c[100];
}str1;

int main()
{
    str a,b,d;
    str1 e;
    e.x=10;
    a.x=10;
    b.y=1.222;
    scanf("%s",&d.c);
    printf("%d %d",sizeof(a),sizeof(e));
    return 0;
}
