#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void swap(char **A, char **B)
{
    char *temp;
    temp=*A;
    *A=*B;
    *B=temp;
}

int main()
{
    char *s1,*s2;
    s1 = (char*)malloc(50);
    s2 = (char*)malloc(50);
    strcpy(s1,"Mdu");
    strcpy(s2,"Chn");
    printf("Before swap: \n%s\n%s\n",s1,s2);
    swap(&s1,&s2);
    printf("After swap: \n%s\n%s\n",s1,s2);
}