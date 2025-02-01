#ifndef _6502_H
#define _6502_H

#include <stdint.h>

#define PREFIX_UNDEFINED 0
#define PREFIX_ADC 1
#define PREFIX_AND 2
#define PREFIX_ASL 3

#define PREFIX_BCC 4
#define PREFIX_BCS 5
#define PREFIX_BEQ 6
#define PREFIX_BIT 7
#define PREFIX_BMI 8
#define PREFIX_BNE 9
#define PREFIX_BPL 10
#define PREFIX_BRK 11
#define PREFIX_BVC 12
#define PREFIX_BVS 13

#define PREFIX_CLC 14
#define PREFIX_CLD 15
#define PREFIX_CLI 16
#define PREFIX_CLV 17
#define PREFIX_CMP 18
#define PREFIX_CPX 19
#define PREFIX_CPY 20

#define PREFIX_DEC 21
#define PREFIX_DEX 22
#define PREFIX_DEY 23

#define PREFIX_EOR 24

#define PREFIX_INC 25
#define PREFIX_INX 26
#define PREFIX_INY 27

#define PREFIX_JMP 28
#define PREFIX_JSR 29

#define PREFIX_LDA 30
#define PREFIX_LDX 31
#define PREFIX_LDY 32
#define PREFIX_LSR 33

#define PREFIX_NOP 34
#define PREFIX_ORA 35

#define PREFIX_PHA 36
#define PREFIX_PHP 37
#define PREFIX_PLA 38
#define PREFIX_PLP 39

#define PREFIX_ROL 40
#define PREFIX_ROR 41
#define PREFIX_RTI 42
#define PREFIX_RTS 43

#define PREFIX_SBC 44
#define PREFIX_SEC 45
#define PREFIX_SED 46
#define PREFIX_SEI 47
#define PREFIX_STA 48
#define PREFIX_STX 49
#define PREFIX_STY 50

#define PREFIX_TAX 51
#define PREFIX_TAY 52
#define PREFIX_TSX 53
#define PREFIX_TXA 54
#define PREFIX_TXS 55
#define PREFIX_TYA 56

typedef enum AddressingMode
{
    ADDRESSING_UNDEFINED = 0, // ???
    ADDRESSING_IMMEDIATE = 1, // Operand value is given in instruction. Ex: LDA #$0A => $A9 $0A
    ADDRESSING_ABSOLUTE = 2, // 2-byte address operand: LDA $31F6 => $AD $31F6
    ADDRESSING_ABSOLUTE_ZEROPAGE = 3, // aka Zero Page. 1-byte address operand (high byte assumed 00): LDA $F4 => $A5 $F4
    ADDRESSING_IMPLIED = 4, // no operands - implied by instruction
    ADDRESSING_ACCUMULATOR = 5, // no operands - operates on accumulator
    ADDRESSING_INDEXED = 6, // 2-byte address added to X or Y register "index" address. Ex: LDA $31F6, Y
    ADDRESSING_INDEXED_ZEROPAGE = 7, // 1-byte address added to X or Y register "index" address. Ex: LDA $20, X
    ADDRESSING_INDIRECT = 8, // Indirect means it takes the address of an address. This version only applies to JMP. Ex: JMP ($215F)
    ADDRESSING_INDIRECT_PREINDEXED = 9, // takes a 1-byte address, adds to contents of X, creating a 1-byte (zero-page, wrapping if needed!) relative address. Ex: LDA ($3E, X)
    ADDRESSING_INDIRECT_POSTINDEXED = 10, // takes CONTENTS of a 1-byte address, adds to contents of Y, then same as above! Ex: LDA ($4C), Y
    ADDRESSING_RELATIVE = 11, // used for branching, takes a 1-byte value and treats it as signed to allow 127-byte program counter movement in either direction. Ex: BEQ $A7
    // indexed mode enums for specific indices
    ADDRESSING_INDEXED_X = 61, // e.g. Absolute,X
    ADDRESSING_INDEXED_Y = 62, // e.g. Absolute,Y
    ADDRESSING_INDEXED_ZEROPAGE_X = 71, // aka Zero Page,X
    ADDRESSING_INDEXED_ZEROPAGE_Y = 72, // aka Zero Page,Y
} AddressingMode_t;

typedef const struct Registers
{
    uint8_t A; // Accumulator
    uint8_t X; // X Index
    uint8_t Y; // Y Index
    uint8_t P; // Processor Status
    uint8_t PC; // Program Counter
    uint8_t S; // Stack Pointer
} Registers_t;

typedef const struct Operation
{
    uint8_t prefix_index;
    AddressingMode_t addressing_mode;
    uint8_t size_bytes;
    uint8_t time_cycles;
} Operation_t;

extern const char prefixes[57][4];
extern const uint8_t addressing_operand_counts[12];
extern const char addressing_formats[12][16];
extern const Operation_t opcodes[256];

#endif
