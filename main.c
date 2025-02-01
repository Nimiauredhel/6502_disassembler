#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "6502.h"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("No file argument, terminating.\n");
        exit(EXIT_SUCCESS);
    }

    FILE *rom = fopen(argv[1], "r");
    //fseek(rom, 16, SEEK_SET);
    Operation_t *op;

    size_t bytes_read;
    uint8_t opcode;
    AddressingMode_t addressing_mode;
    uint8_t format_index;
    uint8_t operand_count;
    uint16_t user_operand;
    char buffer[32];

    do
    {
        bytes_read = fread(&opcode, 1, 1, rom);

        op = &opcodes[opcode];
        addressing_mode = op->addressing_mode;
        format_index = addressing_mode;
        if (format_index > 12) format_index /= 10;
        operand_count = addressing_operand_counts[format_index];

        if (op->size_bytes > 1)
        {
            bytes_read = fread(&user_operand, op->size_bytes - 1, 1, rom);
        }

        switch(operand_count)
        {
            case 0:
                sprintf(buffer, addressing_formats[format_index], prefixes[op->prefix_index]);
                break;
            case 1:
                sprintf(buffer, addressing_formats[format_index], prefixes[op->prefix_index], user_operand);
                break;
            case 2:
                sprintf(buffer, addressing_formats[format_index], prefixes[op->prefix_index], user_operand,
                        addressing_mode == ADDRESSING_INDEXED_ZEROPAGE_X || addressing_mode == ADDRESSING_INDEXED_X ? 'X' : 'Y');
                break;
        }

        printf("%s\n", buffer);
    }
    while (bytes_read > 0);


    return EXIT_SUCCESS;
}
