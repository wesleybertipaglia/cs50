#include <stdio.h>

// Bubble sort algorithm
// Sorts an array of integers in ascending order
// O(n^2) time complexity

// Pseudocode:
// set swap counter to a non-zero value
// repeat until the swap counter is 0:
//     reset swap counter to 0
//     compare each pair of adjacent elements in the array
//     if the elements are in the wrong order:
//         swap them

void bubbleSort(int arr[], int size);

int main(void)
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    bubbleSort(arr, size);

    printf("Sorted array: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void bubbleSort(int arr[], int size)
{
    int i, j, temp;

    for (i = 0; i < size - 1; i++)
    {
        int swappCount = 0;
        for (j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swappCount++;
            }
        }
        if (swappCount == 0)
        {
            break;
        }
    }
}