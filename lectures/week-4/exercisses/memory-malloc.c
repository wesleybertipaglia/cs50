#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int)); // allocate memory for three integers
    // if the pointer has not allocated memory and you try to access it,
    // it will cause a segmentation fault

    if (x == NULL)
    {
        return 1;
    }

    x[0] = 1;
    x[1] = 2;
    x[2] = 3;

    free(x); // free memory
}