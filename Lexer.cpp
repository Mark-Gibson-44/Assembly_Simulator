#include "Lexer.h"

#include <regex>
#include <fstream>
#include <iostream>
#include <map>

const std::map<std::string, Tokens> regexes = {
	{"^R[0-2][0-9]$", Tokens::Reg},
	{"^[0-9]*$", Tokens::Imm},
	{"^[a-z]{3}$", Tokens::Op},
	{"^NOTHING$", Tokens::Addr}

};

void Lexer::log_lexing()
{
	for (auto& l : lexemes)
	{
		std::cout << (int)l.first << std::endl;
	}
}

std::vector<std::pair<Tokens, std::string>>& Lexer::out()
{
	return lexemes;
}

Lexer::Lexer(const char* File)
{
	std::fstream f;
	f.open(File);

	

	while (f.get(current))
	{
		if (current == ' ' || current == '\n')//No statement within the language contains whitespace therefor it means the end of a word
		{
			
			this->eval();
		}
		else
			current_word += current;

	}
	this->eval();
	lexemes.push_back(std::make_pair(Tokens::Eof, "EOF"));

}

void Lexer::eval()
{
	
	for (auto& regex : regexes)
	{
		std::regex a(regex.first);
		if (std::regex_match(current_word, a))
		{
			this->lexemes.push_back(std::make_pair(regex.second, this->current_word));
		}
	}
	this->current_word = "";


}
