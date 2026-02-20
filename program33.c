#include<stdio.h>

enum st{ PENDING, SHIPPED, DELIVERED};

int main()
{
    enum st a=PENDING,b=SHIPPED,c=DELIVERED;
    printf("%d %d %d",a,b,c);
}