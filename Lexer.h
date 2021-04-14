#include <vector>
#include <string>


//Unique identifiers for each type of write
enum class Tokens {
	Reg = 0,
	Imm = 1,
	Op = 2,
	Addr = 3,
	Labl = 4,
	Eof = 100

};
 
class Lexer {
	//output
	std::vector<std::pair<Tokens, std::string>> lexemes;
	//current character for iteration
	char current;

	//current accumulation of characters
	std::string current_word;

	
	void consume();

	//Checks the current word against a map of regexes
	void eval();

public:

	void log_lexing(); //Printing

	std::vector<std::pair<Tokens, std::string>>& out();
	Lexer(const char* File);
};