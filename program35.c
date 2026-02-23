#include<stdio.h>

int add(int*,int*);
int sub(int*,int*);
int mul(int*,int*);
int div(int*,int*);

int main()
{
    int (*funcptr[4]) (int*,int*) = {&add,&sub,&mul,&div};
    int a,b;
    scanf("%d %d",&a,&b);
    for(int i=0;i<4;i++)
    {
        printf("%d\n", funcptr[i](&a,&b));
    }
    return 0;
}

int add(int* a,int* b)
{
    return *a+*b;
}
int sub(int* a,int* b)
{
    return *a-*b;
}
int mul(int* a,int* b)
{
    return (*a)*(*b);
}
int div(int* a,int* b)
{
    if(*b==0) return -1;
    return (*a)/(*b);
}