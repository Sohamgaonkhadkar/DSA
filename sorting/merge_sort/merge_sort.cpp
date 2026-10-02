#include <stdio.h>

// Function to merge two sorted halves
void merge(int arr[], int low, int mid, int high) {
    int temp[100];        // temporary array
    int i = low;          // pointer for left half
    int j = mid + 1;      // pointer for right half
    int k = low;          // pointer for temp array

    // Compare elements from both halves
    while (i <= mid && j <= high) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left half
    while (i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right half
    while (j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy sorted elements back to original array
    for (int x = low; x <= high; x++) {
        arr[x] = temp[x];
    }
}

// Merge sort function
void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);      // left half
        mergeSort(arr, mid + 1, high); // right half

        merge(arr, low, mid, high);    // merge both halves
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = 7;

    mergeSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}

