#include<stdio.h>

struct Student
{
    int roll_num,marks;
    char name[100];
}std;

typedef struct Student1
{
    int roll_num,marks;
    char name[100];
}std1;

int main()
{
  std.roll_num=10;
  std1 s;
  s.roll_num=12;
  printf("%d %d",s.roll_num,std.roll_num);
}