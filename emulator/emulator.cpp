#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

// In C, unsigned int can be wrapped around, while signed int will be undefined when overflow
uint32_t R[32], PC; // RISC-V register, RV32
// uint8_t M[64] = {0x13, 0x05, 0x00, 0x00, 0x93, 0x05, 0x10, 0x04, 0x73, 0x00, 0x10, 0x00,
// 0x13, 0x05, 0x10, 0x00, 0x93, 0x05, 0x00, 0x00, 0x73, 0x00, 0x10, 0x00,
// 0x6f, 0x00, 0x00, 0x00}; // 64 Byte memory, here assuming the program is loaded in the memory

// In an instruction cycle:
// 1. fetch an instruction from the addr PC points to,
// 2. decode the opcode and operand from that instruction,
// 3. execute according to opcode and operand, update the state machine,
// 4. update PC, point to the next addr, update the state machine.


// Suppose we have only two riscv instructions
// 31 ...... 20 19 15 14 12 11   7 6 ...... 0
//  imm[11:0]  | rs1 | 000 | rd  |  0010011 |   ADDI
// 000000000001|00000| 000 |00000|  1110011 |  EBREAK

bool halt = false;

void inst_cycle() {
    uint32_t inst = *(uint32_t *) &M[PC];
    // Check the instructions
    if (((inst & 0x7f) == 0x13) && ((inst >> 12 ) & 0x7) == 0) {
        // ADDI
        // imm + rs1 -> rd, rd = 0 do not assign
        if (((inst >> 7)& 0x1f) != 0) {
            R[ (inst >>7) & 0x1f ] = R[ (inst>>15)&0x1f] + (((inst >> 20) & 0x7ff) - ((inst & 0x80000000) ? 4096:0));
        }
    } else if (inst == 0x00100073) {
        // ebreak
        if (R[10] == 0) {
            putchar(R[11] & 0xff);
        }
        else if (R[10] == 1) {halt = true;}
    else {printf("Unsupported ebreak command\n");}
    } else {printf("Unsupported instruction\n");}
    PC += 4;
}

// Initial state, or reset state
// R[0] = 0, PC = 0, program is stored in M


// We can also read program from file
uint8_t M[1024];

// Mimic instruction cycle
int main() {
    PC =0; R[0]=0;
    FILE *fp = fopen(argv[1], "r");
    fread(M, 1, 1024, fp);
    fclose(fp);
    while (!halt) {
        inst_cycle();
    }
    return 0;
}