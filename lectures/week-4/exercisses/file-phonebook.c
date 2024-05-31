#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a"); // "a" for append

    if (file == NULL)
    {
        return 1;
    }

    char name[30];
    char number[20];

    printf("Name: ");
    scanf("%s", name);

    printf("Number: ");
    scanf("%s", number);

    fprintf(file, "%s, %s\n", name, number); // write to the file
    fclose(file);                            // close the file
}