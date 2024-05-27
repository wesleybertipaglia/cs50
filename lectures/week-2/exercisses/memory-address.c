#include <stdio.h>

int main()
{
    int a, b, c; // integer variables
    int *p;      // pointer variable

    p = &a; // p is pointing to the address of a

    // printing the address of a, b, and c
    printf("Address of a: %p\n", &a); // %p is used to print the address of a variable
    printf("Address of b: %p\n", &b);
    printf("Address of c: %p\n", &c);

    return 0;
}