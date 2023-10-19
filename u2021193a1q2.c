#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1000

int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        printf("Insufficient arguments");
        exit(-1);
    }

    FILE *line1;
    FILE *line2;
    FILE *line3;
    line1 = fopen(argv[1], "r");
    line2 = fopen(argv[2], "r");
    line3 = fopen(argv[3], "r");
    if (line1 == NULL || line2 == NULL || line3 == NULL)
    {
        printf("Error: failed to open input file: %s", argv[1]);
        exit(-2);
    }

    char line[MAX_LENGTH];
    while (fgets(line, MAX_LENGTH, line1) != NULL) {
        printf("%s\n", line);
    }

    while (fgets(line, MAX_LENGTH, line2) != NULL) {
        printf("%s\n", line);
    }

    while (fgets(line, MAX_LENGTH, line3) != NULL) {
        printf("%s\n", line);
    }

    
    fclose(line1);
    fclose(line2);
    fclose(line3);

}