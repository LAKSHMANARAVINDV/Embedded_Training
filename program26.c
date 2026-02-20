#include<stdio.h>

struct Student
{
    int roll_num,marks;
    char name[100];
}std[5];
 
void display(struct Student s){
    printf("Roll num: %d",s.roll_num);
    printf("\nName: %s",s.name);
    printf("\nMarks: %d",s.marks);
}

int main()
{
    for(int i=0;i<5;i++)
    {
        scanf(" %d",&std[i].roll_num);
        scanf(" %s",&std[i].name);
        scanf(" %d",&std[i].marks);
    }
    int max=std[0].marks,j=0;
    for(int i=1;i<5;i++)
    {
        if(std[i].marks>max) {j=i;max=std[i].marks;}
    }
    display(std[j]);
    return 0;    
}