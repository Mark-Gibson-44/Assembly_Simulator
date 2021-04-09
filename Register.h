#pragma once
#include <memory>
#include <variant>

class Register {


	
	long long data;
	
public:
	Register() : data(0) {}

	
	void setData(long long d) {
		this->data = d;
	}
	constexpr void clearData() noexcept
	{
		this->data = this->data ^ this->data;
	}
	constexpr long long getData()
	{
		return this->data;
	}
	constexpr void setTrue() noexcept
	{
		this->data = this->data | 1;
	}
	

};