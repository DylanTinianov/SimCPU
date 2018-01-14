#ifndef SIMCPU_H
#define SIMCPU_H

#define NUM_REGISTERS 32
#define NUM_BITS 32
#define HEX_0 0x00000000

#include <exception>

enum InstructionType = {TYPE1, TYPE2};

union Instruction {
    unsigned int instr;

    struct type1 {          // JR or JALR
        
    } type1;

    struct type2 {

    } type2;
};


class Register {
    public:
        unsigned int get_value();
        unsigned int write_value();
    private:
        unsigned int value;
};


class SimALU {
    // SimALU takes in a cmd, and 1 or 2 operands and outputs the computed value
};



class SimCPU {
    public:
        SimCPU();
        virtual ~SimCPU();
        void initialize_registers();
        void fetch_instruction();
        void execute_instruction(); // Control Logic
        void set_register_value(int reg_num, unsigned int value);
        unsigned int get_register_value(int reg_num);
        void print_register_values();
        bool isNewData();

    private:
        unsigned int PC;                // Program Counter
        Instruction IR;                 // Instruction Register
        unsigned int MAR;               // Memory Address Register
        unsigned int MDR;               // Memory Data Register
        unsigned int registers[32];     // List of registers
        SimALU* ALU;                    // Arithmetic Logic Unit
};


class ExitException : public std::exception {
    virtual const char* what() const throw() {return "Exit Exception";}
} ExitException;

#endif 