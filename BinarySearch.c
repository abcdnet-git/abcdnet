#include <stdio.h>

// Function to implement Binary Search
int binarySearch(int arr[], int left, int right, int key) {
    while (left <= right) {
        // Find the middle element
        int mid = left + (right - left) / 2;

        // Check if the key is present at mid
        if (arr[mid] == key) {
            return mid;  // Key found, return the index
        }

        // If the key is smaller, search the left half
        if (arr[mid] > key) {
            right = mid - 1;
        }
        // If the key is larger, search the right half
        else {
            left = mid + 1;
        }
    }
    
    // If the key was not found
    return -1;
}

// Utility function to print the result
void printResult(int result) {
    if (result == -1) {
        printf("Element not found.\n");
    } else {
        printf("Element found at index: %d\n", result);
    }
}

int main() {
    int n;

    // Take input for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Array to store the elements
    int arr[n];

    // Take input for the elements of the array
    printf("Enter the elements of the array (sorted):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Ask the user for the key to search
    int key;
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Perform Binary Search
    int result = binarySearch(arr, 0, n - 1, key);

    // Print the result
    printResult(result);

    return 0;
}
