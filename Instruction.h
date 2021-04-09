#pragma once

#include <variant>
#include <optional>
#include <map>

#include "Register.h"


namespace Instruction {

	void mov(Register& dest, std::variant<Register, int> src);
	void add(Register& dest, std::variant<Register, int> src);
	void mul(Register& dest, std::variant<Register, int> src);
	void sub(Register& dest, std::variant<Register, int> src);
	void cmp(Register& dest, std::variant<Register, int> src);
	void div(Register& dest, std::variant<Register, int> src);
	void log_xor(Register& dest, std::variant<Register, int> src);
	void log_or(Register& dest, std::variant<Register, int> src);
	void log_and(Register& dest, std::variant<Register, int> src);
	void inc(Register& dest);
	void dec(Register& dest);
	

	bool carry_set(int i);
	bool cmp_set(int j);

	
	


};







/*
class Instruction {
	Register& dest;
	std::optional<std::variant<Register&, int>> src;
	virtual void set();
	

	
};

 
class FlagInstruction  : public Instruction{
	bool condition(std::function<bool(Register, Register)> cond);
	void set();

};
*/