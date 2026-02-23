#include <stdio.h>

int main()
{
    int a, b;

    scanf("%d %d", &a, &b);

    printf("Sum = %d\n", a + b);
    printf("Difference = %d\n", a - b);
    printf("Product = %d\n", a * b);

    if (b != 0)
        printf("Quotient = %d\n", a / b);
    else
        printf("Quotient = Undefined (division by zero)\n");

    return 0;
}
