#include <stdio.h>

// Binary search algorithm
// searches for a target in a sorted array by dividing the search interval in half
// O(log n) time complexity

// Pseudocode:
// set left to 0 and right to n-1
// while left <= right:
//     set mid to the average of left and right
//     if the target is equal to the element at mid:
//         return mid
//     if the target is less than the element at mid:
//         set right to mid - 1
//     if the target is greater than the element at mid:
//         set left to mid + 1
// return -1 if the target is not found

int binarySearch(int arr[], int size, int target);

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int target;
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Enter a number to search for: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result == -1)
    {
        printf("Element is not present in the array\n");
    }
    else
    {
        printf("Element is present at index %d\n", result);
    }

    return 0;
}

int binarySearch(int arr[], int size, int target)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}
