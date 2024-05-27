#include <stdio.h>

// Linear search algorithm
// searches for a target in an array by checking each element
// O(n) time complexity

// Pseudocode:
// for each element in the array:
//     if the element is equal to the target:
//         return the index of the element
// return -1 if the target is not found

int linearSearch(int arr[], int target);

void main()
{
    int numbers[] = {17, 1, 5, 31, 78, 4, 8, 9, 15, 20};
    int target;

    printf("Enter a number to search for: ");
    scanf("%d", &target);

    int result = linearSearch(numbers, target);

    if (result != -1)
    {
        printf("%d was found at index %d\n", target, result);
    }
    else
    {
        printf("%d was not found\n", target);
    }
}

int linearSearch(int arr[], int target)
{
    for (int i = 0; i <= 10; i++)
    {
        printf("Checking index %d\n", i);
        if (arr[i] == target)
        {
            printf("Found %d at index %d\n", target, i);
            return i;
        }
    }
    return -1;
}