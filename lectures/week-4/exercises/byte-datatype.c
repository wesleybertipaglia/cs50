#include <stdio.h>

typedef __uint8_t byte;

int main(void)
{
    byte b = 0x41;                    // 0x41 is the hexadecimal representation of the ASCII character 'A'
    printf("Byte: %c\n", b);          // %c is used to print the character value of the variable
    printf("Byte: %d\n", b);          // %d is used to print the decimal value of the variable
    printf("Byte address: %p\n", &b); // %p is used to print the address of the variable
}