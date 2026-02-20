#include <unistd.h>
#include<stdio.h>


int main()
{
    //puts("First C program");
    char str[] = "First C Program";
    int i=0;
    while(str[i]!='\0') {putchar(str[i]);i++;}
    return 0;
}
