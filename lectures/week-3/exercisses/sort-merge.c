#include <stdio.h>

// Merge sort algorithm
// Sorts an array of integers in ascending order
// O(n log n) time complexity

// Pseudocode:
// sort the left half of the array (assuming n > 1)
// sort the right half of the array (assuming n > 1)
// merge the two sorted halves into a single sorted array

void mergeSort(int arr[], int l, int r);

int main(void)
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
    }
}
