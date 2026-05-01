#include <stdio.h>

// Simple Bubble Sort (to make array sorted first)
void sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Binary Search Iterative
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;

    while(left <= right) {
        int mid = (left + right) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input array
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort array first
    sort(arr, n);

    // Print sorted array (matches your example output)
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    // OPTIONAL: Binary search usage
    /*
    int key;
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);

    if(result != -1)
        printf("\nElement found at index %d", result);
    else
        printf("\nElement not found");
    */

    return 0;
}
