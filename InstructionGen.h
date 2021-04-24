#pragma once
#include "Parser.h"
#include "Instruction.h"


enum class Op__Codes {
	mov = 0x01,
	add = 0x02,
	sub = 0x03,
	mul = 0x03,
	div = 0x04,
	inc = 0x05,
	dec = 0x06,
	cmp = 0x07,
	jmp = 0x08,
	log_and = 0x09,
	log_or = 0x10,
	log_xor = 0x11,
	jne = 0x12,
	jlt = 0x13,
	jle = 0x14,
	jgt = 0x15,
	jge = 0x16,
	
};

//Map of strings to their corresponding enum values
static std::map<std::string, Op__Codes> operationMappings = {
		{"mov", Op__Codes::mov},
		{"inc", Op__Codes::inc},
		{"dec", Op__Codes::dec},
		{"add", Op__Codes::add},
		{"mul", Op__Codes::mul},
		{"div", Op__Codes::div},
		{"cmp", Op__Codes::cmp},
		{"jmp", Op__Codes::jmp},
		{"or", Op__Codes::log_or},
		{"and", Op__Codes::log_and},
		{"xor", Op__Codes::log_xor},
		{"jne", Op__Codes::jne},
		{"jge", Op__Codes::jge},
		{"jle", Op__Codes::jle},
		{"jlt", Op__Codes::jlt},
		{"jgt", Op__Codes::jgt}
};

class InstructionGen {
	ParseNode* Tree;
	ParseNode* Iterator;
	
	std::vector<int> out;
	
public:
	InstructionGen(ParseNode* tree) : Tree(tree), Iterator(tree) {};

	/*
	Traverses a generated parsetree in order to generate a compiled version of the 
	Instructions for later execution
	*/
	void Traverse(const char* out);
	


};