#include<stdio.h>
#include<string.h>

struct Student
{
    int rn,m;
    char n[100];
};

void disp(struct Student e)
{
    printf("%d %s %d",e.rn,e.n,e.m);
}

int main()
{
    struct Student std, *ptr;
    std.rn = 10;
    std.m=100;
    strcpy(std.n,"Aravind");
    ptr=&std;
    printf("%d\n",ptr->m);
    printf("%d",sizeof(ptr));
    return 0;
}   