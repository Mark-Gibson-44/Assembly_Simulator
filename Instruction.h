#pragma once

#include <variant>
#include <optional>
#include <map>

#include "Register.h"


namespace Instruction {

	bool mov(Register& dest, std::variant<Register, int> src);
	bool add(Register& dest, std::variant<Register, int> src);
	bool mul(Register& dest, std::variant<Register, int> src);
	bool sub(Register& dest, std::variant<Register, int> src);
	bool cmp(Register& dest, std::variant<Register, int> src);
	bool jne(Register& dest, std::variant<Register, int> src);
	bool jgt(Register& dest, std::variant<Register, int> src);
	bool jge(Register& dest, std::variant<Register, int> src);
	bool jlt(Register& dest, std::variant<Register, int> src);
	bool jle(Register& dest, std::variant<Register, int> src);
	bool div(Register& dest, std::variant<Register, int> src);
	bool log_xor(Register& dest, std::variant<Register, int> src);
	bool log_or(Register& dest, std::variant<Register, int> src);
	bool log_and(Register& dest, std::variant<Register, int> src);
	bool inc(Register& dest);
	bool dec(Register& dest);
	

	bool carry_set(int i);
	bool cmp_set(int j);

	
	


};