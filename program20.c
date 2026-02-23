#include<stdio.h>

int add(int*,int*);
int sub(int*,int*);
int mul(int*,int*);
int div(int*,int*);

int main()
{
    int (*funcptr[4]) (int*,int*) = {&add,&sub,&mul,&div};
    int choice;
    int a,b;
    scanf("%d %d",&a,&b);
    do{
        scanf("%d",&choice);
        if(choice==1) printf("%d\n",funcptr[0](&a,&b));
        if(choice==2) printf("%d\n",funcptr[1](&a,&b));
        if(choice==3) printf("%d\n",funcptr[2](&a,&b));
        if(choice==4) printf("%d\n",funcptr[3](&a,&b));
        if(choice==0) break;
    } while(choice!=0);
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