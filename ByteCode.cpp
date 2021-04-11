#include "ByteCode.h"
#include <iostream>

void VM::dumpReg()
{
	for (auto& reg : registers)
	{
		std::cout << "Register " << reg.first << " Finished with value :" << reg.second.getData() << std::endl;
	}
}

void VM::initISA()
{
	ISA[Op__Codes::mov] = Instruction::mov;
	ISA[Op__Codes::inc] = Instruction::inc;
	ISA[Op__Codes::add] = Instruction::add;
	ISA[Op__Codes::dec] = Instruction::dec;
	ISA[Op__Codes::sub] = Instruction::sub;
	ISA[Op__Codes::mul] = Instruction::mul;
	ISA[Op__Codes::div] = Instruction::div;
	ISA[Op__Codes::log_and] = Instruction::log_and;
	ISA[Op__Codes::log_xor] = Instruction::log_xor;
	ISA[Op__Codes::log_or] = Instruction::log_or;
}

void VM::initReg()
{
	

	registers["R00"] = R00;
	registers["R01"] = R01;
	registers["R02"] = R02;
	registers["R03"] = R03;
	registers["R04"] = R04;
	registers["R05"] = R05;
	registers["R06"] = R06;
	registers["R07"] = R07;
	registers["R08"] = R08;
	registers["R09"] = R09;
	registers["R10"] = R10;
	registers["R11"] = R11;
	registers["R12"] = R12;
	registers["R13"] = R13;
	registers["R14"] = R14;
	registers["R15"] = R15;
	
}

VM::VM()
{
	initISA();
	initReg();

}

void VM::Interpreter(ParseNode* Tree)
{
	for (auto& operations : Tree->children)
	{
		
		
		
		auto fun = ISA[operationMappings[operations->getLex()]];
		auto reg1 = operations->children[0]->getLex();
		
		if (operations->children.size() > 1)
		{
			
			
			auto reg2 = operations->children[1]->getLex();
			if(reg2[0] != 'R')
				std::get<0>(fun)(registers[reg1], std::atoi(reg2.c_str()));
			else
				std::get<0>(fun)(registers[reg1], registers[reg2]);
		}
		else
		{
			//execute with single address;
			std::get<1>(fun)(registers[reg1]);
		}
	}
	
	dumpReg();
}
