#pragma once


#include "InstructionGen.h"

#include <map>
#include <functional>
#include <variant>
#include<vector>


using ThreeAddress = bool(*)(Register& l, std::variant<Register, int>);
using TwoAddress = bool(*)(Register& l);



class VM {

	//Register Set
	Register R00;
	Register R01;
	Register R02;
	Register R03;
	Register R04;
	Register R05;
	Register R06;
	Register R07;
	Register R08;
	Register R09;
	Register R10;
	Register R11;
	Register R12;
	Register R13;
	Register R14;
	Register R15;
	std::map<std::string, Register> registers; //Map of register names to Register Objects

	std::map<Op__Codes, std::variant < ThreeAddress, TwoAddress>> ISA; //Map of opcodes to either a 3 address or two address func pointer
	std::vector<ParseNode*> labels;
	void dumpReg();//Prints all register values

	//Initializers
	void initISA();
	void initReg();
	
	//Flag functions TODO
	bool set_carry();
	bool set_cmp();
	bool set_interupt();
	ParseNode* jump(std::string lab);
public:
	VM();
	//Immediately after parsing generate instruction code and run it
	void Interpreter(ParseNode* Tree);

	//Having generated a compiled equivalent of the desired program run it
	void Interpreter(std::string compiled);
	


};