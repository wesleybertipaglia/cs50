#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int HEADER_SIZE = 44;

typedef uint8_t BYTE;
typedef int16_t TWO_BYTE;

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    BYTE header[HEADER_SIZE];
    fread(header, sizeof(header), 1, input);
    fwrite(header, sizeof(header), 1, output);

    TWO_BYTE sample;

    while (fread(&sample, sizeof(sample), 1, input) != 0)
    {
        sample *= factor;
        fwrite(&sample, sizeof(sample), 1, output);
    }

    fclose(input);
    fclose(output);
}
