#include <stdio.h>

int main(void)
{
    int n = 50;
    int *p = &n;       // p is a pointer that points to the address of n
    printf("%p\n", p); // %p is used to print the address of the variable
}