#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // list of 3 elements
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    for (int i = 0; i < 3; i++)
    {
        list[i] = i + 1;
    }

    // we want to add a 4th element to the list
    // but we can't resize the array
    // so we need to create a new array with the new size

    // temporary array to copy the elements
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // copy the elements from the original array to the temporary array
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // free the original array
    free(list);

    // add the new element to the temporary array
    tmp[3] = 4;

    // point the original array to the temporary array
    list = tmp;

    // print the elements
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }
}