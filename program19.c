#include <stdio.h>

// Define arithmetic functions
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b != 0) return a / b;
    else {
        printf("Error: Division by zero!\n");
        return 0;
    }
}

int main() {
    int (*operation)(int, int);
    int x = 10, y = 5;
    char choice;
    printf("Choose operation (+, -, *, /): ");
    scanf(" %c", &choice);
    switch (choice) {
        case '+':
            operation = add;
            break;
        case '-':
            operation = subtract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            operation = divide;
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    int result = operation(x, y);
    printf("Result: %d\n", result);
    return 0;
}