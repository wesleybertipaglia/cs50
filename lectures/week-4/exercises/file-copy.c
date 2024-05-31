#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    if (src == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 1;
    }

    if (dst == NULL)
    {
        fclose(src);
        printf("Could not create %s.\n", argv[2]);
        return 2;
    }

    BYTE b;

    while (fread(&b, sizeof(b), 1, src) != 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);
}