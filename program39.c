#include <stdio.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c)
{
    if(top < MAX - 1)
        stack[++top] = c;
}


void pop()
{
    if(top >= 0)
        top--;
}


char peek()
{
    if(top >= 0)
        return stack[top];
    return '\0';
}


int isEmpty()
{
    return (top == -1);
}

int main()
{
    char s[] = "({[]})";
    int i;

    for(i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        if(c == '(' || c == '{' || c == '[')
        {
            push(c);
        }
        else
        {
            if(isEmpty())
            {
                printf("Not valid");
                return 0;
            }

            if((c == ')' && peek() != '(') ||
               (c == ']' && peek() != '[') ||
               (c == '}' && peek() != '{'))
            {
                printf("Not valid");
                return 0;
            }
            pop();
        }
    }

    if(isEmpty())
        printf("Valid");
    else
        printf("Not valid");

    return 0;
}
