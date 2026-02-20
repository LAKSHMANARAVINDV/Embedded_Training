#include<stdio.h>

int main()
{
    int isleap,year;
    scanf("%d",&year);
    isleap=(year%400 == 0)? 1 :( (year%100 == 0) ? 0 : ((year%4 == 0) ? 1 : 0) );
    puts(isleap?"Leap year":"Not leap year");
    return 0;
}