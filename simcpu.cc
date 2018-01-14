// SimCPU is a simulated cpu which reads MIPS generated binary and manipulates virtual registers
// Needs to fetch instructions from binary, manipulate registers, manipulate a stack, and perform assembly instructions.

#include <iostream>
#include <string>
#include "simcpu.h"


#define PC_INCR 0x00000004


SimCPU::SimCPU() : ALU(new SimALU()), PC(HEX_0), MAR(HEX_0), MDR(HEX_0) {
    IR.instr = HEX_0;
    initialize_registers();
}

SimCPU::~SimCPU() {
    print_register_values();
    delete ALU;
}

void SimCPU::initialize_registers() {
    for (int i=0; i < NUM_REGISTERS; i++) {
        registers[i] = HEX_0;
    }
}

void SimCPU::set_register_value(int reg_num, unsigned int value) {
    if (0 <= reg_num && reg_num <= NUM_REGISTERS) {
        registers[reg_num] = value;
    }
    else {
        throw ExitException;
    }
}

unsigned int SimCPU::get_register_value(int reg_num) {
    return registers[reg_num];
}

void SimCPU::fetch_instruction() {
    // Sets the IR to the value of the next instruction
    PC += PC_INCR;
}

void SimCPU::execute_instruction() {
    // check opcode and use IR to pull out s, t, d, i, or whatever
}

bool SimCPU::isNewData() {
    // Returns true if there are more instructions
}


int main(int argc, char* argv[]) {
    // check_binary_file from cmd line
    SimCPU* CPU = new SimCPU();
    try {
        while(CPU->isNewData()) {
            CPU->fetch_instruction();
            CPU->execute_instruction();
        }
    }
    catch (std::exception& e) {
        // Handle errors
    }

    delete CPU;
}
