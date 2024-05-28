#include <stdio.h>

// Selection sort algorithm
// Sorts an array of integers in ascending order
// O(n^2) time complexity

// Pseudocode:
// repeat until no unsorted elements remain:
//     search the unsorted part of the data to find the smallest value
//     swap the smallest found value with the first unsorted element

void selectionSort(int arr[], int size);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    selectionSort(arr, size);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void selectionSort(int arr[], int size)
{
    int minIndex, temp;

    for (int i = 0; i < size - 1; i++)
    {
        minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}