#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function for Quick Sort
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // Choosing the last element as the pivot
    int i = low - 1;       // Index of smaller element

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Quick Sort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Insertion Sort function
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Function to generate the Fibonacci series up to a given limit
void generateFibonacci(int fib[], int limit) {
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < limit; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
}

// Fibonacci Search Function
int fibonacciSearch(int arr[], int size, int key, int fib[], int fibSize) {
    int offset = -1;
    int fibM2 = 0;
    int fibM1 = 1;
    int fibM = fibM1 + fibM2;

    while (fibM < size) {
        fibM2 = fibM1;
        fibM1 = fibM;
        fibM = fibM1 + fibM2;
    }

    while (fibM > 1) {
        int i = offset + fibM2 < size - 1 ? offset + fibM2 : size - 1;

        if (arr[i] < key) {
            fibM = fibM1;
            fibM1 = fibM2;
            fibM2 = fibM - fibM1;
            offset = i;
        } else if (arr[i] > key) {
            fibM = fibM2;
            fibM1 = fibM1 - fibM2;
            fibM2 = fibM - fibM1;
        } else {
            return i;
        }
    }

    if (fibM1 && arr[offset + 1] == key) {
        return offset + 1;
    }

    return -1;
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice, n = 0;
    int arr[100];
    int fib[20];

    do {
        printf("\nMenu:-\n");
        printf("1. Read Array\n");
        printf("2. Insertion Sort\n");
        printf("3. Quick Sort\n");
        printf("4. Fibonacci Search\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the number of elements: ");
            scanf("%d", &n);
            printf("Enter %d elements: \n", n);
            for (int i = 0; i < n; i++) {
                scanf("%d", &arr[i]);
            }
            printf("Array read successfully.\n");
            break;
        case 2:
            if (n == 0) {
                printf("Array is empty. Please read the array first.\n");
                break;
            }
            insertionSort(arr, n);
            printf("Array after Insertion Sort: \n");
            printArray(arr, n);
            break;
        case 3:
            if (n == 0) {
                printf("Array is empty. Please read the array first.\n");
                break;
            }
            quickSort(arr, 0, n - 1);
            printf("Array after Quick Sort: \n");
            printArray(arr, n);
            break;
        case 4:
            if (n == 0) {
                printf("Array is empty. Please read the array first.\n");
                break;
            }
            int key;
            printf("Enter the element to search: ");
            scanf("%d", &key);
            generateFibonacci(fib, 20);
            int result = fibonacciSearch(arr, n, key, fib, 20);
            if (result != -1) {
                printf("Element found at index %d.\n", result);
            } else {
                printf("Element not found.\n");
            }
            break;
        case 5:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
