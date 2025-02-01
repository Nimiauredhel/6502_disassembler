
const char opcodes[256][16] =
{
    "BRK", "ORA (%s,X)", "", "", "", "ORA %s", "ASL %s", "", "PHP", "ORA #%s", "ASL A", "", "", "ORA %s", "ASL %s", "",
    "BPL", "ORA %s,Y", "", "", "", "ORA (%s),X", "ASL (%s),X", "", "CLC", "ORA %s,Y", "", "", "", "ORA %s,X", "ASL %s,X", "",  
    "JSR", "AND (%s,X)", "", "", "BIT %s", "AND %s", "ROL %s", "", "PLP", "AND #%s", "ROL A", "", "BIT %s", "AND %s", "ROL %s", "",
    "BMI", "AND (%s),Y", "", "", "", "AND %s,X", "ROL %s,X", "", "SEC", "AND %s,Y", "", "", "", "AND %s,X", "ROL %s,X", "",
    "RTI", "EOR (%s,X)", "", "", "", "EOR %s", "LSR %s", "", "PHA", "EOR #%s", "LSR A", "", "JMP %s", "EOR %s", "LSR %s", "",
    "BVC", "EOR (%s),Y", "", "", "", "EOR %s,X", "LSR %s,X", "", "CLI", "EOR %s,Y", "", "", "", "EOR %s,X", "LSR %s,X", "",
    "RTS", "ADC (%s,X)", "", "", "", "ADC %s", "ROR %s", "", "PLA", "ADC #%s", "ROR A", "", "JMP (%s)", "ADC %s", "ROR %s", "",
    "BVS", "ADC (%s),Y", "", "", "", "ADC %,X", "ROR %s,X", "", "SEI", "ADC %s,Y", "", "", "", "ADC %s,X", "ROR %s,X", "",
    "", "STA (%s,X)", "", "", "STY %s", "STA %s", "STX %s", "", "DEY", "", "TXA", "", "STY %s", "STA %s", "STX %s", "",
    "BCC", "STA (%s),Y", "", "", "STY %s,X", "STA %s,X", "STX %s,X", "", "TYA", "STA %s,Y", "TXS", "", "", "STA %s,X", "", "",
    "LDY #%s", "LDA (%s,X)", "LDX #%s", "", "LDY %s", "LDA %s", "LDX %s", "", "TAY", "LDA #%s", "TAX", "", "LDY %s", "LDA %s", "LDX %s", "",
    "BCS", "LDA (%s),Y", "", "", "LDY %s,X", "LDA %s,X", "LDX %s,Y", "", "CLD", "LDA %s,Y", "TSX", "", "LDY %s,X", "LDA %s,X", "LDX %s,Y", "",
    "Cpy #%s", "CMP (%s,X)", "", "", "CPY %s", "CMP %s", "DEC %s", "", "INY", "CMP #%s", "DEX", "", "CPY %s", "CMP %s", "DEC %s", "",
    "BNE", "CMP (%s,Y)", "", "", "", "CMP %s,X", "DEC %s, X", "", "CLD", "CMP %s,Y", "", "", "", "CMP %s,X", "DEC %s,X", "",
    "CPX #%s", "SBC (%s,X)", "", "", "CPX %s", "SBC %s", "INC %s", "", "INX", "SBC #%s", "NOP", "", "CPX %s", "SBC %s", "INC %s", "",
    "BEQ", "SBC (%s),Y", "", "", "", "SBC %s,X", "INC %s,X", "", "SED", "SBC %s,Y", "", "", "", "SBC %s,X", "INC %s,X", ""
};
