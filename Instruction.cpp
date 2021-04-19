#include "Instruction.h"

bool Instruction::mov(Register& dest, std::variant<Register, int> src)
{
	
	if (src.index() == 0)
		dest.setData(std::get<0>(src).getData());
	else
		dest.setData(std::get<1>(src));
	
	return false;
}

bool Instruction::add(Register& dest, std::variant<Register, int> src)
{

	if (src.index() == 0)
		dest.setData(dest.getData() + std::get<0>(src).getData());
	else
		dest.setData(dest.getData() + std::get<1>(src));

	return false;
}

bool Instruction::mul(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() * std::get<0>(src).getData());
	else
		dest.setData(dest.getData() * std::get<1>(src));

	return false;
}


bool Instruction::sub(Register& dest, std::variant<Register, int> src)
{

	if (src.index() == 0)
		dest.setData(dest.getData() - std::get<0>(src).getData());
	else
		dest.setData(dest.getData() - std::get<1>(src));

	return false;
}

bool Instruction::div(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
	{
		if (std::get<0>(src).getData() == 0)
			return false;
		dest.setData(dest.getData() / std::get<0>(src).getData());
	}
	else
	{
		dest.setData(dest.getData() / std::get<1>(src));
	}

	return false;
}

bool Instruction::log_xor(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() ^ std::get<0>(src).getData());
	else
		dest.setData(dest.getData() ^ std::get<1>(src));
	return false;
}

bool Instruction::log_or(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() | std::get<0>(src).getData());
	else
		dest.setData(dest.getData() | std::get<1>(src));

	return false;
}

bool Instruction::log_and(Register& dest, std::variant<Register, int> src)
{
	if (src.index() == 0)
		dest.setData(dest.getData() & std::get<0>(src).getData());
	else
		dest.setData(dest.getData() & std::get<1>(src));

	return false;
}

bool Instruction::inc(Register& dest)
{
	dest.setData(dest.getData() + 1);

	return false;
}

bool Instruction::dec(Register& dest)
{
	dest.setData(dest.getData() - 1);

	return false;
}
