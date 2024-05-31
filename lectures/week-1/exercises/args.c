#include <stdio.h>

int main(int argc, char argv[])
{
    printf("argc: %d\n", argc);
    printf("argv: %s\n", argv);
    printf("argv: %s\n", argv[0]);
    printf("argv: %s\n", argv[1]);
    printf("argv: %s\n", argv[2]);
    return 0;
}