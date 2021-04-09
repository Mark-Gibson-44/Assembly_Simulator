#include "Instruction.h"

void Instruction::mov(Register& dest, std::variant<Register, int> src)
{
	
	if (src.index() == 0)
		dest.setData(std::get<0>(src).getData());
	else
		dest.setData(std::get<1>(src));

}

void Instruction::add(Register& dest, std::variant<Register, int> src)
{

	if (src.index() == 0)
		dest.setData(dest.getData() + std::get<0>(src).getData());
	else
		dest.setData(dest.getData() + std::get<1>(src));

}

void Instruction::mul(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() * std::get<0>(src).getData());
	else
		dest.setData(dest.getData() * std::get<1>(src));
}


void Instruction::sub(Register& dest, std::variant<Register, int> src)
{

	if (src.index() == 0)
		dest.setData(dest.getData() - std::get<0>(src).getData());
	else
		dest.setData(dest.getData() - std::get<1>(src));

}

void Instruction::div(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
	{
		if (std::get<0>(src).getData() == 0)
			return;
		dest.setData(dest.getData() / std::get<0>(src).getData());
	}
	else
	{
		dest.setData(dest.getData() / std::get<1>(src));
	}
}

void Instruction::log_xor(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() ^ std::get<0>(src).getData());
	else
		dest.setData(dest.getData() ^ std::get<1>(src));
}

void Instruction::log_or(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() | std::get<0>(src).getData());
	else
		dest.setData(dest.getData() | std::get<1>(src));
}

void Instruction::log_and(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() & std::get<0>(src).getData());
	else
		dest.setData(dest.getData() & std::get<1>(src));
}

void Instruction::inc(Register& dest)
{
	dest.setData(dest.getData() + 1);
}

void Instruction::dec(Register& dest)
{
	dest.setData(dest.getData() - 1);
}
