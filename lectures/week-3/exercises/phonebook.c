#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[20];
    char number[20];
} Person;

int main(void)
{
    Person people[4];
    char target[20];

    strcpy(people[0].name, "Alice");
    strcpy(people[0].number, "+1-123-456-7890");

    strcpy(people[1].name, "Bob");
    strcpy(people[1].number, "+1-987-654-3210");

    strcpy(people[2].name, "Charlie");
    strcpy(people[2].number, "+1-555-123-4567");

    strcpy(people[3].name, "David");
    strcpy(people[3].number, "+1-154-391-4275");

    printf("Name: ");
    scanf("%19s", target);

    for (int i = 0; i < 4; i++)
    {
        if (strcmp(people[i].name, target) == 0)
        {
            printf("Found:\n name: %s\n phone: %s\n", people[i].name, people[i].number);
            return 0;
        }
    }

    printf("Not found\n");
    return -1;
}