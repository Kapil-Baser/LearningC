#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LEN 1024

void read_line(char buffer[], int *size);
char *get_name(char buffer[], int size);

int main(void)
{
    char buf[LEN];
    int size = 0;
    printf("Enter your first name: ");
    read_line(buf, &size);
    char *first_name = get_name(buf, size);
    printf("Enter your last name: ");
    read_line(buf, &size);
    char *last_name = get_name(buf, size);
    
    printf("Hello %s %s!\n", first_name, last_name);

    free(first_name);
    free(last_name);
    return 0;
}

void read_line(char buffer[], int *size)
{
    if (!fgets(buffer, LEN, stdin))
    {
        fprintf(stderr, "Unable to read input\n");
        exit(1);
    }
    *size = strlen(buffer);
}

char *get_name(char buffer[], int size)
{
    char *name = malloc(sizeof(*name) * size);
    if (name == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    strncpy(name, buffer, size);
    name[size - 1] = '\0';
    return name;
}
