#include<stdio.h>
typedef struct 
{
    char name[15];
    int salary;
} Employee;

void Scan(Employee *emp)
{
    for(int i=0;i<10;i++)
    {
        scanf("%s\n",emp->name);
        scanf("%d",emp->salary);
    }
}

int main()
{
    
}

