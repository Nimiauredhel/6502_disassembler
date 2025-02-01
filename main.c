#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "6502.h"

int main(int argc, char **argv)
{
    printf("%s\n", prefixes[0]);

    if (argc < 2)
    {
        printf("No file argument, terminating.\n");
        exit(EXIT_FAILURE);
    }

    FILE *rom = fopen(argv[1], "r");

    return EXIT_SUCCESS;
}
