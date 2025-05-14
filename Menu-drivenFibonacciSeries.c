#include <stdio.h>

// Function to generate Fibonacci series without recursion
void fibonacciWithoutRecursion(int n) {
    int a = 0, b = 1, c;
    printf("Fibonacci Series (Without Recursion): ");
    for (int i = 0; i < n; i++) {
        if (i <= 1)
            c = i;
        else {
            c = a + b;
            a = b;
            b = c;
        }
        printf("%d ", c);
    }
    printf("\n");
}

// Function to generate Fibonacci series using recursion
int fibonacciWithRecursion(int n) {
    if (n <= 1)
        return n;
    return fibonacciWithRecursion(n - 1) + fibonacciWithRecursion(n - 2);
}

int main() {
    int choice, n;

    do {
        printf("\nMenu:\n");
        printf("1. Fibonacci Series Without Recursion\n");
        printf("2. Fibonacci Series With Recursion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            if (n < 0) {
                printf("Number of terms must be non-negative.\n");
            } else {
                fibonacciWithoutRecursion(n);
            }
            break;
        case 2:
            printf("Enter the number of terms: ");
            scanf("%d", &n);
            if (n < 0) {
                printf("Number of terms must be non-negative.\n");
            } else {
                printf("Fibonacci Series (With Recursion): ");
                for (int i = 0; i < n; i++) {
                    printf("%d ", fibonacciWithRecursion(i));
                }
                printf("\n");
            }
            break;
        case 3:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
